

//#region Task1

let Car = {
    mark: "Volkswagen",
    model: "Tiguan",
    year: 2016,
    averageSpeed: 180,
    speedType: "km/h"
}

function displayCarInfo(){
    console.log(`Mark: ${Car.manufacturer}`);
    console.log(`Model: ${Car.model}`);
    console.log(`Year: ${Car.year}`);
    console.log(`Average speed: ${Car.averageSpeed} ${Car.speedType}`);
}

function calculateTime(distance, averageSpeed) {
    let hours = distance / averageSpeed;
    let restCount = Math.floor(hours / 4);
    let totalHours = hours + restCount;

    return totalHours;
}
displayCarInfo();
let distance = 360
let travelTime = calculateTime(distance, Car.averageSpeed);
console.log(`${travelTime + ` hour(s)`}`);




//#endregion Task1


//#region Task2


class Fraction {
    constructor(numerator, denominator) {
        this.numerator = numerator;
        this.denominator = denominator;
    }

    static add(fraction1, fraction2) {
        const numerator = fraction1.numerator * fraction2.denominator + fraction2.numerator * fraction1.denominator;
        const denominator = fraction1.denominator * fraction2.denominator;
        return Fraction.reduce(new Fraction(numerator, denominator));
    }

    static subtract(fraction1, fraction2) {
        const numerator = fraction1.numerator * fraction2.denominator - fraction2.numerator * fraction1.denominator;
        const denominator = fraction1.denominator * fraction2.denominator;
        return Fraction.reduce(new Fraction(numerator, denominator));
    }

    static multiply(fraction1, fraction2) {
        const numerator = fraction1.numerator * fraction2.numerator;
        const denominator = fraction1.denominator * fraction2.denominator;
        return Fraction.reduce(new Fraction(numerator, denominator));
    }

    static divide(fraction1, fraction2) {
        const numerator = fraction1.numerator * fraction2.denominator;
        const denominator = fraction1.denominator * fraction2.numerator;
        return Fraction.reduce(new Fraction(numerator, denominator));
    }

    static reduce(fraction) {
        const gcd = Fraction.greatestCommonDivisor(fraction.numerator, fraction.denominator);
        return new Fraction(fraction.numerator / gcd, fraction.denominator / gcd);
    }

    static greatestCommonDivisor(a, b) {
        if (!b) {
            return a;
        }
        return Fraction.greatestCommonDivisor(b, a % b);
    }

    toString() {
        return `${this.numerator}/${this.denominator}`;
    }
}


const fraction1 = new Fraction(1, 2);
const fraction2 = new Fraction(1, 4);

const sum = Fraction.add(fraction1, fraction2);
console.log(`Sum: ${sum.toString()}`);

const difference = Fraction.subtract(fraction1, fraction2);
console.log(`Difference: ${difference.toString()}`); 

const product = Fraction.multiply(fraction1, fraction2);
console.log(`Product: ${product.toString()}`); 

const quotient = Fraction.divide(fraction1, fraction2);
console.log(`Quotient: ${quotient.toString()}`); 




//#endregion Task1


//#region Task3

let time = {
    hours: 0,
    minutes: 0,
    seconds: 0,
}

function displayTime() {
    console.log(`${formatTime(time.hours)}:${time.minutes}:${time.seconds}`)
}

function formatTime(value) {
    return value < 10 ? `0${value}` : value
}

function addSeconds(seconds) {
    time.seconds += seconds;
    normalizeTime();
}

function addMinutes(minutes) {
    time.minutes += minutes;
    normalizeTime();
}

function addHours(hours) {
    time.hours += hours;
    normalizeTime();
}

function normalizeTime() {
    let extraMinutes = Math.floor(time.seconds / 60);
    time.seconds %= 60;
    time.minutes += extraMinutes;

    let extraHours = Math.floor(time.minutes / 60);
    time.minutes += 60;
    time.hours += extraHours;

    time.hours %= 24;
}

time.hours = 20;
time.minutes = 30;
time.seconds = 45;

displayTime()

//#endregion Task1
