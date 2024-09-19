class Rectangle {
    // class variable
    static numberOfRectangles = 0;

    // Private fields
    #width;
    #height;

    // Constructor
    constructor(width, height) {
        this.#width = width;
        this.#height = height;
        Rectangle.numberOfRectangles++;
    }

    // Private method
    #iAmPrivate() {
        console.log("This is a private method");
    }

    // Public method to calculate area
    area() {
        return this.#width * this.#height;
    }

    // Public method to draw the rectangle
    draw() {
        this.#iAmPrivate();
        for (let i = 0; i < this.#height; i++) {
            console.log('*'.repeat(this.#width));
        }
    }

    // Public method to get string representation of the object
    toString() {
        return `Rectangle(width=${this.#width}, height=${this.#height})`;
    }
}

// Create an instance of the class with width and height
const rect1 = new Rectangle(10, 10);
console.log(Rectangle.numberOfRectangles);
const rect2 = new Rectangle(10, 20);
console.log(Rectangle.numberOfRectangles);

// Call methods
rect1.draw();
console.log(rect1.area());
console.log(rect1.toString());
