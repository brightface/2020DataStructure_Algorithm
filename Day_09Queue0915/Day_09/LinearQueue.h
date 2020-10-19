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
		// rear 를 증가시키고 넣어준다.
		else
			cout << "Queue 가 가득 차 있는 상태입니다." << endl;
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
			cout << "Queue 가 비어있는 상태입니다." << endl;
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
	// 인덱스를 증가 시키고 넣는다.
	int* datas = nullptr;	// 동적 배열
	int size = 0;			// 배열의 사이즈
	int front = 0;	// 첫 번째 위치
	int rear = -1;	// 마지막 위치	
};