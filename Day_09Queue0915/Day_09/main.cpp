#include <iostream>
#include <queue>
#include "LinearQueue.h"
#include "ListQueue.h"
using namespace std;

/* 
	Queue 큐는 대기줄 같은 느낌이다.

	큐는 입력 큐, 렌더링 큐 등등 모든 큐를 다 따로 사용한다.
	그리고 이 큐를 쓰레드로 처리한다.

	Queue 는 Vector 를 사용할 수 없다.
	- Vector 는 Pop_Front 함수가 없기 때문이다.
	
	Queue 는 List, 배열 에 사용이 된다.
	- 일반적인 선형 배열을 사용할 때는 문제점이 있다.
	- Front 를 비웠을 때 뒤에 남는 데이터들을 앞에 옮겨야 하고 그 과정이 낭비이기 때문이다.

	rear + 1 % Size == front 와 같다면 가득 차있음
*/

int main()
{
	// Enqueue : 예전에는 밀어넣는 queue -- 현재는 Push
	// Dequeue : 예전에는 빼는 queue -- 현재는 Pop
	// Empty

	//queue<int> q;
	// Queue 는 데이터 순회를 할 필요가 없다. 만약 순회가 필요하다면 Queue 를 사용하면 안된다. ( 임의 접근도 마찬가지이다. )
	// queue<int>::iter -- 사용 불가
	//q.push(10);
	//q.push(20);
	//q.push(30);
	//q.push(40);
	//q.push(50);

	//while (q.empty() == false)
	//{
	//	// 레퍼런스 반환이다.
	//	cout << q.front() << endl;
	//	cout << q.back() << endl;

	//	q.pop();
	//}

	/*LinearQueue lq(5);
	lq.Enqueue(10);
	lq.Enqueue(20);
	lq.Enqueue(30);
	lq.Enqueue(40);
	lq.Enqueue(50);
	lq.Enqueue(60);

	while (lq.isEmpty() == false)
	{
		cout << lq.Front() << endl;
		cout << lq.Back() << endl;

		lq.Dequeue();
	}

	lq.Dequeue();*/

	ListQueue<int> lq(5);
	lq.Enqueue(10);
	lq.Enqueue(20);
	lq.Enqueue(30);
	lq.Enqueue(40);
	lq.Enqueue(50);


	while (lq.isEmpty() == false)
	{
		cout << lq.Front() << endl;
		cout << lq.Back() << endl;

		lq.Dequeue();

	}

	int a = 0;

	return 0;
}