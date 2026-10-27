// notes api - final node project
var express = require('express');
var bodyParser = require('body-parser');

var app = express();
app.use(bodyParser.json());

var notes = [
    { id: 1, text: 'learn express' },
    { id: 2, text: 'finish camp project' }
];
var nextId = 3;

app.get('/notes', function(req, res) {
    res.json(notes);
});

app.post('/notes', function(req, res) {
    var note = { id: nextId, text: req.body.text };
    nextId = nextId + 1;
    notes.push(note);
    res.json(note);
});

app.delete('/notes/:id', function(req, res) {
    var id = parseInt(req.params.id);
    notes = notes.filter(function(n) {
        return n.id !== id;
    });
    res.json({ message: 'deleted' });
});

app.listen(3000, function() {
    console.log("notes api running on port 3000");
});
