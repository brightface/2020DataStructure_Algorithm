#pragma once

#include <Windows.h>
#define MAX_ARRAY_SIZE 256	// 고정 배열 크기로 만들어 줄것이다.

class MinHeap
{
public:
	MinHeap()
	{
		ZeroMemory(values, sizeof(int) * MAX_ARRAY_SIZE);
	}

	void Push(int data)
	{
		// 노드의 제일 끝부터 data 를 넣어준다.
		values[++heapCount] = data;

		int current = heapCount;
		int parent = current / 2;	// 부모 인덱스 공식

		// 반복 잘 활용하기
		while (current > 1 && values[current] < values[parent])
		{
			Swap(&values[parent], &values[current]);

			current = parent;
			parent = current / 2;
		}
	}

	int Pop()
	{
		// 1 번 인덱스가 Root 이다.
		int result = values[1];

		// Swap 후 heapCount 는 1 개씩 줄일거기 때문에 -- 연산자를 사용한다.
		Swap(&values[1], &values[heapCount--]);

		int current = 1;
		int child = current * 2;	// 자식을 구하는 공식 ( Left Child )

		if (child + 1 <= heapCount)
		{
			child = values[child] < values[child + 1] ? child : child + 1;
		}

		// 이렇게 재정렬 하는것을 Heap 정렬이라고 부른다.
		while (child <= heapCount && values[current] > values[child])
		{
			Swap(&values[current], &values[child]);

			current = child;
			child = child * 2;

			if (child + 1 <= heapCount)
			{
				child = values[child] < values[child + 1] ? child : child + 1;
			}
		}

		return result;
	}

private:
	int values[MAX_ARRAY_SIZE];
	int heapCount = 0;

};