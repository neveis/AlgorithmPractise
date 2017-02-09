/**
 * lang：JavaScript
 * 快速排序算法
 * 分为3步:
 * 1.从数列中取出一个数作为基准数。
 * 2.将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边。分为左右区间。
 * 3.再对左右区间重复第二步，直到各区间只有一个数。
 * 
 * 对基准数选取进行优化：
 * 选取第一个数，中间数，最后一个数中的中数作为基准，可以有效降低升序数组和降序数组的时间。
 * 参考：http://www.codeceo.com/article/3-sort-quick-sort-improve.html
 */
'use strict'

/**
 * 对数列进行分区
 * list:输入数列
 * length：数列长度
 * start：起始下标
 * end:结束下标
 * 
 * 返回：基准数的下标
 */
function partition(list, length, start, end) {
    //检测输入合法性
    if (!(list instanceof Array) || length <= 0 || start < 0 || end >= length) {
        throw 'invaild input'
    }

    //三个数中找到中数，并放于第一个位置
    var middle = ((start + end) / 2) | 0;
    if (list[middle] > list[end]) {
        swap(list, middle, end);
    }
    if (list[start] > list[end]) {
        swap(list, start, end);
    }
    if (list[middle] > list[start]) {
        swap(list, start, middle);
    }

    /*
    //以第一个数为基准数。
    //从后往前遍历，将小于基准的数往前移动
    var pivot = end;
    for (var index = end; index > start; index--) {
        if (list[index] > list[start]) {
            if (index != pivot) {
                swap(list, index, pivot);
            }
            pivot--;
        }
    }
    swap(list, start, pivot);
    return pivot;
    */

    //挖坑填数
    //以第一个数为基准数。
    var first = start;
    var last = end;
    var key = list[start];
    while (first < last) {
        while (first < last && list[last] >= key) {
            last--;
        }
        list[first] = list[last];
        while (first < last && key >= list[first]) {
            first++;
        }
        list[last] = list[first];
    }
    list[first] = key;
    return first;
}

function swap(list, index1, index2) {
    var temp = list[index1];
    list[index1] = list[index2];
    list[index2] = temp;
}

function Quicksort(data, length, start, end) {
    if (!(data instanceof Array) || length <= 0 || start < 0 || end >= length) {
        if (length === 0) {
            return;
        } else {
            throw 'invaild input'
        }
    }

    if (start === end) return;

    var index = partition(data, length, start, end);
    if (start < index) {
        Quicksort(data, length, start, index - 1)
    }
    if (index < end) {
        Quicksort(data, length, index + 1, end)
    }
}


module.exports = Quicksort;