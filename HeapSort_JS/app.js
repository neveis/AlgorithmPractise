const MaxHeap = require('./MaxHeap');

var h = MaxHeap([1, 8, 34, 4, 9, 6, 0,11,2, 3]);

console.log(h.data());
console.log(h.begin());
h.insert(5)
h.insert(7)
console.log(h.data());


console.log(h.sort());
console.log(h.size());
h.deleteMax();
h.deleteMax();
console.log(h.data());

var h2 = MaxHeap();
h2.insert(3);
h2.insert(1);
h2.insert(10);
h2.insert(5);
console.log(h2.data());
console.log(h.data());