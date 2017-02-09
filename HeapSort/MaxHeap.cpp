#include <cstdlib>
#include <cmath>
#include <cstdio>
#include "MaxHeap.h"


void HeapAdjust(int data[],int parentIndex,int length) {

	int key = data[parentIndex];
	int childIndex = 2 * parentIndex + 1;

	while (childIndex < length) {
		//������������������ұ�����������ѡ��������
		if (childIndex + 1 < length && data[childIndex] < data[childIndex + 1]) {
			childIndex++;
		}

		//������ڵ���ڵ����ӽڵ㣬����
		if (key >= data[childIndex]) {
			break;
		}

		//�ӽڵ㸳ֵ�����ڵ�
		data[parentIndex] = data[childIndex];

		//����ɸѡ
		parentIndex = childIndex;
		childIndex = 2 * parentIndex + 1;
	}

	data[parentIndex] = key;

}
/*
void MaxHeap(int data[], int length) {

	//��������Ϊ����
	for (int i = length / 2 - 1; i >= 0; i--) {
		HeapAdjust(data, i, length);
	}

}
*/
MaxHeap::MaxHeap() {
	m_length = 0;
	m_maxLength = 100;
	m_pData = new int[m_maxLength];
}

MaxHeap::~MaxHeap() {
	if (m_pData != nullptr) {
		delete[]m_pData;
	}
}
MaxHeap::MaxHeap(int maxLength) {
	m_length = 0;
	m_maxLength = maxLength;
	m_pData = new int[m_maxLength];
}

MaxHeap::MaxHeap(int input[], int length, int maxLength) {
	m_maxLength = maxLength;
	m_pData = new int[m_maxLength];
	if (length > m_maxLength) {
		printf("�������鳤�ȴ��ڶѵ�����С���������ݽ����ض�\n");
		length = m_maxLength;
	}
	m_length = length;
	for (int i = 0; i < m_length; i++) {
		m_pData[i] = input[i];
	}

	//��������Ϊ����
	for (int i = m_length / 2 - 1; i >= 0; i--) {
		HeapAdjust(m_pData, i, m_length);
	}
}
/*
void MaxHeap::HeapAdjust(int data[], int parentIndex, int length) {

	int key = data[parentIndex];
	int childIndex = 2 * parentIndex + 1;

	while (childIndex < length) {
		//������������������ұ�����������ѡ��������
		if (childIndex + 1 < length && data[childIndex] < data[childIndex + 1]) {
			childIndex++;
		}

		//������ڵ���ڵ����ӽڵ㣬����
		if (key >= data[childIndex]) {
			break;
		}

		//�ӽڵ㸳ֵ�����ڵ�
		data[parentIndex] = data[childIndex];

		//����ɸѡ
		parentIndex = childIndex;
		childIndex = 2 * parentIndex + 1;
	}

	data[parentIndex] = key;
}
*/
int MaxHeap::size() {
	return m_length;
}

int MaxHeap::begin() {
	if (m_length) {
		return m_pData[0];
	}
	else {
		throw "û������";
	}
}

void MaxHeap::deleteMax() {
	if (m_length == 0) {
		printf("û������\n");
		return;
	}
	m_pData[0] = m_pData[m_length - 1];
	m_length--;
	HeapAdjust(m_pData, 0, m_length);
}

void MaxHeap::print() {
	for (int i = 0; i < m_length; i++) {
		printf("%d ", m_pData[i]);
	}
	printf("\n");
}

void MaxHeap::insert(int value) {
	if (m_length >= m_maxLength) {
		printf("�ռ�����������ʧ��\n");
		return;
	}
	int insertIndex = m_length;
	m_length++;
	while (insertIndex > 0 && value > m_pData[(insertIndex - 1) / 2]) {
		m_pData[insertIndex] = m_pData[(insertIndex - 1) / 2];
		insertIndex = (insertIndex - 1) / 2;
	}
	m_pData[insertIndex] = value;
}

void MaxHeap::toArray(int output[],int length) {
	if (length < m_length) {
		printf("���鳤��С�ڶѴ�С���ض����");
	}
	int len = fmin(length, m_length);
	for (int i = 0; i < len; i++) {
		output[i] = m_pData[i];
	}
}

int main() {
	int data[] = { 1, 3, 4, 5, 2, 6, 9, 7, 8, 0 };

	MaxHeap heap = MaxHeap(data, 10, 100);

	heap.print();
	heap.deleteMax();
	heap.print();
	heap.insert(9);
	heap.print();
	heap.insert(10);
	heap.print();

	MaxHeap h1 = MaxHeap();

	h1.insert(9);
	h1.insert(1);
	h1.insert(10);
	h1.print();
	h1.insert(10);
	h1.print();
	printf("%d\n", h1.begin());
	
	system("pause");
	return 0;
}
