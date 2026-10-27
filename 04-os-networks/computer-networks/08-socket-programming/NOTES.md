# Socket Programming

A socket is one end of a two-way link between two programs on a network. It is basically a
file descriptor you can read from and write to, except the bytes go over the network instead
of to disk. On Unix everything is a file, and a socket fits right into that. We use the BSD
socket API (`<sys/socket.h>`), which is what Linux and macOS both give you.

## Client-server model

One side (the server) starts first, grabs a well known port and waits. The other side (the
client) knows the server's address and port and reaches out to it. The server is passive, the
client is active. Once they are connected both can send and receive.

## The call sequence

TCP is connection oriented, so there is a handshake and a fixed order of calls.

    server                          client
    socket()                        socket()
    bind()
    listen()
    accept()  <---- blocks here     connect()  ----> handshake
    recv()/send()                   send()/recv()
    close()                         close()

- `socket()` makes the endpoint and returns an fd.
- `bind()` ties the socket to an address + port. Server only.
- `listen()` marks it passive and sets the backlog (queue of pending connections).
- `accept()` pulls one connection off the queue and returns a NEW fd for that client. The
  listening socket stays open for the next one.
- `connect()` on the client does the actual handshake to the server.
- `send`/`recv` (or `write`/`read`) move the bytes.
- `close()` tears it down.

UDP is connectionless so it skips listen/accept/connect. The server does socket, bind, then
`recvfrom` / `sendto`. `recvfrom` also hands back the sender's address so you know who to reply
to. No connection, no handshake, every datagram stands alone.

## TCP vs UDP

| | TCP | UDP |
|---|---|---|
| type | `SOCK_STREAM` | `SOCK_DGRAM` |
| connection | yes, 3-way handshake | none |
| reliable | yes, retransmits | no, best effort |
| ordering | in order | can arrive out of order |
| boundaries | byte stream, no message boundaries | keeps message boundaries |
| speed / overhead | more overhead | lighter, faster |
| used by | HTTP, FTP, SSH | DNS, DHCP, video, VoIP |

The byte-stream point catches people out. One `send` does not equal one `recv`. TCP can split
or merge your data, so for anything longer than a small message you loop until you have read
what you expect. That is why the file transfer here reads in a `while` loop.

## Byte order

Different CPUs store multibyte numbers differently (little vs big endian). The network standard
is big endian, "network byte order". So before you put a port or address into the socket
structs you convert:

- `htons` / `htonl` - host to network, short / long. Ports go through `htons`.
- `ntohs` / `ntohl` - network to host, the other way.

If you forget `htons(PORT)` the connection quietly goes to the wrong port and nothing works.
Got this wrong in the internal once and spent ten minutes staring at it.

## Ports

A port is a 16-bit number (0-65535) that says which program on the host the traffic is for. The
IP address finds the machine, the port finds the process. 0-1023 are the well known ports (need
root), so for these programs I picked ones in the 9100 range. Each program here uses its own
`#define PORT` so two of them can run at the same time without clashing.

Every server also sets `SO_REUSEADDR` with `setsockopt`. Without it, if you kill the server and
restart quickly you get "address already in use" because the old socket sits in TIME_WAIT.

## Concurrent servers

A plain server handles one client, then the next. If one client is slow everyone else waits.
Two ways to serve many clients at once:

- **fork()** - after `accept`, fork a child process to handle that client while the parent goes
  back to `accept`. Simple. Each client gets its own process. Downside is a process per client
  is heavy, and you must reap the children (`SIGCHLD` set to `SIG_IGN`, or `waitpid`) or you
  pile up zombies.
- **select()** - stay in one process. Keep all the fds in an `fd_set`, hand them to `select()`,
  and it tells you which ones are ready to read. You loop over the ready ones. No extra
  processes, but the code is fiddlier and you track the client list yourself.

fork is easier to read, select scales better and shares memory. `poll`/`epoll` (`kqueue` on
mac) are the newer versions of the same idea.

> Blocking accept is the normal case - the server just sits in accept() until someone connects.

## Files here

- 01/02 - TCP server + client, one message and a reply.
- 03/04 - UDP server + client, recvfrom / sendto.
- 05 - TCP echo server, bounces back whatever you send.
- 06 - concurrent server, fork a child per client.
- 07 - select based server, many clients on one thread.
- 08 - daytime server, sends the current date/time on connect.
- 09/10 - file sender + receiver, a file over TCP in chunks.
