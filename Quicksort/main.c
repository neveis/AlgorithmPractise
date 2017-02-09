#include <stdio.h>
#include "Quicksort.h"

void test() {
	int a[] = { 3,2,4,6,5,2,1,9 };

	Quicksort(a, 8, 0, 7);

	for (int i = 0; i < 8; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void test2() {
	int *a = NULL;
	Quicksort(a, 2, 0, 1);
	printf("\n");
}

void test3() {
	int a[] = { 1 };

	Quicksort(a, 1, 0, 0);
	for (int i = 0; i < 1; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main() {
	test();
	test2();
	test3();

	system("pause");
	return 0;
}

