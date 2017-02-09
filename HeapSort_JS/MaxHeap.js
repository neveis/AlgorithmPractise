/*
* lang:JavaScript
* 最大堆
*/
'use strict';

(function () {
    var MaxHeap = function (list) {
        var m_data = [];
        var init = function () {
            for (var i = ((m_data.length / 2) | 0) - 1; i >= 0; i--) {
                heapAdjust(m_data, i,m_data.length);
            }
        }

        var heapAdjust = function (array, parentIndex,length) {
            var key = array[parentIndex];
            var childIndex = 2 * parentIndex + 1;
            while (childIndex < length) {
                if (childIndex + 1 < length && array[childIndex + 1] > array[childIndex]) {
                    childIndex++;
                }

                if (key >= array[childIndex]) {
                    break;
                }
                array[parentIndex] = array[childIndex];
                parentIndex = childIndex;
                childIndex = 2 * parentIndex + 1;
            }
            array[parentIndex] = key;
        }

        if (list instanceof Array) {
            m_data = list.slice();
            init();
        }

        var heap = {};

        heap.size = function () {
            return m_data.length;
        }

        heap.begin = function () {
            if (m_data.length) {
                return m_data[0];
            } else {
                return null;
            }
        }

        heap.insert = function (value) {
            m_data.push(value);
            var index = m_data.length - 1;
            while (index > 0 && value > m_data[((index - 1) / 2) | 0]) {
                m_data[index] = m_data[((index - 1) / 2) | 0];
                index = ((index - 1) / 2) | 0;
            }
            m_data[index] = value;
        }

        heap.deleteMax = function () {
            var temp = m_data[0];
            m_data[0] = m_data[m_data.length - 1];
            m_data.pop();
            heapAdjust(m_data, 0,m_data.length);
            return temp;
        }

        heap.data = function () {
            return m_data.slice();
        }

        heap.sort = function () {
            var array = m_data.slice();
            for (var i = array.length - 1; i > 0; i--) {
                var temp = array[0];
                array[0] = array[i];
                array[i] = temp;
                heapAdjust(array, 0, i);
            }
            return array;
        }

        return heap;
    };

    module.exports = MaxHeap;
} ())