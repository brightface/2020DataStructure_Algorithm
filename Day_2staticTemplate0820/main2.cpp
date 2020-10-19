#include <iostream>
#include "Static.h"
using namespace std;

int global;
//static
int main()
{
	/*
		1. 공용 메모리 영역에 저장이 된다.
		2. 초기화는 한번만 된다.
		3. 초기화를 안해줘도 0으로 초기화 된다.
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