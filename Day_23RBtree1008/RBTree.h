#pragma once

/*
RBTree ����-�� Ʈ��

vs. 
avl tree�� rb tree�� ���� �����ϰ� ������ �����Ѵ�.
	-> avl �� Ž���� ������, rb �� ����/������ ������.
rb tree�� ��ټ��� ���α׷��� ���� map, multimap, multiset �� �����迭��
	�����ϱ����� �ڷᱸ���� ���ȴ�.
avl tree �� ���� ��ȸ�� �ʿ��� �����ͺ��̽����� ���� ����̵ȴ�.


RBƮ���� �Ӽ�
	1. ��� ������ black�̰ų� red�̴�.
	2. ��Ʈ ���� �׻� black�̴�.
	3. ��� �ٻ����(leaf node)���� �׻� black�̴�.
	4. ���࿡ ��尡 red���, �� ����� �ڽĵ��� �Ѵ� black�̴�.
	5. �� ���~������� ������ ��� ��ο� ���� ������ ����� ���� ����.
	-> ��� ��ο� ���� ���� ����� �Ÿ��� �ִ� ����� �Ÿ��� �ι� �̻��� �ɼ� ����.

*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <Windows.h>
using namespace std;

enum EColor
{
	RED,
	BLACK,
};

class RBTree
{
public:
	struct Node
	{
		int data;
		bool color = RED;
		Node* left = nullptr;
		Node* right = nullptr;
		Node* parent = nullptr;
	};

	static Node* Create(int data)
	{
		Node* node = new Node();
		node->data = data;
		return node;
	}

	static void Delete(Node** node)
	{
		delete(*node);
		*node = nullptr;
	}

	Node* Parent(Node* node)
	{
		return node == nullptr ? nullptr : node->parent;
	}

	Node* GrandParent(Node* node)
	{
		return Parent(Parent(node));
	}

	Node* Uncle(Node* node)
	{
		Node* grandParent = GrandParent(node);
		if (grandParent == nullptr)
			return nullptr;

		if (node->parent == grandParent->left)
			return grandParent->right;
		else
			return grandParent->left;
	}

	Node* Insert(Node* root, Node* node)
	{
		InsertBST(root, node);
		Balance(node);
		root = node;
		while (Parent(root) != nullptr)
			root = Parent(root);

		return root;
	}

	void InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		InOrder(root->left);
		cout << root->data << " " << endl;
		InOrder(root->right);
	}

	void Display(Node* root)
	{
		int depth = 0;
		int maxNumber = 1; //2^(1 - 1)
		int height = Height(root);
		int width = height * pow(2, height - 1);

		queue<Node*> level;
		level.push(root);

		for (int i = 0; i < width * 2; i++)
			cout << "*";
		cout << endl;

		while (depth < height)
		{
			if (maxNumber < 1)
			{
				depth++;
				width /= 2;
				maxNumber = pow(2, depth);

				cout << endl << endl;
			}

			Node* now = level.front();
			if (now != nullptr)
			{
				level.push(now->left);
				level.push(now->right);
			}
			else
			{
				level.push(nullptr);
				level.push(nullptr);
			}

			cout << setw(width);
			if (now != nullptr)
			{
				if (now->color == RED)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				else
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				cout << now->data;
			}
			else
				cout << " ";

			cout << setw(width) << "";
			level.pop();
			maxNumber--;
		}
	}

	void DeleteNode(Node* root, Node* node)
	{
		Node* child = BSTReplace(node);
		bool bBlack = (child == nullptr || child->color == BLACK) && (node->color == BLACK);
		Node* parent = node->parent;

		if (child == nullptr)
		{
			if (node == root)
				root = nullptr;
			else
			{
				if (bBlack == true)
				{
					FixDoubleBlack(root, node);
				}
				else
				{
					if (Sibling(node) != nullptr)
						Sibling(node)->color = RED;
				}
				if (IsLeft(node))
					parent->left = nullptr;
				else
					parent->right = nullptr;
			}
			Delete(&node);
			return;
		}

		if (node->left == nullptr || node->right == nullptr)
		{
			if (node == root)
			{
				node->data = child->data;
				node->left = nullptr;
				node->right = nullptr;
				Delete(&child);
			}
			else
			{
				if (IsLeft(node) == true)
					parent->left = child;
				else
					parent->right = child;

				child->parent = parent;
				Delete(&node);

				if (bBlack == true)
					FixDoubleBlack(root, child);
				else
					child->color = BLACK;
			}
			return;
		}

		SwapValue(child, node);
		DeleteNode(root, child);
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

	void Balance(Node* node)
	{
		if (Parent(node) == nullptr)
			InsertCase1(node);
		else if (Parent(node)->color == BLACK)
			InsertCase2(node);
		else if (Uncle(node) != nullptr && Uncle(node)->color == RED)
			InsertCase3(node);
		else
			InsertCase4(node);
	}

	void InsertBST(Node* root, Node* node)
	{
		if (root != nullptr)
		{
			if (node->data < root->data)
			{
				if (root->left != nullptr)
				{
					InsertBST(root->left, node);
					return;
				}
				else
					root->left = node;
			}
			else
			{
				if (root->right != nullptr)
				{
					InsertBST(root->right, node);
					return;
				}
				else
					root->right = node;
			}
		}

		node->parent = root;
	}


	void InsertCase1(Node* node)
	{
		//node�� tree�� root�϶�
		if (node->parent == nullptr)
			node->color = BLACK;
		else
			InsertCase2(node);
	}

	void InsertCase2(Node* node)
	{
		if (node->parent->color == BLACK)
			return;
		else
			InsertCase3(node);
	}

	//double red �θ� red - ���� ���Ե� �ڽĵ� red
	void InsertCase3(Node* node)
	{
		Node* uncle = Uncle(node);
		Node* grandParent = GrandParent(node);

		if (uncle != nullptr && uncle->color == RED)
		{
			//recoloring
			node->parent->color = BLACK;
			uncle->color = BLACK;
			grandParent->color = RED;
			InsertCase1(grandParent);
		}
		else
			InsertCase4(node);
	}

	void InsertCase4(Node* node)
	{
		//restructuring
		Node* parent = Parent(node);
		Node* grandParent = GrandParent(node);

		if (node == parent->right && parent == grandParent->left)
		{
			RotateLeft(parent);
			node = node->left;
		}
		else if (node == parent->left && parent == grandParent->right)
		{
			RotateRight(parent);
			node = node->right;
		}

		InsertCase5(node);
	}

	void InsertCase5(Node* node)
	{
		Node* parent = Parent(node);
		Node* grandParent = GrandParent(node);

		if (node == parent->left)
			RotateRight(grandParent);
		else
			RotateLeft(grandParent);

		parent->color = BLACK;
		grandParent->color = RED;
	}

	void RotateLeft(Node* node)
	{
		Node* temp = node->right;
		Node* parent = Parent(node);

		if (temp == nullptr)
		{
			cout << "node�� ���γ�尡 �ƴ�(RotateLeft)" << endl;
			return;
		}

		node->right = temp->left;
		temp->left = node;
		node->parent = temp;

		if (node->right != nullptr)
			node->right->parent = node;

		if (parent != nullptr)
		{
			if (node == parent->left)
				parent->left = temp;
			else if (node == parent->right)
				parent->right = temp;
		}

		temp->parent = parent;
	}

	void RotateRight(Node* node)
	{
		Node* temp = node->left;
		Node* parent = Parent(node);

		if (temp == nullptr)
		{
			cout << "node�� ���γ�尡 �ƴ�(RotateRight)" << endl;
			return;
		}

		node->left = temp->right;
		temp->right = node;
		node->parent = temp;

		if (node->left != nullptr)
			node->left->parent = node;

		if (parent != nullptr)
		{
			if (node == parent->left)
				parent->left = temp;
			else if (node == parent->right)
				parent->right = temp;
		}

		temp->parent = parent;
	}

	/*
	double black
		1. �θ� ��尡 �����̸� ���� ��ī ������ ��� ���� ��Ȳ
			- > �θ� ���� ���� ����� ������ ��ȯ�Ѵ�.
		2. ���� ��尡 ���̰� �ָ� �ִ� ��ī ��尡 �����϶�
			-> �θ� ��带 �������� �������� ȸ���ϰ�, �θ� ���� ���� �����
			������ ��ȯ�� �Ŀ� �ָ��ִ� ��ī�� ������ ������ �ٲ۴�.
		3. ���� ��尡 ���̰� ������ �ִ� ��ī ��尡 ����, �ָ� �ִ� ��ī��尡 ��
			-> ������带 ���������� ȸ���ϰ�, ������ �ִ� ��ī�� ���� ����� ������ ��ȯ�Ѵ�.
		4. �θ�, ����, ��ī ������ ��� ���϶�
			-> ���� ����� ������ ����� �ٲ��ְ�, �θ� ���� ������ �÷�������.
	*/

	Node* Successor(Node* node)
	{
		Node* temp = node;
		while (temp->left != nullptr)
			temp = temp->left;

		return temp;
	}

	Node* Sibling(Node* node)
	{
		Node* parent = Parent(node);
		if (parent == nullptr)
			return nullptr;

		if (node == parent->left)
			return parent->right;
		else
			return parent->left;
	}

	void SwapColor(Node* node1, Node* node2)
	{
		bool temp = node1->color;
		node1->color = node2->color;
		node2->color = temp;
	}

	void SwapValue(Node* node1, Node* node2)
	{
		int temp = node1->data;
		node1->data = node2->data;
		node2->data = temp;
	}

	//���� ��带 ã�� �Լ�
	Node* BSTReplace(Node* node)
	{
		//�ڽ��� ���ʴ� ������
		if (node->left != nullptr && node->right != nullptr)
			return Successor(node->right);

		//�ٻ�����϶�
		if (node->left == nullptr && node->right == nullptr)
			return nullptr;

		if (node->left != nullptr)
			return node->left;
		else
			return node->right;
	}

	bool IsLeft(Node* node)
	{
		return node->parent->left == node ? true : false;
	}

	bool HasRedChild(Node* node)
	{
		return (node->left != nullptr && node->left->color == RED)
				|| (node->right != nullptr && node->right->color == RED);
	}

	

	void FixDoubleBlack(Node* root, Node* child)
	{
		if (child == root)
			return;

		Node* sibling = Sibling(child);
		Node* parent = child->parent;
		if (sibling == nullptr)
		{
			FixDoubleBlack(root, parent);
		}
		else
		{
			if (sibling->color == RED)
			{
				parent->color = RED;
				sibling->color = BLACK;
				if (IsLeft(sibling) == true)
					RotateRight(parent);
				else
					RotateLeft(parent);

				FixDoubleBlack(root, child);
			}
			else
			{
				if (HasRedChild(sibling))
				{
					if (sibling->left != nullptr && sibling->left->color == RED)
					{
						if (IsLeft(sibling) == true)
						{
							sibling->left->color = sibling->color;
							sibling->color = parent->color;
							RotateRight(parent);
						}
						else
						{
							sibling->left->color = parent->color;
							RotateRight(sibling);
							RotateLeft(parent);
						}
					}
					else
					{
						if (IsLeft(sibling) == true)
						{
							sibling->right->color = parent->color;
							RotateLeft(sibling);
							RotateRight(parent);
						}
						else
						{
							sibling->right->color = sibling->color;
							sibling->color = parent->color;
							RotateLeft(parent);
						}
					}
					parent->color = BLACK;
				}
				else
				{
					sibling->color = RED;
					if (parent->color == BLACK)
						FixDoubleBlack(root, parent);
					else
						parent->color = BLACK;
				}
			}
		}
	}
};

