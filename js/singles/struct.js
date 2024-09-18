function Address() {    // actually, this is a function that
    this.name = "";     // returns an object (filled struct) 
    this.street = "";   // with the default values that also
    this.postcode = 0;  // define the type
    this.city = "";
}

var address = new Address(); // the keyword 'new' does the trick 
address.name = "S. Error";   // as it creates the struct address
address.street = "Bus 0";
address.postcode = 6502;
address.city = "Processor";
console.log(address.street);