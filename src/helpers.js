const helpers = require("../build/Release/helpers.node");
console.log("addon", helpers);
console.log("hello ", helpers.hello("Nhat Vu", 20));
console.log("add ", helpers.add(5, 10));

const prevInstance = new helpers.ClassExample(4.3);
console.log("Initial value : ", prevInstance.getValue());
console.log("After adding 3.3 : ", prevInstance.add(3.3));

const newFromExisting = new helpers.ClassExample(prevInstance);

console.log("Testing class initial value for derived instance");
console.log(newFromExisting.getValue());

// const testAddon = require("../build/Release/helpers.node");

// console.log(testAddon.hello("Nhat Vu", 20));

module.exports = helpers;
