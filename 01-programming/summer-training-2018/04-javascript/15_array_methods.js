// map filter reduce forEach
var nums = [5, 12, 8, 130, 44, 3];

var doubled = nums.map(function(n) {
  return n * 2;
});
console.log(doubled);

var big = nums.filter(function(n) {
  return n > 10;
});
console.log(big);

var total = nums.reduce(function(sum, n) {
  return sum + n;
}, 0);
console.log("total is " + total);

nums.forEach(function(n) {
  console.log("value " + n);
});

var marks = [85, 90, 78, 92, 60];
var passed = marks.filter(function(m) {
  return m >= 75;
});
console.log("passed count " + passed.length);

var avg = marks.reduce(function(a, b) {
  return a + b;
}, 0) / marks.length;
console.log("average " + avg);
