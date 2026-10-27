var msg = "Summer Camp 2018";

console.log(msg.length);
console.log(msg.toUpperCase());
console.log(msg.toLowerCase());
console.log(msg.charAt(0));
console.log(msg.indexOf("Camp"));
console.log(msg.slice(0, 6));
console.log(msg.substring(7, 11));
console.log(msg.replace("2018", "2019"));

var name = "   bhargav   ";
console.log(name.trim());

var csv = "kohli,dhoni,rohit,bumrah";
var players = csv.split(",");
console.log(players);
console.log(players.length);

console.log(msg.includes("Camp"));
console.log(msg.split(" ").join("-"));
