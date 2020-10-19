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
	// ���� ��ũ
	// �Լ� ���̺�

	// dll, dynamic Linked Lib ( ���� ���̺귯�� )
	// lib, ���� ���̺귯��
	// ���и�ũ ���� �Լ� ���̺��� ��� ( ����ȭ, �ӵ��� ���� )
	// ���и�ũ�� ������� ������ �߰��� ��ġ�� ���� ���� �ٷ� �Լ��� ���� �ּҷ� �ǳ� �پ� ������.

	// �Լ� ������ : �Լ��� �ּҸ� ����
	// C ��� �Լ�������
	void(*fp1)() = Function;		// �ڷ���(* �Լ������� �̸� ) ( �Ű����� ����Ʈ ) = �Լ��� �̸�;
	// void(*fp2)(int) = Function;
	// void(*fp3)(int, int) = Function;
	// C ���� �Լ��������� ����� �Լ����̾���.

	/* 
		�Լ��� �Լ������ͷ� ����ϴ� ������
		-> �Լ��� ��üȭ �Ͽ� ����ϱ� ���ؼ��̴�.
	*/ 

	// C++ �Լ� ������
	function<void()> fp4 = Function;
	function<void(int)> fp5 = Function2;

	// Vector
	vector<void(*)()> vec;
	vec.push_back(fp1);		// �Լ�
	vec.push_back([]() {cout << "Lambda" << endl; });	// ����

	for (void(*fp1)() : vec)
		fp1();


	return 0;
}