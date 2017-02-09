#include <cstdio>
#include "BinaryTree.h"
#include <stack>

BinaryTreeNode* CreateBinaryTreeNode(int value) {
	BinaryTreeNode* pNode = new BinaryTreeNode();
	if (pNode == nullptr) {
		return nullptr;
	}
	pNode->m_nValue = value;
	pNode->m_pLeft = nullptr;
	pNode->m_pRight = nullptr;

	return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight) {
	if (pParent == nullptr) {
		return;
	}
	pParent->m_pLeft = pLeft;
	pParent->m_pRight = pRight;
}

void PrintTreeNode(const BinaryTreeNode* pNode) {
	if (pNode == nullptr) {
		printf("this node is nullptr.\n");
	}
	else {
		printf("node:%d\n", pNode->m_nValue);
		if (pNode->m_pLeft != nullptr) {
			printf("left:%d\n", pNode->m_pLeft->m_nValue);
		}
		else {
			printf("left child is nullptr.\n");
		}
		if (pNode->m_pRight != nullptr) {
			printf("right:%d\n", pNode->m_pRight->m_nValue);
		}
		else {
			printf("right child is nullptr.\n");
		}
	}
}

void PrintTree(const BinaryTreeNode* pNode) {
	PrintTreeNode(pNode);

	if (pNode != nullptr) {
		if (pNode->m_pLeft != nullptr) {
			PrintTree(pNode->m_pLeft);
		}
		if (pNode->m_pRight != nullptr) {
			PrintTree(pNode->m_pRight);
		}
	}
}

void DestroyTree(BinaryTreeNode* pRoot) {
	if (pRoot != nullptr) {
		BinaryTreeNode* pLeft = pRoot->m_pLeft;
		BinaryTreeNode* pRight = pRoot->m_pRight;

		delete pRoot;
		pRoot = nullptr;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}

void Visit(BinaryTreeNode* pNode) {
	printf("%d ", pNode->m_nValue);
}

/**
* 中 左 右
*/
void PreOrder(BinaryTreeNode* pRoot) {
	if (pRoot == nullptr) {
		printf("this node is nullptr.\n");
		return;
	}
	
	Visit(pRoot);
	if (pRoot->m_pLeft != nullptr) {
		PreOrder(pRoot->m_pLeft);
	}
	if (pRoot->m_pRight != nullptr) {
		PreOrder(pRoot->m_pRight);
	}
}

/**
* 左 中 右
*/
void InOrder(BinaryTreeNode* pRoot) {
	if (pRoot == nullptr) {
		printf("this node is nullptr.\n");
		return;
	}
	
	if (pRoot->m_pLeft != nullptr) {
		InOrder(pRoot->m_pLeft);
	}

	Visit(pRoot);

	if (pRoot->m_pRight != nullptr) {
		InOrder(pRoot->m_pRight);
	}
}

/**
* 左 右 中
*/
void PostOrder(BinaryTreeNode* pRoot) {
	if (pRoot == nullptr) {
		printf("this node is nullptr.\n");
		return;
	}

	if (pRoot->m_pLeft != nullptr) {
		PostOrder(pRoot->m_pLeft);
	}

	if (pRoot->m_pRight != nullptr) {
		PostOrder(pRoot->m_pRight);
	}

	Visit(pRoot);
}

/*
* 非递归前序遍历，借助堆栈
*/
void PreOrderNonRecursion(BinaryTreeNode* pRoot) {
	if (pRoot == nullptr) {
		printf("this node is nullptr.\n");
		return;
	}

	std::stack<BinaryTreeNode*> stack;
	BinaryTreeNode* pNode = pRoot;

	while (pNode != nullptr || !stack.empty()) {
		if (pNode!= nullptr) {
			Visit(pNode);
			stack.push(pNode);
			pNode = pNode->m_pLeft;
		}
		else {
			pNode = stack.top();
			stack.pop();
			pNode = pNode->m_pRight;
		}
	}
}

void InOrderNonRecursion(BinaryTreeNode* pRoot) {
	if (pRoot == nullptr) {
		printf("this node is nullptr.\n");
		return;
	}

	std::stack<BinaryTreeNode*> stack;
	BinaryTreeNode* pNode = pRoot;

	while (pNode != nullptr || !stack.empty()) {
		if (pNode != nullptr) {
			stack.push(pNode);
			pNode = pNode->m_pLeft;
		}
		else {
			pNode = stack.top();
			stack.pop();
			Visit(pNode);
			pNode = pNode->m_pRight;
		}
	}
}

void PostOrderNonRecursion(BinaryTreeNode* pRoot) {
	if (pRoot == nullptr) {
		printf("this node is nullptr.\n");
		return;
	}

	//辅助分别是否遍历过左右子树
	struct TempNode
	{
		BinaryTreeNode* pNode;
		char flag;
	};

	std::stack<TempNode*> stack;
	BinaryTreeNode* pNode = pRoot;
	TempNode* pTemp;

	while (pNode != nullptr || !stack.empty()) {
		//遍历左子树
		while (pNode != nullptr) {
			pTemp = new TempNode();
			pTemp->pNode = pNode;
			pTemp->flag = 'l';
			stack.push(pTemp);
			pNode = pNode->m_pLeft;
		}

		//左右子树都遍历结束后，访问根节点
		while (!stack.empty() && (stack.top()->flag == 'r')) {
			pTemp = stack.top();
			stack.pop();
			
			Visit(pTemp->pNode);
		}

		//遍历右子树
		if(!stack.empty()) {
			pTemp = stack.top();
			pTemp->flag = 'r';
			pNode = pTemp->pNode->m_pRight;
		}
	}
	
}