//#region Task1

function compareNumbers(a, b) {
  if (a < b) {
    return -1;
  } else if (a > b) {
    return 1;
  } else {
    return 0;
  }
}

console.log(compareNumbers(5, 10));
console.log(compareNumbers(10, 5));
console.log(compareNumbers(5, 5));

// #endregion Task1

//#region Task2

function factorialNumber(a) {
  let b = 1;
  for (let index = 1; index <= a; index++) {
    b = b * index;
  }
  return b;
}

console.log(factorialNumber(5));

//#endregion Task2

//#region Task3

function composingNumber(a, b, c) {
  let i = a + b + c;

  return i;
}

console.log(composingNumber("1", "4", "9"));

//#endregion Task3

//#region Task4

function rectangeSqare(a, b) {
  let sqr;
  if (b === undefined) {
    sqr = a * a;
  } else {
    sqr = a * b;
  }

  return sqr;
}

console.log(rectangeSqare(5, 8));
console.log(rectangeSqare(5));

//#endregion  Task4

//#region Task5

function isPerfectNumber(a) {
  if (a <= 0) {
    return false;
  }
  let sum = 0;
  for (let index = 1; index < a; index++) {
    if (a % index == 0) {
      sum += index;
    }
  }

  return sum == a;
}

console.log(isPerfectNumber(6));
console.log(isPerfectNumber(12));
console.log(isPerfectNumber(28));

//#endregion Task5

//#region Task6

function perfectNumbers(min, max) {
  let perfect = [];
  for (let index = min; index < max; index++) {
    if (isPerfectNumber(index)) {
      perfect.push(index);
    }
  }

  return perfect;
}

console.log(perfectNumbers(3, 30));

//#endregion Task6

//#region Task7

function showTime(hours, minutes, seconds) {
  if (minutes === undefined) {
    minutes = 0;
  }
  if (seconds === undefined) {
    seconds = 0;
  }

  hours = String(hours);
  minutes = String(minutes);
  seconds = String(seconds);

  if (hours.length === 1) {
    hours = "0" + hours;
  }
  if (minutes.length === 1) {
    minutes = "0" + minutes;
  }
  if (seconds.length === 1) {
    seconds = "0" + seconds;
  }

  return hours + ":" + minutes + ":" + seconds;
}

console.log(showTime(12, 3, 23));
console.log(showTime(12, 3));
console.log(showTime(12));

//#endregion Task7

//#region Task8

function timeToSeconds(hours, minutes, seconds) {
  return hours * 3600 + minutes * 60 + seconds;
}

console.log(timeToSeconds(1, 2, 3));

// #endregion Task8

//#region Task9

function secondsToTime(number) {
  if (number > 0) {
    const hours = Math.floor(number / 3600);
    number -= hours * 3600;
    const minutes = Math.floor(number / 60);
    number -= minutes * 60;
    const seconds = number;

    if (hours < 10) {
      var finalHours = String("0" + hours);
    } else {
      var finalHours = String(hours);
    }
    if (minutes < 10) {
      var finalMinutes = String("0" + minutes);
    } else {
      var finalMinutes = String(minutes);
    }
    if (seconds < 10) {
      var finalSeconds = String("0" + seconds);
    } else {
      var finalSeconds = String(seconds);
    }
  }
  return finalHours + ":" + finalMinutes + ":" + finalSeconds;
}

console.log(secondsToTime(4000));

//#endregion Task9

//#region Task10

function datesDifference(
  firstHours,
  firstMinutes,
  firstSecond,
  secondHours,
  secondMinutes,
  secondSeconds
) {
  var timeToSecondsFirstResult = timeToSeconds(
    firstHours,
    firstMinutes,
    firstSecond
  );
  var timeToSecondsSecondResult = timeToSeconds(
    secondHours,
    secondMinutes,
    secondSeconds
  );

  var secondsDifference = Math.abs(
    timeToSecondsFirstResult - timeToSecondsSecondResult
  );

  return secondsToTime(secondsDifference);
}

console.log(datesDifference(10, 2, 12, 12, 3, 11));

//#endregion Task10
