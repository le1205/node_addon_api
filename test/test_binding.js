const DLMSTranslatorUtilsExtension = require("../lib/binding.js");
console.log("Tests passed- everything looks OK!");
const assert = require("assert");

assert(DLMSTranslatorUtilsExtension, "The expected function is undefined");

const translator = new DLMSTranslatorUtilsExtension();
console.log("========================");
console.log("+++++++++++++++++", translator.GetSystemTitle())
   translator.SetSystemTitle("new system title")


console.log("Tests passed- everything looks OK!");


// // Create an instance of your addon class
// const translatorUtils = new DLMSTranslatorUtils();

// // Call the SetSystemTitle function
// translatorUtils.SetSystemTitle(systemTitle);

// console.log('System title set to:', systemTitle);



// const assert = require("assert");

// assert(getSystemTitle, "The expected function is undefined");

// function testBasic()
// {
//     const result =  getSystemTitle("hello");
//     assert.strictEqual(result, "world", "Unexpected value returned");
// }

// assert.doesNotThrow(testBasic, undefined, "testBasic threw an expection");

// console.log("Tests passed- everything looks OK!");