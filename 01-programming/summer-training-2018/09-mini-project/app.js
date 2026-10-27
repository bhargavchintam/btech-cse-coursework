// contact book frontend - talks to the express backend

var list = document.getElementById("list");
var form = document.getElementById("form1");

function load() {
  fetch("/contacts")
    .then(function(res) { return res.json(); })
    .then(function(data) {
      list.innerHTML = "";
      data.forEach(function(c) {
        var row = "<tr><td>" + c.name + "</td><td>" + c.phone + "</td><td>" + c.email +
                  "</td><td><span class='del' onclick='removeContact(" + c.id + ")'>x</span></td></tr>";
        list.innerHTML += row;
      });
    });
}

form.onsubmit = function(e) {
  e.preventDefault();
  var name = document.getElementById("name").value;
  var phone = document.getElementById("phone").value;
  var email = document.getElementById("email").value;
  if (name === "") {
    alert("enter a name");
    return;
  }
  fetch("/contacts", {
    method: "POST",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify({ name: name, phone: phone, email: email })
  }).then(function() {
    form.reset();
    load();
  });
};

function removeContact(id) {
  fetch("/contacts/" + id, { method: "DELETE" })
    .then(function() { load(); });
}

load();
