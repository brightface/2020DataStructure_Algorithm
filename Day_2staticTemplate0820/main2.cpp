#include <iostream>
#include "Static.h"
using namespace std;

int global;
//static
int main()
{
	/*
		1. ���� �޸� ������ ������ �ȴ�.
		2. �ʱ�ȭ�� �ѹ��� �ȴ�.
		3. �ʱ�ȭ�� �����൵ 0���� �ʱ�ȭ �ȴ�.
	*/

	static int value;
	cout << value << endl;

	/*while (true)
	{
		static int value2 = 10;
		value2 += 10;
		cout << value2 << endl;
	}*/

	cout << sizeof(Static) << endl;

	Static::value4 = 4;
	Static a;
	a.value4 = 4;

	return 0;
}