/**
* lang：C
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
#include <stdlib.h>

void swap(int data[], int index1, int index2) {
	int temp;
	temp = data[index1];
	data[index1] = data[index2];
	data[index2] = temp;
}

int partition(int data[], int length, int start, int end) {
	//check input
	if (data == NULL || length <= 0 || start < 0 || end >= length) {
		return -1;
	}

	//三个数中找到中数，并放于第一个位置
	int middle = (start + end) / 2;
	if (data[middle] > data[end])
		swap(data, middle, end);
	if (data[start] > data[end])
		swap(data, start, end);
	if (data[middle] > data[start])
		swap(data, middle, start);
	
	//挖坑填数
	int first = start;
	int last = end;
	int key = data[first];

	while (first < last) {
		while (first < last && data[last] >= key)
			last--;
		data[first] = data[last];
		while (first < last && data[first] <= key)
			first++;
		data[last] = data[first];
	}
	data[first] = key;
	return first;
}

void Quicksort(int data[], int length, int start, int end) {
	//check input
	if (data == NULL || length <= 0 || start < 0 || end >= length) {
		return;
	}

	//递归出口
	if (start == end) return;
	int index = partition(data, length, start, end);
	if (start < index) {
		Quicksort(data, length, start, index - 1);
	}
	if (index < end) {
		Quicksort(data, length, index + 1, end);
	}
}