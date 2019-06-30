"use strict";

function GCD(num1, num2)
{
    /*
        Recursive function calculates GCD of two numbers
        num1: larger number
        num2: smaller number
    */

    // check if num2 is 0, recursively, num2 will be the remainder
    if(num2 === 0)
    {   
        // return num1, which at this step is the previous remainder
        return num1;
    }

    // recursively calculate GCD unless remainder is 0
    return GCD(num2, num1%num2);
}


// call the functions
// returns 6
console.log(GCD(270,192));