'use strict';
let message = 'Hello, World'
// var does not have block visibility
// variable created with 'var' can be declared again
// var is hoisted

// Hard-coded constant`s name is written in upper case.  
const WELCOME_MESSAGE = 'Hello, User';

function NewMessage(secondPart) {
    return WELCOME_MESSAGE + secondPart; 
}

let secondPart = 'Barsik';
// Soft-coded constant`s name is written in camelCase.
const barsikMessage = NewMessage(secondPart); 

// alert(message);
// let name1 = "Ілля";
// alert( `привіт ${1}` ); // ?
// alert( `привіт ${"name1"}` ); // ?
// alert( `привіт ${name1}` );

var new_var = 2;
console.log(new_var);

var human = Object();

human.name = "Vitalii";
alert(human.name);

let user = {};
user.name = "John";
user.surname = "Smith";
user.name = "Pete";
delete user.name;

function isEmpty(obj) {
    for (let key in obj)
        return false;
    return true;
}

let salaries = {
    John: 100,
    Ann: 160,
    Pete: 130
};

let sum = 0;
for (let salary in salaries) {
    sum += salaries[salary];
}

let menu = {
    width: 200,
    height: 300,
    title: "My menu"
};

multiplyNumeric(menu);

function multiplyNumeric(obj) {
    for (let key in obj) {
        let value = obj[key];
        if (typeof value === "number")
            value *= 2;
    }
}