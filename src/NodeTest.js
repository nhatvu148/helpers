const nodeTest = require("../build/Release/NodeTest.node");

console.log(nodeTest.pass_number(123));
console.log(nodeTest.pass_integer(122));
console.log(nodeTest.add_2_numbers(1, 1));
console.log(nodeTest.pass_string("Hello Nhat Vu!"));
console.log(nodeTest.pass_boolean(true));
console.log(nodeTest.pass_object({hello: "Rin"}));
