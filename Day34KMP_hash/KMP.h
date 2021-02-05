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
				//���� �ʴٸ� false�� �����. �׸��� �ݺ��� ����.
				bMatched = false;
				break;
			}
		}//true�� ã�Ҵ�.
		if (bMatched == true)
			cout << i << "��°���� ã��" << endl;
	}
}//�׳� ã�� �˰���.(kmp�ƴ�)

/*
KMP �˰���.
�ð����⵵ O(m + n)
���λ�� ���̻��� ������ Ȱ���ؼ� �ݺ��Ǵ� ������ 
�󸶳� ���ϼ� �ִ����� �Ǻ��ؼ� ��Ī�� ���ڿ��� ������ �����ϴ� ���.

Banana
���λ� (prefix)
b
ba
ban
bana
banan
banana

���̻� (suffix)
a
na
ana
nana
anana
banana

�ڱ� �ڽ��� ���ڿ��� �����ϰ�, ���λ�� ���̻簡 ���� ���ڿ� ��
���� �� ���� ���̸� ����ؾ���.

ABAABAB
vector<int> table;
table[0] "A"
	- ���λ� : "A"
	- ���̻� : "A"
	- ���� 0

table[1] "AB"
	- ���λ� : "A", "AB"
	- ���̻� : "B", "AB"
	- ���� 0

table[2] "ABA"
	- ���λ� : "A", "AB", "ABA"
	- ���̻� : "A", "BA", "ABA"
	- ���� 1

table[3] "ABAA"
	- ���λ� : "A", "AB", "ABA", "ABAA"
	- ���̻� : "A", "AA", "BAA", "ABAA"
	- ���� 1 

table[4] "ABAAB"
	- ���λ� : "A", "AB", "ABA", "ABAA", "ABAAB"
	- ���̻� : "B", "AB", "AAB", "BAAB", "ABAAB"
	- ���� 2
*/

#include <vector>

vector<int> MakeTable(string pattern)
{
	vector<int> table(pattern.size(), 0);

	int j = 0;
	for (int i = 1; i < pattern.size(); i++)
	{
		//j�� ó���� 0�̶� �׳� �Ѿ.
		while (j > 0 && pattern[i] != pattern[j]) //���� ������ �ٽ� j-1�� 0�� �Ǿ� table[0] = 1 �� �ȴ�. ���� ������ table[1]=2 ���ǰ�
			j = table[j - 1];
		//ó���� j�� 0, i�� 1�̴�. ������ j�� 1�ȴ�.
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
				cout << i - pattern.size() + 1 << "��°���� ã��" << endl;
			}
			else
				j++;
		}
	}
}