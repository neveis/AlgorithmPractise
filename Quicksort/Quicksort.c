/**
* lang��C
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

	//���������ҵ������������ڵ�һ��λ��
	int middle = (start + end) / 2;
	if (data[middle] > data[end])
		swap(data, middle, end);
	if (data[start] > data[end])
		swap(data, start, end);
	if (data[middle] > data[start])
		swap(data, middle, start);
	
	//�ڿ�����
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

	//�ݹ����
	if (start == end) return;
	int index = partition(data, length, start, end);
	if (start < index) {
		Quicksort(data, length, start, index - 1);
	}
	if (index < end) {
		Quicksort(data, length, index + 1, end);
	}
}