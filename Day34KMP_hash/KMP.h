#pragma once

/*
KMP.h

*/

#include <iostream>
using namespace std;

//O(parent.size() * pattern.size())
//O(m * n)
//parent -> 1000000
//pattern -> 5
void FindString(string parent, string pattern)
{
	for (int i = 0; i + pattern.size() <= parent.size(); ++i)
	{
		bool bMatched = true;
		for (int j = 0; j < pattern.size(); j++)
		{
			if (parent[i + j] != pattern[j])
			{
				//같지 않다면 false로 만든다. 그리고 반복문 나가.
				bMatched = false;
				break;
			}
		}//true면 찾았다.
		if (bMatched == true)
			cout << i << "번째에서 찾음" << endl;
	}
}//그냥 찾는 알고리즘.(kmp아님)

/*
KMP 알고리즘.
시간복잡도 O(m + n)
접두사와 접미사의 개념을 활용해서 반복되는 연산을 
얼마나 줄일수 있는지를 판별해서 매칭할 문자열을 빠르게 점프하는 기법.

Banana
접두사 (prefix)
b
ba
ban
bana
banan
banana

접미사 (suffix)
a
na
ana
nana
anana
banana

자기 자신의 문자열을 제외하고, 접두사와 접미사가 같은 문자열 중
가장 긴 것의 길이를 계산해야함.

ABAABAB
vector<int> table;
table[0] "A"
	- 접두사 : "A"
	- 접미사 : "A"
	- 값은 0

table[1] "AB"
	- 접두사 : "A", "AB"
	- 접미사 : "B", "AB"
	- 값은 0

table[2] "ABA"
	- 접두사 : "A", "AB", "ABA"
	- 접미사 : "A", "BA", "ABA"
	- 값은 1

table[3] "ABAA"
	- 접두사 : "A", "AB", "ABA", "ABAA"
	- 접미사 : "A", "AA", "BAA", "ABAA"
	- 값은 1 

table[4] "ABAAB"
	- 접두사 : "A", "AB", "ABA", "ABAA", "ABAAB"
	- 접미사 : "B", "AB", "AAB", "BAAB", "ABAAB"
	- 값은 2
*/

#include <vector>

vector<int> MakeTable(string pattern)
{
	vector<int> table(pattern.size(), 0);

	int j = 0;
	for (int i = 1; i < pattern.size(); i++)
	{
		//j가 처음은 0이라 그냥 넘어감.
		while (j > 0 && pattern[i] != pattern[j]) //같지 않으면 다시 j-1이 0이 되어 table[0] = 1 이 된다. 만약 같으면 table[1]=2 가되고
			j = table[j - 1];
		//처음은 j가 0, i가 1이다. 같으면 j가 1된다.
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
		while (j > 0 && parent[i] != pattern[j])
			j = table[j - 1];

		if (parent[i] == pattern[j])
		{
			if (j == pattern.size() - 1)
			{
				cout << i - pattern.size() + 1 << "번째에서 찾음" << endl;
			}
			else
				j++;
		}
	}
}