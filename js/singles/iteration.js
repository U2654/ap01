// init some variables
let y = 0;
let i = 0; 
let z = 0;

// run 10 times
for (i = 0; i < 10; i++) {
    y = y + 1; 
}
// y is now 10

// 10 times as y is 10
while (y > 0) {
    y = y - 1; // decrement by 1
    z = z + 2; // increment by 2
}

// z is now 20
console.log(z);