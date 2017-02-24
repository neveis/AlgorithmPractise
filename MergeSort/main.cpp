#include <cstdio>
#include <cstdlib>
#include "MergeSort.h"

int main() {
	int a[] = { 7, 3, 8, 2, 9, 5, 0, 4, 1, 6,-1,-2 };
	int b[] = { 7, 3, 8, 2, 9, 5, 0, 4, 1, 6 };

	MergeSort(a, 0, 11);
	MergeSort(b, 0, 9);

	for (int i = 0; i < 12; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", b[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}