#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include "ArrayStack.h"
#include "DoubleLinkedListStack.h"
using namespace std;

/*
	stack
	- 선형 자료구조에서만 형용된다.
	- 후입선출 ( 제일 마지막에 들어온 것이 제일 먼저 나간다 )
	- stack 은 Pop, Push, Top 이 3 가지 함수만 있으면 쓸 수 있다.
*/

class A
{
public:
	int& Top() { return value; }
	const int& Top() const { return value; }	// 객체가 상수화 됐을때 호출

private:
	int value;

	// mutable int value;	// mutable 은 변이 가능한 이라는 뜻을 가지고 있고 const, 즉 상수도 바꿀 수 있다.

};

void Function(const A a)	// 통상적으로 매개변수로 받아올 때 많이 쓰인다.
{
	// const A a;	// 객체 상수화 ( 멤버 변수들이 전부 다 상수화가 된다. )
	a.Top();
}

void Function2(const stack<int>& s)
{
	// 매개변수의 값을 바꾸고 싶지 않을 때
	s.top();
}

int main()
{
	// 어떻게 써도 문제가 없음
	/*stack<int> s;
	stack<int, vector<int>> sv;
	stack<int, list<int>> sl;
	
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	while (s.empty() != true)
	{
		cout << s.top() << endl;
		s.pop();
	}*/

	/*ArrayStack<int> as(255);
	as.Push(10);
	as.Push(20);
	as.Push(30);
	as.Push(40);

	while (as.Empty() != true)
	{
		cout << as.Top() << endl;
		as.Pop();
	}*/

	DoubleLinkedListStack<int> dls;
	dls.Push(10);
	dls.Push(20);
	dls.Push(30);
	dls.Push(40);
	
	while (dls.Empty() != true)
	{
		cout << dls.Top() << endl;
		dls.Pop();

		int a = 0;
	}


	return 0;
}