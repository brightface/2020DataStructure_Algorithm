#pragma once

#include <iostream>
using namespace std;

// 넣고 증가
template<typename T>
class CircularQueue
{
public:
	CircularQueue(int size) : size(size)
	{
		datas = new T[size];
	}

	~CircularQueue()
	{
		delete[] datas;
		datas = nullptr;
	}

	bool IsFull() { return (rear + 1) % size == front; }
	bool Empty() { return rear == front; }

	void Enqueue(T data)
	{
		if (IsFull() == false)
		{
			datas[rear] = data;
			rear = (rear + 1) % size;
		}
		else
		{
			cout << "가득참!!" << endl;
		}

		ViewIndex();
	}

	void Dequeue()
	{
		if (Empty() == false)
		{
			front = (front + 1) % size;
		}
		else
		{
			cout << "비어있음" << endl;
		}

		ViewIndex();
	}

	T& Front()
	{
		return datas[front];
	}

	void ViewIndex()
	{
		cout << "Current Front Index : " << front << endl;
		cout << "Current Rear Index: " << rear << endl;
		cout << endl;
	}

private:
	T* datas = nullptr;
	int front = 0;
	int rear = 0;
	int size = 0;

};