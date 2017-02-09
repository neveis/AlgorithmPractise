#include <cstdio>
#include <cstdlib>
#include "BinaryTree.h"

void Test1() {
	BinaryTreeNode *root = CreateBinaryTreeNode(5);
	BinaryTreeNode *left = CreateBinaryTreeNode(3);
	BinaryTreeNode *right = CreateBinaryTreeNode(4);
	BinaryTreeNode *left1 = CreateBinaryTreeNode(2);
	BinaryTreeNode *right1 = CreateBinaryTreeNode(1);
	BinaryTreeNode *left2 = CreateBinaryTreeNode(7);
	BinaryTreeNode *right2 = CreateBinaryTreeNode(8);

	ConnectTreeNodes(root, left, right);
	ConnectTreeNodes(left, left1, right1);
	ConnectTreeNodes(right, left2, right2);

	PrintTree(root);
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
	PreOrderNonRecursion(root);
	printf("\n");
	InOrderNonRecursion(root);
	printf("\n");
	PostOrderNonRecursion(root);
	printf("\n");
}

int main() {
	Test1();

	system("pause");
	return 0;
}

