// routing with req.url
var http = require('http');

var server = http.createServer(function(req, res) {
  if (req.url === '/') {
    res.writeHead(200, { 'Content-Type': 'text/html' });
    res.write('<h1>Home Page</h1>');
    res.end();
  } else if (req.url === '/about') {
    res.writeHead(200, { 'Content-Type': 'text/html' });
    res.write('<h1>About</h1><p>I am learning node js</p>');
    res.end();
  } else {
    res.writeHead(404, { 'Content-Type': 'text/html' });
    res.write('<h1>404 page not found</h1>');
    res.end();
  }
});

server.listen(3000, function() {
  console.log("server on 3000");
});
