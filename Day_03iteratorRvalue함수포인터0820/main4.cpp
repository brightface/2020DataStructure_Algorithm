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
		cout << "멤버 함수" << endl;
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
		cout << "스태틱" << endl;
	}

private:
	int value;

};

int main()
{
	TClass t(10);
	function<void(TClass&)> fp1 = &TClass::TestFunction;	// 객체 정보를 넘겨주어야 한다.
	function<void()> fp2 = &TClass::StaticFunction;			// Static 함수는 쉽게 가능
	fp1(t);
	
	function<void()> fp3 = bind(&TClass::TestFunction, t);	// 객체 정보를 고정시키면 객체 정보가 함수 포인터 안에 들어가게 된다.
	// 매개변수를 계속 원하는 만큼 넣는 명칭을 가변인자라고 한다.

	function<void(int)> fp4 = bind(&TClass::TestFunction2, t, placeholders::_1);
	// 가변 인자를 계속 받는 bind, 중간에 t 는 객체 정보를 고정시키기 위해 사용하였다.

	// placeholders 의 순서에는 의미가 있다는 점을 기억하자.
	// 뒤집어 놓으면 값이 들어가는 순서가 뒤바뀌는 것이다.
	function<void(int, int)> fp5 = bind(&TClass::TestFunction3, t, placeholders::_1, placeholders::_2);
	// fp5(10, 20);

	// 이 방식은 매개변수의 값을 고정하고 싶을 때 이런식으로 사용할 수 있다.
	function<void(int)> fp6 = bind(&TClass::TestFunction3, t, placeholders::_1, 20);
	fp6(10);

	// 함수 포인터를 사용할 때에는 함수 객체 정보가 넘어가야 한다.


	return 0;
}