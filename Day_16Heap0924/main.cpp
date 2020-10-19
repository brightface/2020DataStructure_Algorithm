#include "MaxHeap.h"
#include "MinHeap.h"
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	//// �ߺ����� ����ϱ� ������ Node �� ������ 255 �� �̴�.
	//MaxHeap mh;
	//for (int i = 0; i < 255; i++)
	//	mh.Push(rand());

	//for (int i = 0; i < 255; i++)
	//	cout << mh.Pop() << endl;

	MinHeap mh;
	for (int i = 0; i < 255; i++)
		mh.Push(rand());

	for (int i = 0; i < 255; i++)
		cout << mh.Pop() << endl;

	return 0;
}