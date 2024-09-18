let numbers = [];           // array of any type, empty
numbers.push(3);            // add element, pos 0
numbers.push(4);            // add element, pos 1
numbers[1] = 2;             // overwrite element at pos 1
numbers[8] = 5;             // add element at pos 9
console.log(numbers[1]);    // ok, element 2
console.log(numbers[3]);    // undefined, empty
console.log(numbers[8]);    // ok, element 5

