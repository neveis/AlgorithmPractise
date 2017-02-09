const Quicksort = require('./Quicksort');

var a = [5, 1, 7, 4, 2, 11, 23, 999, 33434, 54, 21, 67, 43, 11, 23, 4, 452, 23, 44];
//var a = [0, 1];
//var a = []
Quicksort(a, a.length, 0, a.length - 1);
console.log(a);