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
	int *temp = new int[last - first + 1];

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

	delete[] temp;
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


//优化，减少辅助数组的复制
void Merge(int data[], int temp[], int first, int mid,int last) {
	int i = first;
	int j = mid+1;

	for (int k = i; k <= last; k++) {
		if (i > mid) {
			//第一个子序列排完，第二个子序列按顺序排列
			temp[k] = data[j++];
		}
		else if (j > last) {
			//同上，第二个子序列先排完
			temp[k] = data[i++];
		}
		else if (data[j] < data[i]) {
			temp[k] = data[j++];
		}
		else {
			temp[k] = data[i++];
		}
	}

}

void MergeSort(int data[], int temp[], int first, int last) {
	//递归出口
	if (last <= first) {
		return;
	}

	int mid = (first + last) / 2;
	MergeSort(temp, data, first, mid);
	MergeSort(temp, data, mid + 1, last);

	Merge(data, temp, first,mid, last);
}

void MergeSort(int data[], int length) {
	if (data == nullptr || length <=0) {
		return;
	}
	int *temp = new int[length];
	//先复制一份到辅助数组中
	for (int i = 0; i < length; i++) {
		temp[i] = data[i];
	}
	
	MergeSort(temp, data, 0, length - 1);

	delete[] temp;
}