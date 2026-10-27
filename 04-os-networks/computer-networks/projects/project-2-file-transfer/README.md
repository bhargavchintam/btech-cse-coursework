# File transfer over TCP

Send a file from a client to a server over a plain TCP connection on port 9302. The
point of the project is that TCP is a byte stream with no message boundaries, so you
have to frame the file yourself - a small header up front, then the raw bytes, and the
receiver reads exactly as many bytes as the header promised.

## Protocol

One connection, one file. The client sends a single header line first:

    <size> <filename>\n

- `size`     - number of bytes in the file, decimal
- a space
- `filename` - the base name (any directory part is dropped), the rest of the line
- terminated by a single `\n`

Then it sends the file bytes, exactly `size` of them, in 4 KB chunks. The server reads
the header up to the newline, parses out the size and name, then reads `size` bytes into
`recv_<filename>` (the `recv_` prefix keeps it from overwriting the original when you test
in the same folder). No acknowledgement, no trailer - when `size` bytes are in, it is done.

## Build

    g++ -std=c++14 -Wall ft_server.cpp -o ft_server
    g++ -std=c++14 -Wall ft_client.cpp -o ft_client

## Run

Server first (it waits for one connection):

    ./ft_server

Then the client with the file to send:

    ./ft_client somefile.txt

The server writes `recv_somefile.txt` in its own directory.

## Sample session

    $ ./ft_server
    ft server on port 9302, waiting for a file
    got 1024 of 1024 bytes -> recv_somefile.txt

    $ ./ft_client somefile.txt
    sent 1024 bytes (somefile.txt)

The received copy is byte-for-byte identical to what was sent - check it with

    diff somefile.txt recv_somefile.txt

and diff prints nothing. Works the same for binary files, not just text, since the bytes
are never touched on the way through.
