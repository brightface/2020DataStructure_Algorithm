#pragma once

#include <iostream>
using namespace std;

void FindString(string parent, string pattern)
{
	for (int i = 0; i + pattern.size() <= parent.size(); ++i)
	{
		bool bMatched = true;
		for (int j = 0; j < pattern.size(); j++)
		{
			if (parent[i + j] != pattern[j])
			{
				bMatched = false;
				break;
			}
		}
		if (bMatched == true)
			cout << i << "번째에서 찾음" << endl;
	}
}

/*
KMP 알고리즘
시간 복잡도는 O(m + n)으로 매우 빠르다.
접두사와 접미사의 개념을 활용해서 반복되는 연산을 얼마나
줄일수 있는지를 판별하여 매칭할 문자열을 빠르게 점프하는 기법이다.

banana
접두사?
b
ba
ban
bana
banan
banana
이 6개가 접두사(prefix)이다.

접미사?
a
na
ana
nana
anana
banana
이 6개가 접미사(suffix)이다.

우리가 구해야할 것은 자기자신의 문자열을 제외하고 
접두사와 접미사가 같은 문자열 중 가장 긴 것의 길이

ABAABAB

table[0]
인덱스 0 : 문자열 ("A")은 접두사와 접미사가 자기 자신이기 때문에 값은 0

인덱스 1: 접두사가 "A"/ "AB", 접미사가 "B", "AB" / 접두사와 접미사가 같은것이 
없기 때문에 값은 0

인덱스 2("ABA") :  접두사 "A" / "AB" / "ABA" / 접미사 "A" / "BA" / "ABA"
값은 1("A")

인덱스 3("ABAA") :
	접두사 : "A", "AB", "ABA", "ABAA"
	접미사 : "A", "AA", "BAA", "ABAA"
값은 1("A")

인덱스 4("ABAAB")
	접두사 : "A", "AB", "ABA", "ABAA", "ABAAB"
	접미사 : "B", "AB", "AAB", "BAAB", "ABAAB"
값은 2("AB")
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> MakeTable(string pattern)
{
	vector<int> table(pattern.size());

	int j = 0;
	for (int i = 1; i < pattern.size(); i++)
	{
		while (j > 0 && pattern[i] != pattern[j])
			j = table[j - 1];

		if (pattern[i] == pattern[j])
			table[i] = ++j;
	}

	return table;
}

void KMP(string parent, string pattern)
{
	vector<int> table = MakeTable(pattern);

	int j = 0;
	for (int i = 0; i < parent.size(); i++)
	{
		//"ABCAABACBABA";
		//    AABAA
		//	   ABAA
		//      
		// 0 1 0 1 2
		while (j > 0 && parent[i] != pattern[j])
			j = table[j - 1];

		if (parent[i] == pattern[j])
		{
			if (j == pattern.size() - 1)
			{
				cout << i - pattern.size() + 1 << "번째에서 찾음" << endl;
				j = table[j];
			}
			else
				j++;
		}
	}
}