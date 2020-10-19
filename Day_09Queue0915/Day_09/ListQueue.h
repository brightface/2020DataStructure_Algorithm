#pragma once

#include <iostream>
using namespace std;

template<typename T>
class ListQueue
{
public:
	struct Node
	{
		Node* next = nullptr;

		T data;
	};

	static Node* Create(T data)
	{
		Node* node = new Node();
		node->data = data;

		return node;
	}

	static void Destroy(Node** node)
	{
		delete *node;
		*node = nullptr;
	}

public:
	ListQueue(int size) : size(size)
	{

	}
	~ListQueue()
	{

	}

	bool isFull() { return rear == (size - 1); }
	bool isEmpty() { return rear < 0; }

	void Enqueue(T data)
	{
		Node* node = Create(data);

		if (head == nullptr)
		{
			head = node;
			tail = node;
		}
		else
		{
			tail->next = node;
			tail = tail->next;
		}

		rear++;
	}

	void Dequeue()
	{
		if (size == 0) return;

		if (size == 1)
		{
			Destroy(&head);
			tail = nullptr;
		}
		else
		{
			Node* tempNode = head;
			head = head->next;
			Destroy(&tempNode);
		}

		size--;
		rear--;
	}

	int& Front()
	{
		return head->data;
	}

	int& Back()
	{
		return tail->data;
	}

private:
	Node* head = nullptr;
	Node* tail = nullptr;

	int size = 0;
	int front = 0;
	int rear = -1;
};