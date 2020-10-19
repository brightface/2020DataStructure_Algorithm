#include <iostream>
#include <functional>
#include <vector>
using namespace std;

void Function()
{
	cout << "Function" << endl;
}

void Function2(int value)
{
	cout << value << endl;
}

//void Function(int a)
//{
//	cout << "OverLoading1" << endl;
//}
//
//void Function(int a, int b)
//{
//	cout << "OverLoading2" << endl;
//}

int main()
{
	Function();
	// 증분 링크
	// 함수 테이블

	// dll, dynamic Linked Lib ( 동적 라이브러리 )
	// lib, 정적 라이브러리
	// 증분링크 통해 함수 테이블을 사용 ( 최적화, 속도를 위함 )
	// 증분링크를 사용하지 않으면 중간에 거치는 과정 없이 바로 함수의 원본 주소로 건너 뛰어 버린다.

	// 함수 포인터 : 함수의 주소를 저장
	// C 언어 함수포인터
	void(*fp1)() = Function;		// 자료형(* 함수포인터 이름 ) ( 매개변수 리스트 ) = 함수의 이름;
	// void(*fp2)(int) = Function;
	// void(*fp3)(int, int) = Function;
	// C 언어에서 함수포인터의 대상은 함수들이었다.

	/* 
		함수를 함수포인터로 사용하는 이유는
		-> 함수를 객체화 하여 사용하기 위해서이다.
	*/ 

	// C++ 함수 포인터
	function<void()> fp4 = Function;
	function<void(int)> fp5 = Function2;

	// Vector
	vector<void(*)()> vec;
	vec.push_back(fp1);		// 함수
	vec.push_back([]() {cout << "Lambda" << endl; });	// 람다

	for (void(*fp1)() : vec)
		fp1();


	return 0;
}