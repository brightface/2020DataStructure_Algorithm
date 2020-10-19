#pragma once

/*
	트리 구현
	1. 배열 ( N-Link )
	2. 연결 리스트 ( Left-Child, Right-Sibbling )

	2진 트리
	1. 자식 노드가 2개 밖에 없는 트리를 2진 트리라고 부른다.
	2. 검색과 삭제를 빼면 일반적으로 상수 시간 복잡도를 가진다.
	3. 검색과 삭제를 넣었을 때 최악의 경우에는 O(n) 의 시간 복잡도를 가진다.
*/

/*
	배열로 구현한 이진트리
	1. 현재 노드가 arr[n] 일 때
	- 현재 노드의 부모 -> arr[(n + 1) / 2 - 1]
	- 현재 노드의 왼쪽 자식 -> arr[n * 2 + 1]
	- 현재 노드의 오른쪽 자식 -> arr[n * 2 + 2]
	- 형제 노드( 내가 왼쪽, 홀수 ) -> arr[n + 1]
	- 형제 노드( 내가 오른쪽, 짝수 ) -> arr[n - 1]
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
		// 전위 ( Root, Left, Right )
		if (node == nullptr) return;
		cout << " " << node->data;

		PreOrder(node->left);
		PreOrder(node->right);
	}

	static void InOrder(Node* node)
	{
		// 중위 ( Left, Root, Right )
		if (node == nullptr) return;
		InOrder(node->left);
		cout << " " << node->data;
		InOrder(node->right);
	}

	static void PostOrder(Node* node)
	{
		// 후위 ( Left, Right, Root )
		if (node == nullptr) return;
		PostOrder(node->left);
		PostOrder(node->right);
		cout << " " << node->data;
	}

	
};