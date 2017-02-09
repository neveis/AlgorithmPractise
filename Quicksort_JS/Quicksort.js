/**
 * lang��JavaScript
 * ���������㷨
 * ��Ϊ3��:
 * 1.��������ȡ��һ������Ϊ��׼����
 * 2.��������������ȫ�ŵ������ұߣ�С�ڻ����������ȫ�ŵ�������ߡ���Ϊ�������䡣
 * 3.�ٶ����������ظ��ڶ�����ֱ��������ֻ��һ������
 * 
 * �Ի�׼��ѡȡ�����Ż���
 * ѡȡ��һ�������м��������һ�����е�������Ϊ��׼��������Ч������������ͽ��������ʱ�䡣
 * �ο���http://www.codeceo.com/article/3-sort-quick-sort-improve.html
 */
'use strict'

/**
 * �����н��з���
 * list:��������
 * length�����г���
 * start����ʼ�±�
 * end:�����±�
 * 
 * ���أ���׼�����±�
 */
function partition(list, length, start, end) {
    //�������Ϸ���
    if (!(list instanceof Array) || length <= 0 || start < 0 || end >= length) {
        throw 'invaild input'
    }

    //���������ҵ������������ڵ�һ��λ��
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
    //�Ե�һ����Ϊ��׼����
    //�Ӻ���ǰ��������С�ڻ�׼������ǰ�ƶ�
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

    //�ڿ�����
    //�Ե�һ����Ϊ��׼����
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