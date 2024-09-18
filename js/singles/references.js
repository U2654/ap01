let array_1 = [1, 2, 3];    // create array_1
array_2 = array_1;          // array_2 is reference, not copy
array_3 = [...array_1];     // array_3 is a copy (using spread ...)
array_2.push(4);            // array_1 and array_2 reference the same 
array_1.push(5);            // both arrays are changed
console.log(array_1);       // output: [ 1, 2, 3, 4, 5 ]
console.log(array_2);       // output: [ 1, 2, 3, 4, 5 ]
console.log(array_3);       // output: [ 1, 2, 3 ]
