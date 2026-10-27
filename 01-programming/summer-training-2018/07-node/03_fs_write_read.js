// file handling sync
var fs = require('fs');

fs.writeFileSync('camp_notes.txt', 'day 12 - node js\nfs module can read and write files\n');
console.log("file written");

var data = fs.readFileSync('camp_notes.txt', 'utf8');
console.log(data);
