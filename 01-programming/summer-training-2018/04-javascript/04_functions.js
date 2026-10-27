// three ways to write functions
function add(a, b) {
    return a + b;
}

var sub = function(a, b) {
    return a - b;
};

const mul = (a, b) => a * b;

console.log(add(4, 2));
console.log(sub(4, 2));
console.log(mul(4, 2));
