#pragma once

/*
	�� ����Ʈ��(Full Binary Tree)
	�ٻ� ��带 ������ ��� ��尡 �ڽĳ�带
	2�� �Ǵ� 0���� ������ Ʈ��
	I�� ���γ���� ������� ������
	�ٻ������ ���� : I + 1 ��
	�� ����� ���� : 2I + 1 ��

	
	�� ����Ʈ���� �� N���� ��尡 ������
	�� ���� ����� ����  (N - 1) / 2
	�� �ٻ� ����� ����  (N + 1) / 2

	�� ����Ʈ���� L���� �ٻ� ��尡 ������
	�� ����� ����  2L - 1
	�� ���� ����� ���� L - 1

	////////////////////////////////////
	��ȭ ����Ʈ�� (Perfect Binary Tree)
	��ȭ ����Ʈ���� �ٻ������ ���̰� ��� ����
	�� ������ 2���� �ڽ��� ������ Ʈ��
	���̰� h�϶�
	�� ����� ���� : 2^h - 1
	////////////////////////////////////
	���� ����Ʈ��(Complete Binary Tree)
	��������Ʈ���� ������ ������ ������ ��� ��������
	������ ���� �� ����Ʈ��. �ٸ�, ������ ���Եɶ�
	Ʈ���� ���ʺ��� ä������ ��.
	���̰� h�϶� ����� ������
	2^(h - 1) ~ 2^h - 1
	����� ������ N�϶�
	���� ����Ʈ���� ���̴� ceil(log2(N + 1))
*/

/*
	�켱���� ť�� �̿���
	- �ùķ��̼� �ý���
	- ��Ʈ��ũ Ʈ���� ����
	- �ü���� �۾� �����층
	���

	�켱���� ť�� �迭, ���Ḯ��Ʈ, ������ ��������

	��?
	���� ����Ʈ���� ����
	�켱���� ť�� ���Ͽ� ������� �ڷᱸ��
	�������� ���� �߿��� �ִ밪�̳� �ּҰ��� ������ ã�Ƴ�����
	������� �ڷᱸ��.
		�θ����� Ű���� �ڽĳ�庸�� �׻�ũ��(�۴�)
		ū ���� ���� ������ �ְ�, ���� ���� ���� ������ �ִ�.

	���� ����
	�ִ���(max heap)
		- �θ� ����� Ű���� �ڽ� ����� Ű�� ���� ũ�ų� ���� ���� ����Ʈ��
	�ּ���(min heap)
		- �θ� ����� Ű���� �ڽ� ����� Ű�� ���� �۰ų� ���� ���� ����Ʈ��

	�������� �θ� ���� �ڽ� ����� ����
	���� ����� �ε����� current��� ������
	1. �θ� ����� �ε��� : current / 2
	2. �ڽ� Left�� �ε��� : current * 2
	3. �ڽ� right�� �ε��� : current * 2 + 1

	���� ����
	���� ���ο� ��Ҹ� ������ ���ο� ��带 ���� 
	������ ��ġ�� �����Ѵ�.
	���ο� ��带 �θ� ����� ��ȯ�ذ��鼭 
	���� ���� ������Ų��.

	���� ����
	��Ʈ�� ���� ��ȯ�� �ϰ�, ��Ʈ�� ��������带 �����Ѵ�.
	�ٽ� ���� ���� ���鼭 ������ �Ѵ�.
*/

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

#include <Windows.h>
#define MAX_ARRAY_SIZE 256

class MaxHeap
{
public:
	MaxHeap()
	{
		ZeroMemory(values, sizeof(int) * MAX_ARRAY_SIZE);
	}

	void Push(int data)
	{
		values[++heapCount] = data;

		int current = heapCount;
		int parent = current / 2;
		while (current > 1 && values[current] > values[parent])
		{
			Swap(&values[parent], &values[current]);

			current = parent;
			parent = current / 2;
		}
	}

	int Pop()
	{
		int result = values[1];

		Swap(&values[1], &values[heapCount--]);
		
		int current = 1;
		int child = current * 2;

		if (child + 1 <= heapCount)
		{
			child = values[child] > values[child + 1] ? child : child + 1;
		}

		while (child <= heapCount && values[current] < values[child])
		{
			Swap(&values[current], &values[child]);

			current = child;
			child = child * 2;
			if (child + 1 <= heapCount)
			{
				child = values[child] > values[child + 1] ? child : child + 1;
			}
		}

		return result;
	}

private:
	int values[MAX_ARRAY_SIZE];
	int heapCount = 0;
};