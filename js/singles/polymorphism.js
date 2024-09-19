// base class
class Shape {
  constructor(w, h) {
    this.width = w;
    this.height = h;
  }
  // This should be overridden by derived classes
  area() {
    throw new Error('You have to implement the method area!');
  }
}

// derived classes
class Rectangle extends Shape {
  constructor(w, h) {
    super(w, h);
  }
  area() {
    return this.width * this.height;
  }
}

class Circle extends Shape {
  constructor(w, h) {
    super(w, h);
  }
  area() {
    return (this.height / 2) * (this.height / 2) * Math.PI;
  }
}

// usage
const rect = new Rectangle(10, 10);
const circle = new Circle(15, 15);
let shape = circle; 
console.log(shape.area()); // Output: 176.7145....
shape = rect;
console.log(shape.area()); // Output: 100
