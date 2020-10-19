#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include "ArrayStack.h"
#include "DoubleLinkedListStack.h"
using namespace std;

/*
	stack
	- ���� �ڷᱸ�������� ����ȴ�.
	- ���Լ��� ( ���� �������� ���� ���� ���� ���� ������ )
	- stack �� Pop, Push, Top �� 3 ���� �Լ��� ������ �� �� �ִ�.
*/

class A
{
public:
	int& Top() { return value; }
	const int& Top() const { return value; }	// ��ü�� ���ȭ ������ ȣ��

private:
	int value;

	// mutable int value;	// mutable �� ���� ������ �̶�� ���� ������ �ְ� const, �� ����� �ٲ� �� �ִ�.

};

void Function(const A a)	// ��������� �Ű������� �޾ƿ� �� ���� ���δ�.
{
	// const A a;	// ��ü ���ȭ ( ��� �������� ���� �� ���ȭ�� �ȴ�. )
	a.Top();
}

void Function2(const stack<int>& s)
{
	// �Ű������� ���� �ٲٰ� ���� ���� ��
	s.top();
}

int main()
{
	// ��� �ᵵ ������ ����
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