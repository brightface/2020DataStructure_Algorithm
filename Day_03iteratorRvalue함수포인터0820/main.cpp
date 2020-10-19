#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
	/* 
		iterator( 반복자 )
		컨테이너의 한 지점을 가리키는 객체.
	*/

	// vector<int> vec;
	// list<int> l;

	// vector 나 list 나 begin, end 는 동일하게 적용된다. ( 모든 컨테이너가 사용가능 )

	// vec.begin();		
	// l.begin(); 		

	// vec.end();
	// l.end();
	
	/*
		iterator 를 이용하여 해당 컨테이너의 데이터에 접근하기 위해서 사용한다.
		
		iterator 는 포인터 그 자체가 아니다.
	*/
	
	// Vector 는 물리적으로 연결이 되어있다.
	vector<int>::iterator iter1;
	iter1++;

	// List 같은 경우에는 논리적으로 연결이 되어있다.
	/*list<int>::iterator iter2;
	iter2++;*/

	/*
		iterator 를 사용하는데에 나오는 장점
		-> 내부 구조를 잘 모르더라도 사용이 가능하다.
	*/

	/*	
		InIt( 입력 전용 )  : 오로지 입력만 가능 / 쓰기 불가능	( istream_iterator ) 
		OutIt( 출력 전용 ) : 오로지 출력만 가능 / 읽기 불가능	( ostream_iterator )
		여기서의 입력, 출력은 데이터가 대입이 되느냐 안되느냐이다.

		FwdIt( 정방향 ) : 입출력은 모두 가능하며, 전진만 가능하다 ( ++ 연산자가 정의되어 있다. ) // Queue, Stack 을 예로 들 수 있다.
		BiIt ( 양방향 ) : 앞뒤로 이동가능 ( -- 연산자가 정의되어 있다. ) // 연결 List나 Vector 가 지원이 된다. ( 단 Vector 는 잘 사용하지 않는다. ) 
		RanIt ( Random Access, 임의 접근 ) : vec[3], 순회를 할 필요 없는 컨테이너들만 가지고 있다. // Vector 는 가지고 있으나 List 는 가지고 있지 않음 
	*/ 
	
	// sort 사용법, 람다식 사용
	vector<int> vec;
	sort(vec.begin(), vec.end(), [](const int& a, const int& b)
	{
		return a > b;
	}
	);

	// iter 반복문을 사용한 방법
	vector<int>::iterator iter = vec.begin();
	for (; iter != vec.end(); ++iter)
	{
		cout << *iter << endl;
		// 반복자 무효화
		// 중간에 원소가 비어버리는 것이기 때문에 당겨줘야 한다.
		// iter = vec.erase(iter);	// 당겨주기
	}

	// Map 에도 begin 과 end 가 존재한다.
	map<int, int> m;
	m.begin();
	m.end();


	// Unordered_map

	// Unordered_map 의 순회 방법	
	unordered_map<int, int> um;
	for (pair<int, int> p : um)
		cout << p.second << endl;

	// Unordered_map 도 begin 이 존재한다.
	// 물론 iterator 를 돌릴 수도 있다.
	unordered_map<int, int>::iterator iter3 = um.begin();
	// for (iter3; iter3 != um.end(); ++iter3)
		

	// STL 은 생성자까지는 함수를 공유한다.
	// allocator 에 의해 가능하다.
	vector<int> vec3{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> l2(vec3.begin(), vec3.end());



	return 0;
}