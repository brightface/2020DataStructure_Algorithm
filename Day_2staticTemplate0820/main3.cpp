#include <iostream>
using namespace std;

/*
 c++ ��Ƽ �з����� ���.

 1. ��ü���� ���α׷���
  -> ĸ��ȭ(���м�)
  -> �߻�ȭ
  -> ������
  -> ��Ӽ�

 2. �������� ���α׷���
  prodedural Programming;
  procedure(���ν���) : ���α׷��� �������� ������ �����Ѱ�
  �Լ� ȣ���� ������ �������� ���α׷��� �ۼ��ϴ� ���

 3. �Լ����� ���α׷���

 4. �Ϲ�ȭ ���α׷���
  -> ���� Ÿ�Կ� ���� �����ϴ� �Լ��� Ŭ������ �ۼ��ϴ� ���.
     �ڷ��� �߽����� ���α׷��� ����� ���

*/

//�ΰ��� ���� �����ϴ� �Լ�.
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