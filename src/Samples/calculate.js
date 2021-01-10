const { calc } = require("../build/Release/calculate.node");

const calcJS = () => {
  let i,
    x = 122.34,
    y = 203.54;

  for (i = 0; i < 1000000000; i++) {
    x += y;
  }
  const total = x;
  return total;
};

console.time("JS");
console.log(calcJS());
console.timeEnd("JS");
console.time("C++");
console.log(calc());
console.timeEnd("C++");
