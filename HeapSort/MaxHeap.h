#pragma once
//void MaxHeap(int data[], int length);
void HeapAdjust(int data[], int parentIndex, int length);

class MaxHeap
{
private:
	int* m_pData;
	int m_length;
	int m_maxLength;

public:
	MaxHeap();
	MaxHeap(int maxLength);
	MaxHeap(int input[],int length, int maxLength);
	~MaxHeap();
	//void HeapAdjust(int data[], int parentIndex, int length);
	void insert(int value);
	void deleteMax();
	int size();
	int begin();
	void print();
	void toArray(int output[], int length);
};