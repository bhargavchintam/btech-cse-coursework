// url and querystring parsing
var url = require('url');
var querystring = require('querystring');

var link = 'http://localhost:3000/search?city=bangalore&team=rcb';

var parsed = url.parse(link);
console.log("host: " + parsed.host);
console.log("pathname: " + parsed.pathname);
console.log("query string: " + parsed.query);

var q = querystring.parse(parsed.query);
console.log("city: " + q.city);
console.log("team: " + q.team);

var back = querystring.stringify({ name: 'bhargav', day: 13 });
console.log("built query: " + back);
