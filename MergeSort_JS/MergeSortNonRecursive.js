/**
 * lang：JavaScript
 * 归并排序算法,非递归实现
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

    for (k = 0, i = first; i <= last; k++ , i++) {
        data[i] = temp[k];
    }
}

function MergeSortNonRecursive(data, first, end) {
    var length = end - first + 1;

    //划分子序列
    for (var gap = 1; gap < length; gap = 2 * gap) {
        for (var i = 0; i + 2 * gap - 1 < length; i = i + 2 * gap) {
            //合并序列对
            MergeArray(data, i, i + gap - 1, i + 2 * gap - 1);
        }
        //剩余不足一对的情况
        if (i + gap < length) {
            MergeArray(data, i, i + gap - 1, length - 1);
        }
    }
}

module.exports = MergeSortNonRecursive;