#include "ListQueue.h"
#include "CurcularQueue.h"

int main()
{
	/*ListQueue<int> lq(5);

	lq.Enqueue(10);
	lq.Enqueue(20);
	lq.Enqueue(30);
	lq.Enqueue(40);
	lq.Enqueue(50);
	lq.Enqueue(60);

	while (lq.Empty() == false)
	{
		cout << lq.Front() << endl;
		lq.Dequeue();
	}

	lq.Dequeue();*/

	CircularQueue<int> cq(5);
	cq.Enqueue(20);
	cq.Enqueue(30);
	cq.Enqueue(50);
	cq.Dequeue();
	cq.Enqueue(10);
	cq.Enqueue(60);
	cq.Dequeue();
	cq.Dequeue();




	return 0;
}