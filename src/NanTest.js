// const addon = require("bindings")("hello");
import addon from "bindings";
const NanTest = addon("NanTest");

// NanTest(function (msg) {
//   console.log(msg); // 'hello world'
// });

const obj1 = NanTest("Hello");
const obj2 = NanTest("Nhat Vu!");
console.log(obj1.msg + " " + obj2.msg);

// console.log(NanTest.hello()); // 'world'
// console.log(NanTest.add(1, 2));

// const fn = NanTest();
// console.log(fn());
