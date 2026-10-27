#!/usr/bin/env python3
import os
import json
from http.server import BaseHTTPRequestHandler, HTTPServer

port = int(os.environ.get("PORT", "8080"))


class Handler(BaseHTTPRequestHandler):
    def do_GET(self):
        if self.path == "/health":
            body = json.dumps({"status": "ok"}).encode()
        else:
            body = json.dumps({"msg": "hello from the container", "host": os.uname().nodename}).encode()
        self.send_response(200)
        self.send_header("Content-Type", "application/json")
        self.send_header("Content-Length", str(len(body)))
        self.end_headers()
        self.wfile.write(body)

    def log_message(self, *args):
        pass


if __name__ == "__main__":
    srv = HTTPServer(("0.0.0.0", port), Handler)
    print("listening on", port)
    srv.serve_forever()
