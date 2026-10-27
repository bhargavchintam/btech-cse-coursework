// first web server
var http = require('http');

var server = http.createServer(function(req, res) {
  res.writeHead(200, { 'Content-Type': 'text/html' });
  res.write('<h1>Hello from my node server</h1>');
  res.write('<p>summer camp 2018</p>');
  res.end();
});

server.listen(3000, function() {
  console.log("server running on port 3000");
});
