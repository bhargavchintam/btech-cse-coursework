var student = {
  name: "bhargav",
  age: 19,
  college: "reva",
  marks: [85, 90, 78]
};

var text = JSON.stringify(student);
console.log(text);
console.log(typeof text);

var back = JSON.parse(text);
console.log(back.name);
console.log(back.marks[1]);
console.log(typeof back);

var pretty = JSON.stringify(student, null, 2);
console.log(pretty);

var str = '{"movie":"avengers","year":2018,"rating":8.4}';
var obj = JSON.parse(str);
console.log(obj.movie + " came in " + obj.year);
