#pragma once
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* CreateBinaryTreeNode(int value);
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);
void PrintTreeNode(const BinaryTreeNode* pNode);
void PrintTree(const BinaryTreeNode* pNode);
void DestroyTree(BinaryTreeNode* pRoot);
void PreOrder(BinaryTreeNode* pRoot);
void PreOrderNonRecursion(BinaryTreeNode* pRoot);
void InOrder(BinaryTreeNode* pRoot);
void PostOrder(BinaryTreeNode* pRoot);
void Visit(BinaryTreeNode* pNode);
void InOrderNonRecursion(BinaryTreeNode* pRoot);
void PostOrderNonRecursion(BinaryTreeNode* pRoot);