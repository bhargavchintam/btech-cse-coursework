# Distributed computing

A cloud isn't one big machine, it's a pile of ordinary machines pretending to be one. The pretending is
the hard part. The nodes talk over a network that drops and delays messages, clocks drift, and any box can
crash at any moment while the others carry on. Distributed computing is the set of tricks that keep this
mess looking like a single reliable system.

## Transparency

The goal is that a user shouldn't have to know there are twenty servers behind the service. The textbook
lists a bunch of transparencies but these are the ones that actually came up:

- access - you call it the same way whether the data is local or three racks over.
- location - you don't know (or care) which node holds your file. Consistent hashing (03) is exactly this.
- replication - there are copies for safety, but you see one logical value. Quorums (05) hide the copies.
- failure - a node dies and the service keeps answering. Election (04) and 2PC (06) are failure handling.
- concurrency - lots of users hit the same data at once and nobody sees a half-finished update.

## CAP theorem

The one thing everybody quotes. When the network partitions - some nodes can't reach the others - you get
to keep **two** of Consistency, Availability, Partition tolerance, not all three.

- C - every read sees the most recent write, or an error.
- A - every request gets a (non-error) answer, even if it might be stale.
- P - the system keeps working even when messages between nodes are lost.

Partitions are a fact of networks, you don't get to opt out of P. So the real choice is C vs A *during a
partition*: refuse to answer and stay consistent (CP), or answer with maybe-old data and stay up (AP).

| pick | during a partition | example                    |
|------|--------------------|----------------------------|
| CP   | reject writes/reads to stay correct | HBase, a quorum store tuned strict |
| AP   | answer anyway, reconcile later      | Dynamo, Cassandra, DNS      |

I wrote "pick any 2, freely" in the internal and got dinged - you don't freely pick, P is forced, the
choice is only C vs A and only while partitioned. Normal times you can have both.

## Consistency models

- strong - after a write finishes, every read returns that value. Simple to reason about, expensive,
  needs coordination on every op. This is what W+R>N buys you in 05.
- eventual - if writes stop, the replicas *eventually* converge. Reads can be stale in the meantime. Cheap
  and always available, which is why AP systems live here.
- causal - a middle ground: reads respect happened-before order (if I see your reply I also see your
  question) but concurrent writes can land in any order. Vector clocks (02) are how you track this.

## Logical time - why physical clocks aren't enough

Every machine has a clock but they drift, and NTP only syncs them to within milliseconds. Over a network,
a message can arrive "before" it was sent according to two unsynced wall clocks. So you can't use
timestamps to order events across machines - you'd get nonsense.

Lamport's fix (01): forget real time, just count. Each process keeps a counter, bumps it on every event,
and stamps outgoing messages. On receive you jump your counter past the sender's stamp. That guarantees
**if a happened-before b then clock(a) < clock(b)** - a send always reads lower than its receive. The catch:
the reverse isn't true, a smaller number doesn't prove causality.

Vector clocks (02) fix the catch. Each process keeps a whole vector, one slot per process. Now you can look
at two stamps and actually tell: causally ordered (one vector <= the other) or **concurrent** (neither
dominates). That's the extra information a single Lamport number throws away.

> Physical time tells you when. Logical time tells you what-caused-what. Distributed systems care about
> the second one.  -- lab notes

## Consensus

Getting a set of nodes to agree on one value, despite crashes and slow messages. Shows up everywhere:
electing a leader, committing a transaction, agreeing an order of operations.

- Leader election - the Bully algorithm (04). Highest live id wins. When the leader goes quiet, a node
  starts an election, anyone higher shouts it down and takes over, the top survivor announces itself.
- Atomic commit - two-phase commit (06). A coordinator asks everyone to PREPARE; only if *all* vote yes
  does it COMMIT, otherwise it ABORTs. One "no" kills the whole transaction. The weakness: if the
  coordinator dies mid-way the participants block, which is why Paxos/Raft exist (out of scope here).
- Quorums (05) are the lightweight cousin: don't ask everyone, just ask enough. W+R>N forces the read set
  and write set to overlap, so a read always catches the latest write.

## Failure models

What kind of broken are we defending against? Matters a lot for how hard the algorithm has to be.

- crash-stop - a node just halts and never comes back. Easiest. Bully and 2PC assume this.
- crash-recovery - it dies and later restarts, maybe with stale state. Needs logs to catch up.
- omission - messages get dropped or lost but nobody lies.
- Byzantine - a node behaves arbitrarily, even maliciously, sends conflicting things to different peers.
  Hardest, needs 3f+1 nodes to tolerate f liars. This is the blockchain world, way past this lab.

## The files

- 01_lamport_clock.py     - Lamport counters over 3 processes, checks send < receive
- 02_vector_clock.py      - vector clocks, labels a pair as causally ordered or concurrent
- 03_consistent_hashing.py - hash ring with virtual nodes, ~1/N keys move on add
- 04_bully_election.py    - Bully election, highest id wins, prints the messages
- 05_quorum_consensus.py  - quorum read/write, W+R>N vs W+R<=N (fresh vs stale)
- 06_two_phase_commit.py  - 2PC commit path and an abort path

All standard library. The ring in 03 is the same sorted-structure + binary search from the DSA repo, and
the MapReduce-style partitioning idea shows up again in 04-mapreduce-hadoop.
