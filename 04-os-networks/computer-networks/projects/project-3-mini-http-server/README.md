# Mini HTTP server

A minimal HTTP/1.0 web server in about a hundred lines. It listens on port 9303, reads
the request line, and serves files straight out of its own directory. GET only - anything
else gets a 501. If the file exists it returns 200 with the right Content-Length, if not
a 404. That is the whole thing.

## How it works

- read the request off the socket, look at the first line: `GET /index.html HTTP/1.1`
- if the method is not GET, reply 501
- `/` is rewritten to `/index.html`
- a path with `..` in it is refused (403) so nobody reads files above the directory
- open `.` + path. Found -> 200 with the file bytes and a Content-Length header.
  Not found -> 404.
- the response is HTTP/1.0 with `Connection: close`, so one request per connection

Content-Type is guessed from the extension (.html, .css, .js, .txt), everything else is
sent as application/octet-stream.

## Build

    g++ -std=c++14 -Wall http_server.cpp -o http_server

## Run

    ./http_server

Leave it running. `index.html` is already in the folder for it to serve.

## Test

With curl:

    curl -s http://127.0.0.1:9303/index.html      # prints the page
    curl -i http://127.0.0.1:9303/index.html       # -i shows the 200 OK and headers
    curl -i http://127.0.0.1:9303/nope.html        # 404 Not Found

Or just open http://127.0.0.1:9303/ in a browser and you get the page.

The server logs each request to its own terminal:

    http server on http://127.0.0.1:9303/
    GET /index.html -> 200 (543 bytes)
    GET /nope.html -> 404
