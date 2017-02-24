const MergeSort = require("./MergeSort");
const MergeSortNonRecursive = require("./MergeSortNonRecursive");

var a = [2, 8, 4, 6, 0, 1, 10,5,7];
var b = [2, -1,8, 4, 6, -5,0, 1, 10,9, 5, 7];
MergeSort(a, 0, a.length - 1);
MergeSortNonRecursive(b, 0, b.length - 1);
console.log(a);
console.log(b);