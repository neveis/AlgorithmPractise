/**
 * lang：JavaScript
 * 归并排序算法
 * 1.对序列进行折半划分
 * 2.假设左右序列分别有序，对左右序列合并排序
 *
 */
'use strict'
function MergeArray(data, first, mid, last) {
    var i = first;
    var j = mid + 1;
    var k = 0;
    var temp = [];
    //排序合并
    while (i <= mid && j <= last) {
        if (data[i] <= data[j]) {
            temp[k++] = data[i++];
        } else {
            temp[k++] = data[j++];
        }
    }

    //剩余部分直接复制到合并序列
    while (i <= mid) {
        temp[k++] = data[i++];
    }
    while (j <= last) {
        temp[k++] = data[j++];
    }

    for (k = 0,i=first; i <=last; k++,i++) {
        data[i] = temp[k];
    }
}


function MergeSort(data, first, last) {
    if (!(data instanceof Array)) {
        return;
    }

    if (first < last) {
        var mid = ((first + last) / 2) | 0;
        MergeSort(data, first, mid);
        MergeSort(data, mid + 1, last);
        MergeArray(data, first, mid, last);
    }
}

module.exports = MergeSort;