# Multi-client chat

A little TCP chat room. One server holds all the connections in a single `select()`
loop (no threads, no fork) and whenever a client sends a line it broadcasts that line
to every other client, tagged with the sender's name. Port 9301.

The first line a client sends is taken as its name. After that every line is a message.
When someone joins or leaves the others get a `* name joined` / `* name left` notice.

## Build

    g++ -std=c++14 -Wall chat_server.cpp -o chat_server
    g++ -std=c++14 -Wall chat_client.cpp -o chat_client

## Run

Start the server in one terminal:

    ./chat_server

Then open two (or more) other terminals and run a client in each:

    ./chat_client

Each client first gets a `name:` prompt - type a name and hit enter, then just type
messages. A raw `nc 127.0.0.1 9301` works as a client too, since it is only lines of text.

## Sample session

Terminal A (server):

    chat server on port 9301
    * alice joined
    * bob joined
    alice: hi bob
    bob: hey

Terminal B (alice) types `alice`, then `hi bob`, and sees:

    name: * bob joined
    bob: hey

Terminal C (bob) types `bob`, then `hey`, and sees:

    name: alice: hi bob

So a line from alice reaches bob and the other way round - the sender never gets an echo
of their own line, only the others do.
