// const addon = require("bindings")("hello");
import binds from "bindings";
const addon = binds("addon");

// addon(function (msg) {
//   console.log(msg); // 'hello world'
// });

// const obj1 = addon("Hello");
// const obj2 = addon("Nhat Vu!");
// console.log(obj1.msg + " " + obj2.msg);

// console.log(addon.hello()); // 'world'
// console.log(addon.add(1, 2));

// const fn = addon();
// console.log(fn());

// const obj = new addon.MyObject(10);
// console.log(obj.plusOne()); // 11
// console.log(obj.plusOne()); // 12
// console.log(obj.plusOne()); // 13
// console.log(obj.multiply().value()); // 13
// console.log(obj.multiply(10).value()); // 130
// const newobj = obj.multiply(-1);
// console.log(newobj.value()); // -13
// console.log(obj === newobj); // false

// const obj = addon(10);
// console.log(obj.plusOne()); // 11
// console.log(obj.plusOne()); // 12
// console.log(obj.plusOne()); // 13
// const obj2 = addon(20);
// console.log(obj2.plusOne()); // 21
// console.log(obj2.plusOne()); // 22
// console.log(obj2.plusOne()); // 23

// const obj1 = addon.createObject(10);
// const obj2 = addon.createObject(20);
// const result = addon.add(obj1, obj2);
// console.log(result); // 30

// const calcJS = () => {
//   let i,
//     x = 122.34,
//     y = 203.54;

//   for (i = 0; i < 1000000000; i++) {
//     x += y;
//   }
//   const total = x;
//   return total;
// };
// console.time("JS");
// console.log(calcJS());
// console.timeEnd("JS");
// console.time("C++");
// console.log(addon.calc());
// console.timeEnd("C++");

console.log(addon.pass_number(123));
console.log(addon.pass_integer(122));
console.log(addon.add_2_numbers(1, 1));
console.log(addon.pass_boolean(false));
console.log(addon.pass_string("Hello Nhat Vu!"));
console.log(addon.pass_object({ hello: "Rin" }));
