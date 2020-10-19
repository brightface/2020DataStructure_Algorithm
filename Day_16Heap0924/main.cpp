#include "MaxHeap.h"
#include "MinHeap.h"
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	//// 중복값을 허용하기 때문에 Node 의 갯수도 255 개 이다.
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