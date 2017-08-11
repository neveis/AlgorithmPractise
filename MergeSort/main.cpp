#include <cstdio>
#include <cstdlib>
#include "MergeSort.h"
int main() {
	int a[] = { 7, 3, 8, 2, 9, 5, 0, 4, 1, 6,-1,-2 };
	int b[] = { 7, 3, 8,  9, 5, 0, 4, 1, 6 };
	int c[] = { 4,3,2,1 };
	//MergeSort(a, 0, 11);
	//MergeSort(b, 0, 9);

	MergeSort(c, 4);

	MergeSort(a, 12);
	MergeSort(b, 9);

	for (int i = 0; i < 12; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	for (int i = 0; i < 9; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}