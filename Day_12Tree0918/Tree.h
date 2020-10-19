#pragma once

/*
	Tree
	- 2���� �ڷᱸ��

	Tree �� �⺻���� ���
	- �����͸� ������ Node
	- ��峢�� ���� Link

	Tree ���� Root �� ������ 1 ���̴�. ( Tree �� ������ ������ ���� ���¶�� �����ϸ� �ȴ�. )

	- ���� ��ΰ� �ϳ��� �ƴ� �������� ��ΰ� ���´ٸ� �� ���� Tree �� �ƴ� Graph �̴�.

	Tree ���� Link �� ������ Node �� �� �������� 1 �� ���� �ȴ�.
	�׸��� ������ Node �� Link �� ����.

	Tree ���� Height �� Level �� ���� ���� ��尡 ������ �ȴ�. Level �� �� ����� ���� �� �� �� �ִ�. Height �� ���̴�.


	LCRS ( Left_Child, Right-Sibling ) : Sibling �� ���� ��� ���� ������ �ִ�.
*/

#include <iostream>
#include <vector>
using namespace std;

class Tree
{
public:
	struct Node
	{
		char data;

		Node* leftChild = nullptr;
		Node* rightSibiling = nullptr;
	};

	static Node* Create(char data)
	{
		Node* node = new Node();
		node->data = data;

		return node;
	}

	static Node* Delete(Node** node)
	{
		delete(*node);
		*node = nullptr;
	}

public:
	void AddChild(Node* parent, Node* child)
	{
		if (parent->leftChild == nullptr)
			parent->leftChild = child;
		else
		{
			Node* node = parent->leftChild;

			while (node->rightSibiling != nullptr)
				node = node->rightSibiling;

			node->rightSibiling = child;
		}
	}

	void PrintNode(Node* node, int level)
	{
		// ����, ����, ����
		// ������ ���� Node �������� Node - left - right ������ ����.
		// ������ Left - Root - Right �����̴�.
		// ������ Left - Right - Root �����̴�.

		for (int i = 0; i < level; i++)
			cout << "-";

		cout << node->data << endl;

		if (node->leftChild != nullptr)
			PrintNode(node->leftChild, level + 1);


		if (node->rightSibiling != nullptr)
			PrintNode(node->rightSibiling, level);
	}

	/*Node* GetNode(Node* root, char data)
	{
		Node* node = nullptr;

		if (root->data == data)
			return root;
		else
		{
			if (root->leftChild != nullptr)
				node = GetNode(root->leftChild, data);
			if (node != nullptr)
				return node;
			if (root->rightSibiling != nullptr)
				return  node = GetNode(root->rightSibiling, data);
		}

		return node;
	}*/

	void GetNode(Node* root, char data, vector<Node*> &result)
	{
		if (root->data == data)
		{
			result.emplace_back(root);
		}
		else
		{
			if (root->leftChild != nullptr)
				GetNode(root->leftChild, data, result);
			if (root->rightSibiling != nullptr)
				GetNode(root->rightSibiling, data, result);
		}
	}

private:


};