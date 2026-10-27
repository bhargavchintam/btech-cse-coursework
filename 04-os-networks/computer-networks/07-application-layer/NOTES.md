# Application Layer

The top of the stack. This is where the actual programs live - browsers, mail clients, name
resolvers - and the protocols they speak to each other. Everything below (transport, network, link)
is plumbing that this layer uses. An application layer protocol is really just an agreement on the
format of the messages two programs exchange and the order they send them in.

## Client-server vs peer-to-peer

- **Client-server** - one always-on machine (the server) with a fixed address serves many clients.
  Clients talk to the server, not to each other. HTTP, SMTP, DNS, FTP all work this way. Simple, but
  the server is a bottleneck and a single point of failure.
- **P2P** - peers talk directly to each other, each acting as both client and server. No central
  server (or only a small one to find peers). Scales with the number of peers because they bring
  their own upload capacity. BitTorrent is the classic example.

## HTTP

HyperText Transfer Protocol, runs over TCP (port 80, or 443 for HTTPS). Request/response and
stateless - the server does not remember you between requests, which is why cookies exist.

A request is a **request line + headers + blank line + optional body**:

    GET /index.html HTTP/1.1
    Host: example.com
    User-Agent: ...
    <blank line>

**Methods**: GET (fetch), POST (send data), PUT, DELETE, HEAD (headers only).

**Status codes** come back on the response's status line:

| class | meaning | examples |
|---|---|---|
| 1xx | informational | 100 Continue |
| 2xx | success | 200 OK, 201 Created |
| 3xx | redirect | 301 Moved, 304 Not Modified |
| 4xx | client error | 400 Bad Request, 404 Not Found |
| 5xx | server error | 500 Internal Error, 503 Unavailable |

`01_http_request_builder.cpp` builds a GET and a POST by hand and parses a response's status line and
headers. `06_cookie_parser.py` handles the Set-Cookie / Cookie headers that give HTTP its memory.

## DNS

Domain Name System. Turns names people can remember (www.example.com) into IP addresses machines
route on. Runs over UDP port 53 (falls back to TCP for big answers). It is a distributed hierarchy,
resolved right to left:

    root  ->  .com (TLD)  ->  example.com (authoritative)

Your resolver walks down that tree (or reads it from cache) to get the answer. A query is a 12-byte
header (ID, flags, and the four counts QD/AN/NS/AR) followed by the question: the name encoded as
length-prefixed labels, a type and a class. `03_dns_message.cpp` builds and re-parses one.

**Record types**: A (name -> IPv4), AAAA (name -> IPv6), MX (mail server for a domain),
CNAME (an alias to another name), NS (which name server is authoritative), PTR (reverse, IP -> name).

## FTP

File Transfer Protocol, port 21. Odd one out - it uses **two** TCP connections: a control connection
(port 21) for commands like USER, PASS, RETR, STOR, and a separate data connection for the actual
file bytes. So the control channel stays open the whole session while data connections come and go.
Runs in active or passive mode depending on which side opens the data connection.

## SMTP

Simple Mail Transfer Protocol, port 25. Pushes mail from client to server and between mail servers.
Text based command/reply: HELO/EHLO, MAIL FROM, RCPT TO, DATA, then the message, then QUIT. SMTP is
push only - it delivers mail. Pulling it down to read is a different protocol (POP3 port 110 or
IMAP port 143). Attachments that are not plain text get base64 encoded (MIME) to survive the trip,
which is what `05_base64.py` is about.

## DHCP

Dynamic Host Configuration Protocol, UDP ports 67 (server) and 68 (client). When a machine joins a
network with no IP, DHCP leases it one. The exchange is **DORA**:

| step | message | who | what |
|---|---|---|---|
| D | Discover | client -> broadcast | anyone got an address for me? |
| O | Offer | server -> client | here is one you can have |
| R | Request | client -> broadcast | I'll take that one |
| A | Ack | server -> client | it's yours, here's the lease |

The Ack also carries the subnet mask, gateway and DNS server, and a **lease** time. The client renews
around halfway through the lease (T1) rather than waiting for it to run out. `04_dhcp_simulation.cpp`
walks the whole DORA exchange.

## Files here

- 01 http request builder + response parser (C++)
- 02 url parser (Python)
- 03 dns query build + parse (C++)
- 04 dhcp DORA simulation (C++)
- 05 base64 encode/decode (Python)
- 06 cookie parser (Python)
