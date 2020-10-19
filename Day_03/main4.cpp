#include <iostream>
#include <functional>
#include <vector>
using namespace std;

class TClass
{
public:
	TClass(int value) : value(value) {}
	~TClass() = default;

	void TestFunction()
	{
		cout << "��� �Լ�" << endl;
	}

	void TestFunction2(int value)
	{
		cout << value << endl;
	}

	void TestFunction3(int value, int value2)
	{
		cout << "value : " << value << endl;
		cout << "value2 : " << value2 << endl;
	}

	static void StaticFunction()
	{
		cout << "����ƽ" << endl;
	}

private:
	int value;

};

int main()
{
	TClass t(10);
	function<void(TClass&)> fp1 = &TClass::TestFunction;	// ��ü ������ �Ѱ��־�� �Ѵ�.
	function<void()> fp2 = &TClass::StaticFunction;			// Static �Լ��� ���� ����
	fp1(t);
	
	function<void()> fp3 = bind(&TClass::TestFunction, t);	// ��ü ������ ������Ű�� ��ü ������ �Լ� ������ �ȿ� ���� �ȴ�.
	// �Ű������� ��� ���ϴ� ��ŭ �ִ� ��Ī�� �������ڶ�� �Ѵ�.

	function<void(int)> fp4 = bind(&TClass::TestFunction2, t, placeholders::_1);
	// ���� ���ڸ� ��� �޴� bind, �߰��� t �� ��ü ������ ������Ű�� ���� ����Ͽ���.

	// placeholders �� �������� �ǹ̰� �ִٴ� ���� �������.
	// ������ ������ ���� ���� ������ �ڹٲ�� ���̴�.
	function<void(int, int)> fp5 = bind(&TClass::TestFunction3, t, placeholders::_1, placeholders::_2);
	// fp5(10, 20);

	// �� ����� �Ű������� ���� �����ϰ� ���� �� �̷������� ����� �� �ִ�.
	function<void(int)> fp6 = bind(&TClass::TestFunction3, t, placeholders::_1, 20);
	fp6(10);

	// �Լ� �����͸� ����� ������ �Լ� ��ü ������ �Ѿ�� �Ѵ�.


	return 0;
}