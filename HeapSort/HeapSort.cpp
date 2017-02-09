#include <cstdlib>
#include <cstdio>
#include "MaxHeap.h"

void HeapSort_Min(int data[], int length) {
	MaxHeap h = MaxHeap(data, length, length);
	h.toArray(data, length);

	for (int i = length - 1; i > 0; i--) {
		//交换待排序的第一个数和最后一个数
		int temp = data[i];
		data[i] = data[0];
		data[0] = temp;

		//筛选调整
		HeapAdjust(data, 0, i);
	}
}

/*
int main() {
	int data[] = { 1, 3, 4, 5, 2, 6, 9, 7, 8, 0 ,12,11,13,10};
	
	HeapSort_Min(data, 14);

	for (int i = 0; i < 14; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}
*/