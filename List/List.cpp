#include <cstdio>
#include "List.h"

ListNode* CreateListNode(int value) {
	ListNode* pNode = new ListNode();
	if (pNode == nullptr) {
		return nullptr;
	}
	pNode->m_nValue = value;
	pNode->m_pNext = nullptr;
	return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext) {
	if (pCurrent == nullptr) {
		return;
	}
	pCurrent->m_pNext = pNext;
}

void PrintListNode(ListNode* pNode) {
	if (pNode == nullptr) {
		printf("The node is nullptr\n");
	}
	else {
		printf("Value is %d\n", pNode->m_nValue);
	}
}

void PrintList(ListNode* pHead) {
	if (pHead == nullptr) {
		return;
	}
	ListNode* pNode = pHead;
	while (pNode != nullptr) {
		printf("%d ", pNode->m_nValue);
		pNode = pNode->m_pNext;
	}
	printf("\n");
}

void DestroyList(ListNode* pHead) {
	if (pHead == nullptr) {
		return;
	}
	ListNode* pNode = pHead;
	while (pNode != nullptr) {
		pHead = pNode->m_pNext;
		delete pNode;
		pNode = pHead;
	}
}

/*
pHead可能为空指针，不能直接对pHead进行赋值，因此要传入指针的指针
*/
void AddToTail(ListNode** pHead,int value) {
	if (*pHead == nullptr) {
		*pHead = CreateListNode(value);
		return;
	}
	ListNode* pNode = *pHead;
	ListNode* pNew = CreateListNode(value);
	while (pNode->m_pNext != nullptr) {
		pNode = pNode->m_pNext;
	}
	pNode->m_pNext = pNew;
}

void RemoveNode(ListNode** p, int index) {
	ListNode* pNode;
	if ( p == nullptr || *p == nullptr) {
		return;
	}
	if (index == 0) {
		pNode = *p;
		*p = pNode->m_pNext;
		delete pNode;
		return;
	}
	int i = 0;
	ListNode* pPreNode =nullptr;
	pNode = *p;
	while (i < index && pNode->m_pNext != nullptr) {
		pPreNode = pNode;
		pNode = pNode->m_pNext;
		i++;
	}
	if (i < index) {
		printf("this node doesn't exist\n");
	}
	else {
		pPreNode->m_pNext = pNode->m_pNext;
		delete pNode;
	}
}