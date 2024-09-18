// Object Geometry is also the namespace
let Geometry = {};

Geometry.areaOfCircle = function(radius) {
    return radius * radius * Math.PI;
}

Geometry.circumferenceOfCircle = function(radius) {
    return 2 * radius * Math.PI;
}

// this is exported to be used elsewhere
module.exports={Geometry};
