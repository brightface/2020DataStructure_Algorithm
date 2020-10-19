#include <iostream>
#include <functional>
using namespace std;

struct S
{
	int value = 0;
	S(int value) : value(value) {}

	/*S operator()(const S& other)
	{
		cout << "() 연산자 재정의" << endl;

		return other;
	}*/

	S& operator+(const S& other)
	{
		S temp(value + other.value);
		cout << temp.value << endl;

		return temp;
	}
};

int main()
{
	/*
		함수 포인터로 만들 수 있는 것들
		1. 함수 ( C언어 시절 )
		2. Callable
		3. C++ 로 넘어오면서 () 괄호 열고 닫고 할 수 있는 것들	  // Callable
		4. 연산자											  // Callable
		5. 람다식											  // Callable 
	*/

	// 더하기 연산자 함수 포인터
	S s(10);
	S s2(20);
	function<S&(S&, S&)> fp1 = &S::operator+;
	S s3 = fp1(s, s2);
	
	// 연산자 재정의
	/*function<S(const S&)> fp1 = S();
	fp1(s);*/


	return 0;
}