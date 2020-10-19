#include "DoubleLinkedList.h"

int main()
{
	DoubleLinkedList<int> l;

	l.Push_Back(10);
	l.Push_Back(20);
	l.Push_Front(0);
	l.Push_Front(-10);
	l.Push_Back(100);
	l.PrintList();


	l.Pop_Front();
	l.Pop_Back();
	l.PrintList();

	l.Insert(l[1], 10000);
	l.PrintList();


	return 0;
}