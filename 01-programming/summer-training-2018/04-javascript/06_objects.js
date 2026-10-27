var student = {
    name: "bhargav",
    age: 19,
    college: "reva",
    marks: [85, 90, 78]
};

console.log(student.name);
console.log(student["age"]);
console.log(student.marks[1]);

student.city = "bangalore";
console.log(student);

for (var key in student) {
    console.log(key + " : " + student[key]);
}
