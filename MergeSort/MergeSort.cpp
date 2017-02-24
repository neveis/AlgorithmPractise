/**
* lang：C/C++
* 归并排序算法
* 1.对序列进行折半划分
* 2.假设左右序列分别有序，对左右序列合并排序
*
*/
#include <cstdlib>

void MergeArray(int data[], int first, int mid, int last) {
	int i = first;
	int j = mid + 1;
	int k = 0;
	int *temp = (int*)calloc(last - first + 1, sizeof(data[0]));

	while (i <= mid && j <= last) {
		if (data[i] <= data[j]) {
			temp[k++] = data[i++];
		}
		else {
			temp[k++] = data[j++];
		}
	}

	while (i <= mid) {
		temp[k++] = data[i++];
	}

	while (j <= last) {
		temp[k++] = data[j++];
	}

	for (k = 0, i = first; i <= last; i++, k++) {
		data[i] = temp[k];
	}

	free(temp);
}

void MergeSort(int data[], int first, int last) {
	if (data == nullptr) {
		return;
	}
	if (first < last) {
		int mid = (last + first) / 2;
		MergeSort(data, first, mid);
		MergeSort(data, mid + 1, last);
		MergeArray(data, first, mid, last);
	}
}

void MergeSortNonRecursive(int data[], int first, int last) {
	if (data == nullptr) {
		return;
	}
	int length = last - first + 1;
	for (int gap = 1; gap < length; gap = gap * 2) {
		int i = 0;
		for (; i + 2 * gap < length; i = i + 2 * gap) {
			MergeArray(data, i, i + gap - 1, i + 2 * gap - 1);
		}
		if (i + gap < length) {
			MergeArray(data, i, i + gap - 1, length - 1);
		}
	}
}