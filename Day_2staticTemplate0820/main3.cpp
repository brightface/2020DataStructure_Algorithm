#include <iostream>
using namespace std;

/*
 c++ 멀티 패러다임 언어.

 1. 객체지향 프로그래밍
  -> 캡슐화(은닉성)
  -> 추상화
  -> 다형성
  -> 상속성

 2. 절차지향 프로그래밍
  prodedural Programming;
  procedure(프로시저) : 프로그램을 여러개의 단위로 분해한것
  함수 호출의 개념을 바탕으로 프로그램을 작성하는 방식

 3. 함수지향 프로그래밍

 4. 일반화 프로그래밍
  -> 임의 타입에 대해 동작하는 함수나 클래스를 작성하는 방식.
     자료형 중심으로 프로그램을 만드는 방식

*/

//두개의 값을 스왑하는 함수.
//void Swap(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void Swap(float& a, float& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//void Swap(void* a, void* b, int len)
//{
//	void* temp = nullptr;
//	temp = malloc(len);
//	memcpy(temp, a, len);
//	memcpy(a, b, len);
//	memcpy(b, temp, len);
//	free(temp);
//}
//
//#define SWAP(T, a, b) { T temp; temp = a; a = b; b = temp; }
//
//#define MakeSwap(T)\
//void SwapMacro(T &a, T& b)\
//{\
//	T temp;\
//	temp = a;\
//	a = b;\
//    b = temp;\
//}

//MakeSwap(int)
//MakeSwap(double)

template<typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


int main()
{
	/*int a = 10;
	int b = 20;
	SwapMacro(a, b);

	
	SWAP(int, a, b);
	cout << a << " " << b << endl;*/

	int a = 10;
	int b = 20;
	Swap(a, b);
	float c = 20;
	float d = 30;
	Swap(c, d);

	
	return 0;
}