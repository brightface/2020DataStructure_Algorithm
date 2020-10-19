#pragma once
/*
	<< Red-Black Tree ( ����-�� Ʈ�� ) >>
	- �����迭�� ������ �� ���ȴ�.

	<< AVL ���� ������ >>
	1. AVL Ʈ���� RB Ʈ���� ���� �� �� �����ϰ� ������ �����Ѵ�. ( RB ���ٴ� Ž���� ������. ), ( ȸ���� �� ���� �Ͼ��. ), ( ����, �����ÿ� �ð��� �� �� ���� �ɸ����� �ִ�. )
	2. RB Ʈ���� ���� ������ �����ϱ� ���� �߰� �����Ͱ� �ʿ��ϴ�.
	3. RB Ʈ���� ��ټ��� ���α׷��� ���� �����迭( Map, Set, MultiMap, MultiSet )�� �����ϱ� ���� �ڷᱸ���� ���ȴ�.
	4. AVL Ʈ���� �� ���� ��ȸ�� �ʿ��� �����ͺ��̽����� ���� ����.

	<< RB Ʈ���� �Ӽ� >>
	1. ��� ������ Black �̰ų� Red �̴�.
	2. ��Ʈ ���� �׻� Black �̴�.
	3. ��� Leaf ������ �׻� Black �̴�.
	4. ���࿡ ��尡 Red ���, �� ����� �ڽĵ��� �� �� Black �̴�.
		-> Red ��尡 ���������� ���� �� ����.
		-> Red ����� �θ�� �׻� Black �̴�.
	5. �� ��� ~ �ڼ� Left ��� ������ ��� ��ο� ���� ������ ����� ���� ����.
		-> ��Ʈ ������ ���� �� ��α����� �Ÿ���, ���� ����� ��α����� �Ÿ��� �� �� ���� �׻� �۰� �ȴ�.

	<< RB Ʈ���� ���� >>
	1. ���ԵǴ� ��� ����� ������ Red �̴�.
	
	<< Red �� ���޾� ���� �� ���� �� �ִ� 2 ���� ��� >>
	A. Recoloring
	- ���Ե� ����� �θ��� ���� ������ Red �� ��
	- ���Ե� ����� �θ�� �θ� ���� ��带 Black ���� �ٲ۴�.
	- �θ��� �θ��尡 Root �� �ƴ϶��, �θ��� �θ� ��带 Red �� �ٲ۴�.

	B. Restructuring
	- ���Ե� ����� �θ��� ���� ������ Black �̰ų� nullptr �� ��
	- ���Ե� ���, �θ�, �θ��� �θ� ������������ �����Ѵ�.
	- �߾Ӱ��� �θ� ���� �����, ������ ��带 �ڽ����� ��ȯ�Ѵ�.
	- �θ� �� ��带 Black ����, ������ ��带 Red �� ��ȯ�Ѵ�.

*/

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <queue>
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

	void Destroy(Node** node)
	{
		delete(*node);
		*node = nullptr;
	}

public:
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
		int maxNumber = 1;
		int height = Height(root);
		int width = pow(2, height - 1) * height;

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
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

				cout << now->data;
			}
			else
				cout << " ";

			level.pop();
			cout << setw(width) << "";
			maxNumber--;
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

	///////////////////////////////////////////////////////////////////////////

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
	
	/**  Node �� Tree �� Root �� ��  **/
	void InsertCase1(Node* node)
	{
		if (node->parent == nullptr)
			node->color = BLACK;
		else
			InsertCase2(node);
	}

	/**  �θ� Node �� Black �� ��  **/
	void InsertCase2(Node* node)
	{
		if (node->parent->color == BLACK)
			return;
		else
			InsertCase3(node);
	}

	/**  �θ� Node �� Red �� ��  **/
	void InsertCase3(Node* node)
	{
		Node* uncle = Uncle(node);
		Node* grandParent = GrandParent(node);

		if (uncle != nullptr && uncle->color == RED)
		{
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

	void RotateRight(Node* node)
	{
		Node* temp = node->left;
		Node* parent = Parent(node);

		if (temp == nullptr)
		{
			cout << "Node �� ���γ�尡 �ƴ�(RotateRight)" << endl;
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

	void RotateLeft(Node* node)
	{
		Node* temp = node->right;
		Node* parent = Parent(node);

		if (temp == nullptr)
		{
			cout << "Node �� ���γ�尡 �ƴ�(RotateLeft)" << endl;
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
};