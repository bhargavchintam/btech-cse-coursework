var players = ["kohli", "dhoni", "rohit", "bumrah"];

players.push("dhawan");
console.log(players);

players.pop();
console.log(players);

players.splice(1, 1);
console.log(players);

console.log(players.indexOf("rohit"));

for (var i = 0; i < players.length; i++) {
  console.log(players[i]);
}

players.forEach(function(p) {
  console.log("player " + p);
});
