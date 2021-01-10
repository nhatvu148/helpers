// const addon = require("bindings")("hello");
import addon from "bindings";
const NanTest = addon("NanTest");

// NanTest(function (msg) {
//   console.log(msg); // 'hello world'
// });

// const obj1 = NanTest("Hello");
// const obj2 = NanTest("Nhat Vu!");
// console.log(obj1.msg + " " + obj2.msg);

// console.log(NanTest.hello()); // 'world'
// console.log(NanTest.add(1, 2));

// const fn = NanTest();
// console.log(fn());

// const obj = new NanTest.MyObject(10);
// console.log(obj.plusOne()); // 11
// console.log(obj.plusOne()); // 12
// console.log(obj.plusOne()); // 13
// console.log(obj.multiply().value()); // 13
// console.log(obj.multiply(10).value()); // 130
// const newobj = obj.multiply(-1);
// console.log(newobj.value()); // -13
// console.log(obj === newobj); // false

// const obj = NanTest(10);
// console.log(obj.plusOne()); // 11
// console.log(obj.plusOne()); // 12
// console.log(obj.plusOne()); // 13
// const obj2 = NanTest(20);
// console.log(obj2.plusOne()); // 21
// console.log(obj2.plusOne()); // 22
// console.log(obj2.plusOne()); // 23

const obj1 = NanTest.createObject(10);
const obj2 = NanTest.createObject(20);
const result = NanTest.add(obj1, obj2);
console.log(result); // 30
