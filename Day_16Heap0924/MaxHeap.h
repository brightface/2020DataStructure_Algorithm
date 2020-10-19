#pragma once

/*
	 - k 레벨에 있는 노드의 최대 갯수를 구하는 식은 2 ^ (k - 1) 이다.

	///////////////////////////////////////////////////////////////////////////
	 
	< 정 이진트리 ( Full Binary Tree ) >
	- 마지막 잎새 노드를 제외한 모든 노드가 자식노드를 2 개 또는 0 개를 가지고 있는 트리이다.
	- I 가 내부노드의 갯수라고 했을 때 잎새 노드의 갯수는 I + 1 개 이다.
	- 총 노드의 갯수는 2I + 1 개가 총 노드의 갯수이다.

	< 정 이진트리에 총 N 개의 노드가 있다고 할 때 >
	- 총 내부 노드의 갯수 : (N - 1) / 2
	- 총 잎새 노드의 갯수 : (N + 1) / 2

	< 정 이진트리에 L 개의 잎새 노드가 있을때 >
	- 총 노드의 갯수 : 2L - 1
	- 총 내부 노드의 갯수 : L - 1

	///////////////////////////////////////////////////////////////////////////

	 < 포화 이진트리 ( Perfect Binary Tree ) >
	 - 잎새노드의 깊이가 모두 같고 각 노드들이 2 개의 자식을 가지는 트리이다.
	 
	 < 높이가 H 일때 >
	 - 총 노드의 갯수 : 2^H - 1

	///////////////////////////////////////////////////////////////////////////

	< 완전 이진 트리 ( Complete Binary Tree ) >
	- 완전 이진 트리는 마지막 레벨을 제외한 모든 레벨에서 노드들이 가득 찬 이진트리이다.
	- 다만, 노드들은 삽입될 때 트리의 왼쪽부터 채워져야 한다.

	< 높이가 H 일때 노드의 갯수는 >
	- 2^(H - 1) ~ 2^H - 1 : 범위형 식이 된다.

	< 노드의 갯수가 N 일때 >
	- 완전 이진트리의 높이는 ceil(log2(N + 1)) : ceil 함수는 올림 해주는 함수이다.

	// HeapTree 가 우선순위 Queue 를 위해서 만들어진 알고리즘이며 완전 이진 트리의 일종이다. //
*/

/*
	< 우선순위 큐의 이용사례 >
	- 시뮬레이션 시스템
	- 네트워크 트래픽 제어
	- 운영체제의 작업 스케쥴링 등등에 사용된다.

	// 우선순위 큐는 배열, 연결리스트, 힙으로 구현가능 //

	< 힙이란? >
	- 완전 이진트리의 일종
	- 우선순위 큐를 위하여 만들어진 자료구조
	- 여러개의 값들 중에서 최대값이나 최소값을 빠르게 찾아내도록 만들어진 자료구조이다.
	- 큰 값이 상위 레벨에 있고 작은 값이 하위 레벨에 있다.
	- 로직상 최대값, 최소값을 동시에 찾을 수 없다.
	- Heap 은 중복 Key 값을 허용한다.
	- 부모노드의 키값이 자식노드보다 항상 크다. - Max Heap
	- 부모노드의 키값이 자식노드보다 항상 작다. - Min Heap

	< 힙의 종류 >
	1. 최대 힙 ( Max Heap )
	- 부모 노드의 키값이 자식노드의 키값 보다 크거나 같은 완전 이진트리

	2. 최소 힙 ( Min Heap )
	- 부모 노드의 키값이 자식노드의 키값 보다 작거나 같은 완전 이진트리

	< 힙의 특징들 >
	- 힙을 일반적으로 구현하는 구조는 배열이다.
	- 힙을 구현할 때는 0 번 인덱스는 비워놓고 1 번 인덱스부터 차곡차곡 쌓아가게 된다.

	< 힙에서의 부모 노드와 자식 노드의 관계 >
	// 현재 노드의 인덱스를 Current 라고 했을 때 //
	- 인덱스에 0 을 안 넣는 이유는 계산을 편하게 하기 위해서. 0 을 곱하면 0 이 되버리기 때문이다.
	- 부모 노드의 인덱스 : current / 2
	- 자식 Left 의 인덱스 : current * 2 
	- 자식 Right 의 인덱스 : current * 2 + 1 

	< 힙의 삽입 >
	- 힙에 새로운 요소를 들어오면 새로운 노드를 힙의 마지막 위치에 삽입한다.
	- 새로운 노드를 부모 노드들과 교환해가면서 힙의 성질을 만족시킨다.

	< 힙의 삭제 >
	- 루트의 값을 반환을 하고 루트와 마지막 노드를 스왑한다.
	- 다시 값을 비교해가면서 정렬을 한다.
*/

extern void Swap(int* a, int* b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

#include <Windows.h>
#define MAX_ARRAY_SIZE 256	// 고정 배열 크기로 만들어 줄것이다.

class MaxHeap
{
public:
	MaxHeap()
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
		while (current > 1 && values[current] > values[parent])
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
			child = values[child] > values[child + 1] ? child : child + 1;
		}

		// 이렇게 재정렬 하는것을 Heap 정렬이라고 부른다.
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