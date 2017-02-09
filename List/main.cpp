#include <cstdlib>
#include <cstdio>
#include "List.h"

void Test1() {
	ListNode* pHead = CreateListNode(1);
	ListNode* p2 = CreateListNode(2);
	ListNode* p3 = CreateListNode(3);
	ListNode* p4 = CreateListNode(4);

	ConnectListNodes(pHead, p2);
	ConnectListNodes(p2, p3);
	ConnectListNodes(p3, p4);

	printf("print list\n");
	PrintList(pHead);
	RemoveNode(&pHead, 1);
	printf("print list\n");
	PrintList(pHead);
	AddToTail(&pHead, 5);
	printf("print list\n");
	PrintList(pHead);
	RemoveNode(&pHead, 0);
	printf("print list\n");
	PrintList(pHead);
	RemoveNode(&pHead, 2);
	printf("print list\n");
	PrintList(pHead);
	RemoveNode(&pHead, 2);
	printf("print list\n");
	PrintList(pHead);
	RemoveNode(&pHead, 0);
	printf("print list\n");
	PrintList(pHead);
	RemoveNode(&pHead, 0);
	printf("print list\n");
	PrintList(pHead);
	AddToTail(&pHead, 6);
	printf("print list\n");
	PrintList(pHead);
	AddToTail(&pHead, 5);
	printf("print list\n");
	PrintList(pHead);
	AddToTail(&pHead, 7);
	printf("print list\n");
	PrintList(pHead);
	RemoveNode(&pHead, 1);
	printf("print list\n");
	PrintList(pHead);
}

int main() {
	Test1();

	system("pause");
	return 0;
}