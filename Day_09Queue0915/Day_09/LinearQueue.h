#pragma once

#include <iostream>
#include <assert.h>
using namespace std;

class LinearQueue
{
public:
	LinearQueue(int size) : size(size)
	{
		datas = new int[size];
	}

	~LinearQueue()
	{
		delete[] datas;
		datas = nullptr;
	}

	bool isFull() { return rear == (size - 1); }
	bool isEmpty() { return rear < 0; }

	void Enqueue(int data)
	{
		if (isFull() == false)
			datas[++rear] = data;
		// rear �� ������Ű�� �־��ش�.
		else
			cout << "Queue �� ���� �� �ִ� �����Դϴ�." << endl;
	}

	void Dequeue()
	{
		if (isEmpty() == false)
		{
			for (int i = 1; i < rear + 1; i++)
				datas[i - 1] = datas[i];

			rear--;
		}
		else
			cout << "Queue �� ����ִ� �����Դϴ�." << endl;
	}

	int& Front()
	{
		return datas[0];
	}

	int& Back()
	{
		return datas[rear];
	}



private:
	// �ε����� ���� ��Ű�� �ִ´�.
	int* datas = nullptr;	// ���� �迭
	int size = 0;			// �迭�� ������
	int front = 0;	// ù ��° ��ġ
	int rear = -1;	// ������ ��ġ	
};