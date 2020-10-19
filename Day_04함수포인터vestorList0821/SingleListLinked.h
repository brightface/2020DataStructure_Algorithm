#pragma once

#include <iostream>
using namespace std;

template<typename T>
class SingleLinkedList
{
public:
	struct Node
	{
		T data;		// 가지고 있을 data 값

		Node* next = nullptr;	// 다음 노드를 가리키는 포인터
	};

	static Node* Create(T data)
	{
		Node* node = new Node();
		node->data = data;

		return node;
	}

	static void Destroy(Node** node)
	{
		if (*node == nullptr) return;

		// 허상 포인터
		delete(*node);
		*node = nullptr;
	}

public:
	~SingleLinkedList()
	{
		Clear();
	}

	void Push_Back(T data)
	{
		// 노드 생성
		Node* node = Create(data);

		if (head == nullptr)
		{
			// 첫 노드는 머리이자 꼬리
			head = node;
			tail = node;
		}
		else
		{
			tail->next = node;
			tail = tail->next;
		}

		size++;
	}

	void Push_Front(T data)
	{
		// 노드 생성
		Node* node = Create(data);

		if (head == nullptr)
		{
			head = node;
			tail = node;
		}
		else
		{
			node->next = head;
			head = node;
		}

		size++;
	}

	void Pop_Back()
	{
		if (size == 1)
		{
			Destroy(&head);
			tail = nullptr;
		}
		else
		{
			Node* node = head;
			Node* temp = nullptr;

			while (node->next != nullptr)
			{
				// 0 1 2 3 4
				temp = node;
				node = node->next;
			}

			tail = temp;
			tail->next = nullptr;
			Destroy(&node);
		}

		size--;
	}

	void Insert(Node* target, T data)
	{
		if (target->next == nullptr)
			Push_Back(data);
		else
		{
			Node* newNode = Create(data);
			Node* temp = target->next;

			target->next = newNode;
			newNode->next = temp;
			size++;
		}
	}

	void Remove(T key)
	{
		Node* temp = head;
		while (temp->next != nullptr)
		{
			if (temp == head && temp->data == key)
			{
				temp = temp->next;
				Destroy(&head);
				head = temp;
				size--;
			}
			else if (temp == tail && temp->data == key)
			{

			}
			else if (temp->next->data == key)
			{
				Node* toRemove = temp->next;
				temp->next = temp->next->next;
				Destroy(&toRemove);
				size--;
			}
			else
				temp = temp->next;
		}
	}

	void Clear()
	{
		for (int i = size; i > 0; i--)
			Pop_Back();
	}

	int Size() { return size; }

	Node* operator[](int index)
	{
		Node* node = head;
		while (node != nullptr && index-- > 0)
			node = node->next;

		return node;
	}

private:
	Node* head = nullptr;	// 머리
	Node* tail = nullptr;	// 꼬리

	int size = 0;	// 총 노드의 갯수

};