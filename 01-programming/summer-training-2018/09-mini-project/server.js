// contact book backend - express, keeps contacts in memory

var express = require("express");
var bodyParser = require("body-parser");
var path = require("path");

var app = express();
app.use(bodyParser.json());
app.use(express.static(__dirname));

var contacts = [
  { id: 1, name: "Rahul", phone: "9876543210", email: "rahul@gmail.com" }
];
var nextId = 2;

app.get("/contacts", function(req, res) {
  res.json(contacts);
});

app.post("/contacts", function(req, res) {
  var c = { id: nextId, name: req.body.name, phone: req.body.phone, email: req.body.email };
  nextId++;
  contacts.push(c);
  res.json(c);
});

app.delete("/contacts/:id", function(req, res) {
  var id = parseInt(req.params.id);
  contacts = contacts.filter(function(c) { return c.id !== id; });
  res.json({ deleted: id });
});

app.listen(3000, function() {
  console.log("contact book running on http://localhost:3000");
});
