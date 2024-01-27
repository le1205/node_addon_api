const { DLMSTranslatorUtilsWrapper } = require('dlmsTranslator');

let dlmsTranslator = new DLMSTranslatorUtilsWrapper();
let systemTitle = dlmsTranslator.getSystemTitle();
console.log(systemTitle);

// const assert = require("assert");

// assert(getSystemTitle, "The expected function is undefined");

// function testBasic()
// {
//     const result =  getSystemTitle("hello");
//     assert.strictEqual(result, "world", "Unexpected value returned");
// }

// assert.doesNotThrow(testBasic, undefined, "testBasic threw an expection");

// console.log("Tests passed- everything looks OK!");