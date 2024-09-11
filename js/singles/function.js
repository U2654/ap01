// function taking two arguments
function secondBinomial(a, b) {
    const twiceAB = 2*a*b;      // variable in scope of function
    return a*a + twiceAB + b*b; // return value
}

// call the function 
const r = secondBinomial(4, 3);
console.log(r);