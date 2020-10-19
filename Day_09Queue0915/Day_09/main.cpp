#include <iostream>
#include <queue>
#include "LinearQueue.h"
#include "ListQueue.h"
using namespace std;

/* 
	Queue ť�� ����� ���� �����̴�.

	ť�� �Է� ť, ������ ť ��� ��� ť�� �� ���� ����Ѵ�.
	�׸��� �� ť�� ������� ó���Ѵ�.

	Queue �� Vector �� ����� �� ����.
	- Vector �� Pop_Front �Լ��� ���� �����̴�.
	
	Queue �� List, �迭 �� ����� �ȴ�.
	- �Ϲ����� ���� �迭�� ����� ���� �������� �ִ�.
	- Front �� ����� �� �ڿ� ���� �����͵��� �տ� �Űܾ� �ϰ� �� ������ �����̱� �����̴�.

	rear + 1 % Size == front �� ���ٸ� ���� ������
*/

int main()
{
	// Enqueue : �������� �о�ִ� queue -- ����� Push
	// Dequeue : �������� ���� queue -- ����� Pop
	// Empty

	//queue<int> q;
	// Queue �� ������ ��ȸ�� �� �ʿ䰡 ����. ���� ��ȸ�� �ʿ��ϴٸ� Queue �� ����ϸ� �ȵȴ�. ( ���� ���ٵ� ���������̴�. )
	// queue<int>::iter -- ��� �Ұ�
	//q.push(10);
	//q.push(20);
	//q.push(30);
	//q.push(40);
	//q.push(50);

	//while (q.empty() == false)
	//{
	//	// ���۷��� ��ȯ�̴�.
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