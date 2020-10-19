#pragma once

#include <Windows.h>
#define MAX_ARRAY_SIZE 256	// ���� �迭 ũ��� ����� �ٰ��̴�.

class MinHeap
{
public:
	MinHeap()
	{
		ZeroMemory(values, sizeof(int) * MAX_ARRAY_SIZE);
	}

	void Push(int data)
	{
		// ����� ���� ������ data �� �־��ش�.
		values[++heapCount] = data;

		int current = heapCount;
		int parent = current / 2;	// �θ� �ε��� ����

		// �ݺ� �� Ȱ���ϱ�
		while (current > 1 && values[current] < values[parent])
		{
			Swap(&values[parent], &values[current]);

			current = parent;
			parent = current / 2;
		}
	}

	int Pop()
	{
		// 1 �� �ε����� Root �̴�.
		int result = values[1];

		// Swap �� heapCount �� 1 ���� ���ϰű� ������ -- �����ڸ� ����Ѵ�.
		Swap(&values[1], &values[heapCount--]);

		int current = 1;
		int child = current * 2;	// �ڽ��� ���ϴ� ���� ( Left Child )

		if (child + 1 <= heapCount)
		{
			child = values[child] < values[child + 1] ? child : child + 1;
		}

		// �̷��� ������ �ϴ°��� Heap �����̶�� �θ���.
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