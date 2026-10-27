// var can be redeclared but let and const cannot
var x = 10;
var x = 20;
console.log(x);

let y = 5;
y = 15;
console.log(y);

const pi = 3.14;
console.log(pi);

var a = 1;
if (true) {
  var a = 2;
  let b = 3;
  console.log(b);
}
console.log(a);
