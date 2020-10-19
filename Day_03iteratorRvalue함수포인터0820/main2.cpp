#include <iostream>
#include <vector>
using namespace std;

int main()
{
	/*
		L_Value, R_Value 가 그나마 쓰이는 곳
		1. 이동생성자
		2. 람다식 ( R_Value ) // 람다식 자체가 R_Value 라고 한다.
	*/

	// 예전 C언어 시절에는 L_Value 는 왼쪽, 오른쪽에 다 올 수 있었다. R_Value 는 오른쪽 고정
	// 옛날에는 메모리 공간을 특정할 수 없는 것들을 R-Value 라고 했었다.
	int a = 10;
	// 10;	// Literal 상수 - R_Value

	int b = 20 + 30;	// 총 16 Byte 가 들어간다.
	// 이유는 더한 결과를 임시 변수에 저장해두기 때문이다. ( 메모리가 늘어남 ) - R_Value


	// C++ 에서 확장된 L_Value, R_Value
	// 과거에는 L_Value 메모리 주소를 특정하고 데이터를 넣을 수 있었다면.
	// C++ 에서는 메로리 주소를 특정할 수 있지만 데이터를 넣을 수 없다.
	// const int a = 10;	// L_Value

	// 주소를 알고 있지만 데이터를 대입 할 수 없다.
	// int arr[30];
	// arr = 20;	// L_Value

	int& ref = a;		// 우리가 일반적으로 사용하는 것은 L_Value Ref 이다.
	int&& rRef = 30;	// R_Value Refence

	// 이동생성자 : 소유권에 이전이 일어난다.
	vector<int> vec;
	// vec.push_back(rRef);	// 호출되는 클래스의 생성자는 복사생성자가 호출이 된다.
	// 위의 문제를 개선하기 위해 emplace_back 이 나왔다.

	// vec.emplace_back(rRef);		// emplace_back 은 이동 생성자를 호출한다.
	// 이동 생성자를 호출하게 되면 소유권이 넘어가고 원본 데이터 자체가 사라져버린다.
	// 복사생성자를 호출할 필요가 없다는 장점이 있다.
	// 이동 생성자에 들어가는 매개변수가 R_Value Refernce 이다.

	/*
		Push_back ( 선언한 변수를 다시 쓸 일이 있다면 사용한다 )

		int a = 10;
		vector<int> vec.push_back(a);

		Emplace_back ( 선언한 변수를 다시 쓸 일이 없다면 사용한다 )
	*/

		
	return 0;
}