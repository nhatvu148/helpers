export interface INodeTest {
  pass_number(arg: number): number;
  pass_integer(arg: number): number;
  add_2_numbers(arg1: number, arg2: number): number;
  pass_string(arg: string): string;
  pass_boolean(arg: boolean): boolean;
  pass_object(arg: { hello: string }): { hello: string };
}

const nodeTest: INodeTest = require("./build/Release/NodeTest.node");

export default nodeTest;
