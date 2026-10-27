// path module demo
var path = require('path');

var file = '/home/bhargav/camp/notes.txt';

console.log("dirname: " + path.dirname(file));
console.log("basename: " + path.basename(file));
console.log("extname: " + path.extname(file));

var full = path.join('camp', 'day13', 'work.txt');
console.log("join: " + full);

console.log("this file is: " + __filename);
console.log("in folder: " + __dirname);
