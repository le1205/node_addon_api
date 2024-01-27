const addon = require('../build/Release/dlms_translator_utils_extension');
const DLMSTranslatorUtils = addon.DLMSTranslatorUtilsWrapper;


// Create an instance of your addon class
const translatorUtils = new DLMSTranslatorUtils();

// Call the SetSystemTitle function
translatorUtils.SetSystemTitle(systemTitle);

console.log('System title set to:', systemTitle);


// const assert = require("assert");

// assert(getSystemTitle, "The expected function is undefined");

// function testBasic()
// {
//     const result =  getSystemTitle("hello");
//     assert.strictEqual(result, "world", "Unexpected value returned");
// }

// assert.doesNotThrow(testBasic, undefined, "testBasic threw an expection");

// console.log("Tests passed- everything looks OK!");