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

	static Node* Creat(int data)
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

private:
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

	}
};