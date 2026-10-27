# Load balancing

A single server can only take so many requests before it slows down or falls over. So you run several
copies behind a load balancer (LB): the LB sits in front, takes every incoming request and hands it to
one of the backend servers. The point is to spread the load so no one server becomes a hotspot while
the others sit idle. It also buys you availability - if a server dies, the LB stops sending to it and
the rest keep serving.

Two things a good LB is trying to do at once:
- spread requests evenly (or by capacity) so utilisation is roughly balanced
- avoid sending anything to a server that is down or overloaded

## L4 vs L7

Where in the stack the LB makes its decision matters.

- L4 (transport) - it works at TCP/UDP level. Sees IPs and ports, not the actual HTTP request. Fast,
  cheap, just forwards packets/connections. Can't route on URL or cookie because it never reads them.
- L7 (application) - it terminates the connection and reads the HTTP request. Now it can route on path
  (`/api` to one pool, `/images` to another), on headers, on cookies. More work per request but much
  smarter. This is what nginx / HAProxy in HTTP mode / an ALB do.

Rule of thumb: L4 when you just need to fan out raw connections, L7 when routing depends on what's
inside the request.

## The algorithms

| algorithm            | picks the server by...                                   |
|----------------------|----------------------------------------------------------|
| round robin          | next in the list, cycling - even split                   |
| weighted round robin | same, but a bigger-capacity server gets proportionally more |
| least connections    | fewest active connections right now                      |
| least response time  | fastest recent response (conns + latency)                |
| IP hash / source hash| hash of client IP, so a client always lands on one server |
| throttled            | first VM the index table marks available, else queue     |

- **Round robin** - server 0, 1, 2, 0, 1, 2... Dead simple, no state beyond a counter. Assumes every
  server is equal and every request costs the same, which is often not true. `01_round_robin.py`.
- **Weighted round robin** - give each server a weight. Weights [5,1,1] means the first server takes 5
  out of every 7 requests. Good when boxes have different sizes. I used the smooth version so the
  picks come out interleaved (a a b a c a a) instead of one big block. `02_weighted_round_robin.py`.
- **Least connections** - track how many connections each server currently holds and send the next one
  to the smallest. Adapts to reality: a slow request that hangs around keeps that server's count high
  so it gets skipped. `03_least_connections.py`.
- **Least response time** - least connections but also weight in the server's recent latency, so a box
  that answers quicker gets favoured. Didn't write a separate file, it's least-connections + a latency
  term in the key.
- **IP hash / source hashing** - `server = hash(client_ip) % n`. The same client always maps to the
  same server (cheap sticky sessions with no cookie). Downside: if `n` changes, almost everyone
  remaps - same rehash pain as the hash table in DSA, which is why consistent hashing exists
  (see 07-cloud-simulation for that idea). `04_ip_hash.py`.
- **Throttled** - the cloud-lab classic. The LB keeps an index table of VMs, each AVAILABLE or BUSY.
  A request gets the first AVAILABLE VM (marked BUSY); if none are free the request is queued and
  assigned when a VM is released. So a VM never runs more than one job at a time. `05_throttled.py`.

## Health checks

The LB can't route around a dead server if it doesn't know it's dead. So it probes each backend on an
interval - a TCP connect, or an HTTP GET to `/health` expecting 200. A server that fails a few checks
in a row is marked DOWN and pulled from the pool; when it starts passing again it's added back. Routing
only ever considers the healthy set. `06_health_check.py` shows a server going down mid-run and the
requests skipping it after that.

> An LB with no health check is worse than no LB - it will confidently keep shovelling traffic into a
> box that's already on fire.  -- lab notes

## Sticky sessions

Sometimes a client has to keep hitting the same server - e.g. the session (login, cart) lives in that
server's memory. That's a sticky session, done two ways:
- source/IP hash - same client IP -> same server, no cookie needed (04).
- cookie - the L7 LB sets a cookie naming the server and reads it back on the next request.

Stickiness fights load balancing: pin a client and you can't freely rebalance it, and if that server
dies the session is gone. The clean fix is to not keep session state on the server at all - push it to
a shared store (Redis / the key-value store in 09) so any server can handle any request. Then you
don't need stickiness. Got a question on exactly this in the internal and lost a mark for saying
"just use IP hash" without mentioning the shared-store option.
