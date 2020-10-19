#include <iostream>
#include <functional>
using namespace std;

struct S
{
	int value = 0;
	S(int value) : value(value) {}

	/*S operator()(const S& other)
	{
		cout << "() ������ ������" << endl;

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
		�Լ� �����ͷ� ���� �� �ִ� �͵�
		1. �Լ� ( C��� ���� )
		2. Callable
		3. C++ �� �Ѿ���鼭 () ��ȣ ���� �ݰ� �� �� �ִ� �͵�	  // Callable
		4. ������											  // Callable
		5. ���ٽ�											  // Callable 
	*/

	// ���ϱ� ������ �Լ� ������
	S s(10);
	S s2(20);
	function<S&(S&, S&)> fp1 = &S::operator+;
	S s3 = fp1(s, s2);
	
	// ������ ������
	/*function<S(const S&)> fp1 = S();
	fp1(s);*/


	return 0;
}