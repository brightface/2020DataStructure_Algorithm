#pragma once

/*
	<< AVL Tree ( Adelson, Velsky and Landis ��� ������� ���� AVL �̴�. ) >>
	- ���� ���� Ʈ�� �߿� �ϳ��̴�.


	<< ���� ���� Ʈ����?? >>
	- �� ��忡�� ���� ����Ʈ���� ���̿� ������ ����Ʈ���� ���� ���� 1 ������ ���� Ʈ���̴�.
	- �ð� ���⵵�� O(h) �̴�.


	<< ���� ���� Ʈ���� ���� >>
	- ���ο� ��带 ���� ��, �ұ��� ���·� ���� ���� ����� �������� ���� Ʈ���鿡 ���Ͽ� �ٽ� ������ ��´�.


	<< ������ ��Ÿ���� ��� >>
	- ���� �μ� ( Balance Factor ) ��� ���� �̿��Ѵ�.
	- ���� �μ��� ���� �ڽ��� ���̿��� ������ �ڽ��� ���̸� �� ���̴�.
	- ���� �μ��� 2 �̻��̰ų� -2 �����϶� ������ �����ٰ� �Ѵ�.


	<< ������ ������ ���� 4���� >>
	1. LL ( Left - Left ) Ÿ�� : ���ο� ��尡 �������� ���� ����Ʈ���� ���� ����Ʈ���� ���ԵǴ� ���
	2. RR ( Right - Right ) Ÿ�� : ���ο� ��尡 �������� ������ ����Ʈ���� ������ ����Ʈ���� ���ԵǴ� ���
	3. RL ( Right - Left ) Ÿ�� : ���ο� ��尡 �������� ������ ����Ʈ���� ���� ����Ʈ���� ���ԵǴ� ���
	4. LR ( Left - Right ) Ÿ�� : ���ο� ��尡 �������� ���� ����Ʈ���� ������ ����Ʈ���� ���ԵǴ� ���


	<< ������ �̷�� ���� ��迭�� �ϴ� 4���� ��� >>
	1. LL ȸ�� : ��������� ���ο� �������� ��λ��� ������ ���������� ȸ����Ų��.
	- �θ��带 A, ���� �ڽĳ�带 B ��� ���� �� A �� Left �� B �� Right �� �����ϰ�, B �� Right �� A �� �����Ѵ�.

	2. RR ȸ�� : ��������� ���ο� �������� ��λ��� ������ �������� ȸ����Ų��.
	- �θ��带 A, ������ �ڽĳ�带 B ��� ���� �� A �� Right �� B �� Left �� �����ϰ� B �� Left �� A �� �����Ѵ�.

	3. RL ȸ�� : ��������� ���ο� �������� ��λ��� ������ ������ ȸ���Ŀ� �������� ȸ����Ų��.
	- A �� ������ �ڽĿ� = LL( B ), RR ( A )

	4. LR ȸ�� : ��������� ���ο� �������� ��λ��� ������ ���� ȸ���Ŀ� ���������� ȸ����Ų��.
	- A �� ���� �ڽĿ� = RR ( B ), LL ( A ) 
*/

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

class AVL
{
public:
	struct Node
	{
		int data;

		Node* left = nullptr;
		Node* right = nullptr;
	};

	static Node* Create(int data)
	{
		Node* node = new Node();
		node->data = data;

		return node;
	}

	static void Destroy(Node** node)
	{
		delete(*node);
		*node = nullptr;
	}

public:
	Node* Insert(Node* root, int data)
	{
		if (root == nullptr)
			return Create(data);
		else if (data < root->data)
		{
			root->left = Insert(root->left, data);
			root = Balance(root);
		}
		else if (data >= root->data)
		{
			root->right = Insert(root->right, data);
			root = Balance(root);
		}

		return root;
	}

	void InOrder(Node* node)
	{
		if (node == nullptr)
			return;

		InOrder(node->left);
		cout << node->data << " " << endl;
		InOrder(node->right);
	}

	Node* Find(Node* root, int data)
	{
		Node* node = root;

		while (node != nullptr)
		{
			if (data == node->data)
				return node;
			else if (data < node->data)
				node = node->left;
			else
				node = node->right;
		}

		return nullptr;
	}

	void Display(Node* root, int depth, int width)
	{
		if (root == nullptr) return;

		if (root->left != nullptr)
			Display(root->left, depth + 1, width / 2);

		for (int i = 0; i < depth; i++)
			cout << endl;

		for (int i = 0; i < depth + 1; i++)
			cout << setw(width);

		if (root != nullptr)
			cout << root->data;
		else
			cout << " ";

		if (root->right != nullptr)
			Display(root->right, depth + 1, width / 2);
	}

	/*
		ť�� �����
		ó������ ť�� ��Ʈ��带 �ִ´�,
		��Ʈ����� ���� ������ ���鵵 ť�� �ִ´�.
		Ŀ���� �ű� �� ��Ʈ ����� �����͸� ����ϰ�
		ť���� �� ( maxNumber-- )
		width / 2 �� ���� �� ����

		�ι�°����
		���� ������ �ִ� ��� ���� = 2^(height - 1) ���� �����س���
		maxNumber < 1, �� ������ Node ���� �� ó���� ���̴�.
	*/

	void Display2(Node* root, int depth, int width)
	{
		if (root == nullptr) return;

		queue<int> nodes;
		Node* temp = root;
		int height = Height(root);
		int level = 0;
	
		while (temp->right != nullptr)
		{
			Node* left = temp->left;
			Node* right = temp->right;

			if(temp != nullptr)
				nodes.push(temp->data);
			if (left != nullptr)
			{
				temp = temp->left;
				nodes.push(temp->data);
			}
			if (right != nullptr)
			{
				temp = right;
				nodes.push(temp->right->data);
			}
						
			/*if (nodes.back() == temp->right->data)
				temp = left;
			if(nodes.back() == root->left->data)
				temp = right;*/

			int a = 0;
		}
	}

private:
	int Height(Node* node)
	{
		int height = 0;

		if (node != nullptr)
		{
			int left = Height(node->left);
			int right = Height(node->right);
			int maxHeight = max(left, right);

			height = 1 + maxHeight;
		}

		return height;
	}

	int Diff(Node* node)
	{
		int left = Height(node->left);
		int right = Height(node->right);
		int factor = left - right;

		return factor;
	}

	Node* RR(Node* parent)
	{
		Node* temp = parent->right;
		parent->right = temp->left;
		temp->left = parent;

		return temp;
	}

	Node* LL(Node* parent)
	{
		Node* temp = parent->left;
		parent->left = temp->right;
		temp->right = parent;

		return temp;
	}

	Node* LR(Node* parent)
	{
		// A �� ���� �ڽ� = RR (B), LL (A)
		Node* temp = parent->left;
		parent->left = RR(temp);

		return LL(parent);
	}

	Node* RL(Node* parent)
	{
		Node* temp = parent->right;
		parent->right = LL(temp);

		return RR(parent);
	}

	Node* Balance(Node* node)
	{
		Node* temp = node;
		int factor = Diff(node);

		if (factor > 1)
		{
			if (Diff(temp->left) > 0)
				temp = LL(temp);
			else
				temp = LR(temp);
		}
		else if (factor < -1)
		{
			if (Diff(temp->right) > 0)
				temp = RL(temp);
			else
				temp = RR(temp);
		}
		
		return temp;
	}

};