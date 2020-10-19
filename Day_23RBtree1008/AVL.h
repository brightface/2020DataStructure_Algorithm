#pragma once

//AVL
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
		//부모노드의 오른쪽 자식 노드와 데이터를 교환
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

		//왼쪽 서브트리쪽으로 삽입이 되어 균형이 깨진 경우
		if (factor > 1)
		{
			//LL
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

	void Display(Node* root, int depth, int width)
	{
		//pow(2, height - 1)

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
				cout << now->data;
			else
				cout << " ";

			cout << setw(width) << "";
			level.pop();
			maxNumber--;
		}
	}


};