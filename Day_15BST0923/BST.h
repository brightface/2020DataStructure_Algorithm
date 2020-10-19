#pragma once

#include <iostream>
#include <algorithm>
using namespace std;

class BST
{
public:
	struct Node
	{
		int key;
		Node* left = nullptr;
		Node* right = nullptr;
	};

	static Node* Create(int key)
	{
		Node* node = new Node();
		node->key = key;
		return node;
	}

	static void Delete(Node** node)
	{
		delete(*node);
		*node = nullptr;
	}

	Node* SearchIteration(Node* node, int key)
	{
		while (node != nullptr)
		{
			if (key == node->key)
				return node;
			else if (key < node->key)
				node = node->left;
			else
				node = node->right;
		}
		return nullptr;
	}

	Node* SearchRecurrsive(Node* node, int key)
	{
		if (node == nullptr) return nullptr;

		if (key == node->key)
			return node;
		else if (key > node->key)
			SearchRecurrsive(node->right, key);
		else
			SearchRecurrsive(node->left, key);
	}

	void InsertNode(Node** root, int key)
	{
		Node* parent = nullptr;
		Node* current = nullptr;
		Node* newNode = Create(key);

		current = *root;
		while (current != nullptr)
		{
			if (key == current->key) return;
			parent = current;
			if (key < parent->key)
				current = parent->left;
			else
				current = parent->right;
		}

		if (parent != nullptr)
		{
			if (key < parent->key)
				parent->left = newNode;
			else
				parent->right = newNode;
		}
		else
			*root = newNode;
	}

	void DeleteNode(Node** root, int key)
	{
		Node* parent = nullptr;
		Node* current = nullptr;
		Node* child = nullptr;
		Node* prev = nullptr;
		Node* next = nullptr;

		current = *root;
		while (current != nullptr && current->key != key)
		{
			parent = current;
			current = (key < parent->key) ? parent->left : parent->right;
		}
		if (current == nullptr)
		{
			cout << "해당 키값을 가진 노드가 존재하지 않음" << endl;
			return;
		}

		if (current->left == nullptr && current->right == nullptr)
		{
			if (parent != nullptr)
			{
				if (parent->left == current)
					parent->left = nullptr;
				else
					parent->right = nullptr;
			}
			else
				*root = nullptr;
		}
		else if ((current->left == nullptr) || (current->right == nullptr))
		{
			child = current->left != nullptr ? current->left : current->right;
			if (parent != nullptr)
			{
				if (parent->left == current)
					parent->left = child;
				else
					parent->right = child;;
			}
			else
				*root = child;
		}
		else
		{
			prev = current;
			next = current->right;
			while (next->left != nullptr)
			{
				prev = next;
				next = next->left;
			}

			if (prev->left == next)
				prev->left = next->right;
			else
				prev->right = next->right;

			current->key = next->key;
			current = next;
		}

		Delete(&current);
	}

	int GetNodeCount(Node* node)
	{
		int count = 0;
		if (node != nullptr)
			count = 1 + GetNodeCount(node->left) + GetNodeCount(node->right);
		return count;
	}

	int GetHeight(Node* node)
	{
		int height = 0;
		if (node != nullptr)
		{
			height = 1 + max(GetHeight(node->left), GetHeight(node->right));
		}
		return height;
	}

	void InOrder(Node* node, int depth)
	{
		if (node == nullptr) return;

		for (int i = 0; i < depth; i++)
			cout << "-";
		cout << node->key << endl;
		InOrder(node->left, depth + 1);
		InOrder(node->right, depth + 1);
	}

private:
};