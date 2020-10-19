#pragma once

/*
	Tree
	- 2차원 자료구조

	Tree 의 기본적인 요소
	- 데이터를 가지는 Node
	- 노드끼리 연결 Link

	Tree 에서 Root 는 무조건 1 개이다. ( Tree 는 나무를 뒤집어 놓은 형태라고 생각하면 된다. )

	- 만약 경로가 하나가 아닌 여러개의 경로가 나온다면 그 것은 Tree 가 아닌 Graph 이다.

	Tree 에서 Link 의 갯수는 Node 의 총 갯수보다 1 개 적게 된다.
	그리고 오로지 Node 만 Link 가 없다.

	Tree 에서 Height 는 Level 이 제일 높은 노드가 기준이 된다. Level 은 각 노드의 층이 될 수 도 있다. Height 는 층이다.


	LCRS ( Left_Child, Right-Sibling ) : Sibling 은 형제 라는 뜻을 가지고 있다.
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
		// 전위, 중위, 후위
		// 전위는 현재 Node 기준으로 Node - left - right 순서로 간다.
		// 중위는 Left - Root - Right 순서이다.
		// 후위는 Left - Right - Root 순서이다.

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