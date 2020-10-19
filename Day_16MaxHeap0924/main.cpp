#include "MaxHeap.h"
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	MaxHeap mh;
	for (int i = 0; i < 255; i++)
		mh.Push(rand());

	for (int i = 0; i < 255; i++)
		cout << mh.Pop() << endl;


	return 0;
}