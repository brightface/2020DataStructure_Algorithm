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
		iterator( �ݺ��� )
		�����̳��� �� ������ ����Ű�� ��ü.
	*/

	// vector<int> vec;
	// list<int> l;

	// vector �� list �� begin, end �� �����ϰ� ����ȴ�. ( ��� �����̳ʰ� ��밡�� )

	// vec.begin();		
	// l.begin(); 		

	// vec.end();
	// l.end();
	
	/*
		iterator �� �̿��Ͽ� �ش� �����̳��� �����Ϳ� �����ϱ� ���ؼ� ����Ѵ�.
		
		iterator �� ������ �� ��ü�� �ƴϴ�.
	*/
	
	// Vector �� ���������� ������ �Ǿ��ִ�.
	vector<int>::iterator iter1;
	iter1++;

	// List ���� ��쿡�� �������� ������ �Ǿ��ִ�.
	/*list<int>::iterator iter2;
	iter2++;*/

	/*
		iterator �� ����ϴµ��� ������ ����
		-> ���� ������ �� �𸣴��� ����� �����ϴ�.
	*/

	/*	
		InIt( �Է� ���� )  : ������ �Է¸� ���� / ���� �Ұ���	( istream_iterator ) 
		OutIt( ��� ���� ) : ������ ��¸� ���� / �б� �Ұ���	( ostream_iterator )
		���⼭�� �Է�, ����� �����Ͱ� ������ �Ǵ��� �ȵǴ����̴�.

		FwdIt( ������ ) : ������� ��� �����ϸ�, ������ �����ϴ� ( ++ �����ڰ� ���ǵǾ� �ִ�. ) // Queue, Stack �� ���� �� �� �ִ�.
		BiIt ( ����� ) : �յڷ� �̵����� ( -- �����ڰ� ���ǵǾ� �ִ�. ) // ���� List�� Vector �� ������ �ȴ�. ( �� Vector �� �� ������� �ʴ´�. ) 
		RanIt ( Random Access, ���� ���� ) : vec[3], ��ȸ�� �� �ʿ� ���� �����̳ʵ鸸 ������ �ִ�. // Vector �� ������ ������ List �� ������ ���� ���� 
	*/ 
	
	// sort ����, ���ٽ� ���
	vector<int> vec;
	sort(vec.begin(), vec.end(), [](const int& a, const int& b)
	{
		return a > b;
	}
	);

	// iter �ݺ����� ����� ���
	vector<int>::iterator iter = vec.begin();
	for (; iter != vec.end(); ++iter)
	{
		cout << *iter << endl;
		// �ݺ��� ��ȿȭ
		// �߰��� ���Ұ� �������� ���̱� ������ ������ �Ѵ�.
		// iter = vec.erase(iter);	// ����ֱ�
	}

	// Map ���� begin �� end �� �����Ѵ�.
	map<int, int> m;
	m.begin();
	m.end();


	// Unordered_map

	// Unordered_map �� ��ȸ ���	
	unordered_map<int, int> um;
	for (pair<int, int> p : um)
		cout << p.second << endl;

	// Unordered_map �� begin �� �����Ѵ�.
	// ���� iterator �� ���� ���� �ִ�.
	unordered_map<int, int>::iterator iter3 = um.begin();
	// for (iter3; iter3 != um.end(); ++iter3)
		

	// STL �� �����ڱ����� �Լ��� �����Ѵ�.
	// allocator �� ���� �����ϴ�.
	vector<int> vec3{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> l2(vec3.begin(), vec3.end());



	return 0;
}