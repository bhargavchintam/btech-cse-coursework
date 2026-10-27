var now = new Date();

console.log(now);
console.log(now.getFullYear());
console.log(now.getMonth());
console.log(now.getDate());
console.log(now.getDay());
console.log(now.getHours());
console.log(now.getMinutes());
console.log(now.getSeconds());

var days = ["sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"];
console.log("today is " + days[now.getDay()]);

var bday = new Date(1999, 4, 20);
console.log(bday.toDateString());

var d1 = new Date(2018, 5, 1);
var d2 = new Date(2018, 5, 15);
var diff = (d2 - d1) / (1000 * 60 * 60 * 24);
console.log("difference is " + diff + " days");
