#pragma once

/*
	Ʈ�� ����
	1. �迭 ( N-Link )
	2. ���� ����Ʈ ( Left-Child, Right-Sibbling )

	2�� Ʈ��
	1. �ڽ� ��尡 2�� �ۿ� ���� Ʈ���� 2�� Ʈ����� �θ���.
	2. �˻��� ������ ���� �Ϲ������� ��� �ð� ���⵵�� ������.
	3. �˻��� ������ �־��� �� �־��� ��쿡�� O(n) �� �ð� ���⵵�� ������.
*/

/*
	�迭�� ������ ����Ʈ��
	1. ���� ��尡 arr[n] �� ��
	- ���� ����� �θ� -> arr[(n + 1) / 2 - 1]
	- ���� ����� ���� �ڽ� -> arr[n * 2 + 1]
	- ���� ����� ������ �ڽ� -> arr[n * 2 + 2]
	- ���� ���( ���� ����, Ȧ�� ) -> arr[n + 1]
	- ���� ���( ���� ������, ¦�� ) -> arr[n - 1]
*/

///////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class BinaryTree
{
public:
	struct Node
	{
		char* data;

		Node* left = nullptr;
		Node* right = nullptr;

		~Node()
		{
			delete[] data;
		}
	};

	static Node* CreateNode(char* data)
	{
		Node* node = new Node();
		node->data = data;

		return node;
	}

	static void DeleteNode(Node** node)
	{
		delete(*node);
		*node = nullptr;
	}

public:
	static void PreOrder(Node* node)
	{
		// ���� ( Root, Left, Right )
		if (node == nullptr) return;
		cout << " " << node->data;

		PreOrder(node->left);
		PreOrder(node->right);
	}

	static void InOrder(Node* node)
	{
		// ���� ( Left, Root, Right )
		if (node == nullptr) return;
		InOrder(node->left);
		cout << " " << node->data;
		InOrder(node->right);
	}

	static void PostOrder(Node* node)
	{
		// ���� ( Left, Right, Root )
		if (node == nullptr) return;
		PostOrder(node->left);
		PostOrder(node->right);
		cout << " " << node->data;
	}

	
};