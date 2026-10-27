// async read with callback
var fs = require('fs');

fs.writeFileSync('camp_notes.txt', 'async read demo\n');

fs.readFile('camp_notes.txt', 'utf8', function(err, data) {
    if (err) {
        console.log("error reading file");
        return;
    }
    console.log(data);
});

console.log("this prints first"); // callback runs later
