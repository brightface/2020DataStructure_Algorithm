#pragma once

/*
	정 이진트리(Full Binary Tree)
	잎새 노드를 제외한 모든 노드가 자식노드를
	2개 또는 0개를 가지는 트리
	I가 내부노드의 개수라고 했을때
	잎새노드의 개수 : I + 1 개
	총 노드의 개수 : 2I + 1 개

	
	정 이진트리에 총 N개의 노드가 있을때
	총 내부 노드의 개수  (N - 1) / 2
	총 잎새 노드의 개수  (N + 1) / 2

	정 이진트리에 L개의 잎새 노드가 있을때
	총 노드의 개수  2L - 1
	총 내부 노드의 개수 L - 1

	////////////////////////////////////
	포화 이진트리 (Perfect Binary Tree)
	포화 이진트리는 잎새노드의 깊이가 모두 같고
	각 노드들이 2개의 자식을 가지는 트리
	높이가 h일때
	총 노드의 개수 : 2^h - 1
	////////////////////////////////////
	완전 이진트리(Complete Binary Tree)
	완전이진트리는 마지막 레벨을 제외한 모든 레벨에서
	노드들이 가득 찬 이진트리. 다만, 노드들은 삽입될때
	트리의 왼쪽부터 채워져야 함.
	높이가 h일때 노드의 개수는
	2^(h - 1) ~ 2^h - 1
	노드의 개수가 N일때
	완전 이진트리의 높이는 ceil(log2(N + 1))
*/

/*
	우선순위 큐의 이용사례
	- 시뮬레이션 시스템
	- 네트워크 트래픽 제어
	- 운영체제의 작업 스케쥴링
	등등

	우선순위 큐는 배열, 연결리스트, 힙으로 구현가능

	힙?
	완전 이진트리의 일종
	우선순위 큐를 위하여 만들어진 자료구조
	여러개의 값들 중에서 최대값이나 최소값을 빠르게 찾아내도록
	만들어진 자료구조.
		부모노드의 키값이 자식노드보다 항상크다(작다)
		큰 값이 상위 레벨에 있고, 작은 값이 하위 레벨에 있다.

	힙의 종류
	최대힙(max heap)
		- 부모 노드의 키값이 자식 노드의 키값 보다 크거나 같은 완전 이진트리
	최소힙(min heap)
		- 부모 노드의 키값이 자식 노드의 키값 보다 작거나 같은 완전 이진트리

	힙에서의 부모 노드와 자식 노드의 관계
	현재 노드의 인덱스를 current라고 했을때
	1. 부모 노드의 인덱스 : current / 2
	2. 자식 Left의 인덱스 : current * 2
	3. 자식 right의 인덱스 : current * 2 + 1

	힙의 삽입
	힙에 새로운 요소를 들어오면 새로운 노드를 힙의 
	마지막 위치에 삽입한다.
	새로운 노드를 부모 노드들과 교환해가면서 
	힙의 성질 만족시킨다.

	힙의 삭제
	루트의 값을 반환을 하고, 루트와 마지막노드를 스왑한다.
	다시 값을 비교해 가면서 정렬을 한다.
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