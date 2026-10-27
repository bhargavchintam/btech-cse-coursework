// os module demo
var os = require('os');

console.log("platform: " + os.platform());
console.log("cpu count: " + os.cpus().length);
console.log("home dir: " + os.homedir());
console.log("hostname: " + os.hostname());

var totalGb = os.totalmem() / (1024 * 1024 * 1024);
console.log("total memory gb: " + totalGb.toFixed(2));
console.log("uptime mins: " + Math.round(os.uptime() / 60));
