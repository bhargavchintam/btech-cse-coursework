// closure remembers the outer variable

function counter() {
  var count = 0;
  return function() {
    count++;
    return count;
  };
}

var c1 = counter();
console.log(c1());
console.log(c1());
console.log(c1());

var c2 = counter();
console.log(c2());

function makeAdder(x) {
  return function(y) {
    return x + y;
  };
}

var add5 = makeAdder(5);
var add10 = makeAdder(10);
console.log(add5(2));
console.log(add10(2));

function bank(balance) {
  return {
    deposit: function(amt) {
      balance += amt;
      return balance;
    },
    withdraw: function(amt) {
      balance -= amt;
      return balance;
    }
  };
}

var acc = bank(100);
console.log(acc.deposit(50));
console.log(acc.withdraw(30));
