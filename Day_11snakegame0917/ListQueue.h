#pragma once

#include <iostream>
using namespace std;

template <typename T>
class ListQueue
{
public:
	struct Node
	{
		T data;

		Node* next = nullptr;
	};

	static Node* Create(T data)
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
	ListQueue(int size) : maxSize(size)
	{

	}

	~ListQueue()
	{
		Clear();
	}

	bool IsFull()
	{
		if (size >= maxSize)
		{
			cout << "가득참!!" << endl;

			return true;
		}
		else
			return false;
	}

	void Enqueue(T data)
	{
		if (IsFull() == false)
		{
			Node* node = Create(data);

			if (front == nullptr)
				front = rear = node;
			else
			{
				rear->next = node;
				rear = node;
			}

			size++;
		}
	}

	bool Empty()
	{
		if (size <= 0)
		{
			cout << "비어있음" << endl;

			return true;
		}
		else
			return false;
	}

	void Dequeue()
	{
		if (Empty() == false)
		{
			if (size == 1)
			{
				Destroy(&front);
				rear = nullptr;
			}
			else
			{
				Node* node = front;

				front = front->next;
				Destroy(&node);
			}

			size--;
		}
	}

	T& Front() { return front->data; }

	void Clear()
	{
		while (Empty() == false)
			Dequeue();
	}

private:
	Node* front = nullptr;
	Node* rear = nullptr;
	int size = 0;
	int maxSize = 0;

};