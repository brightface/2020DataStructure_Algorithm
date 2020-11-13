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
			cout << i << "��°���� ã��" << endl;
	}
}

/*
KMP �˰���
�ð� ���⵵�� O(m + n)���� �ſ� ������.
���λ�� ���̻��� ������ Ȱ���ؼ� �ݺ��Ǵ� ������ �󸶳�
���ϼ� �ִ����� �Ǻ��Ͽ� ��Ī�� ���ڿ��� ������ �����ϴ� ����̴�.

banana
���λ�?
b
ba
ban
bana
banan
banana
�� 6���� ���λ�(prefix)�̴�.

���̻�?
a
na
ana
nana
anana
banana
�� 6���� ���̻�(suffix)�̴�.

�츮�� ���ؾ��� ���� �ڱ��ڽ��� ���ڿ��� �����ϰ� 
���λ�� ���̻簡 ���� ���ڿ� �� ���� �� ���� ����

ABAABAB

table[0]
�ε��� 0 : ���ڿ� ("A")�� ���λ�� ���̻簡 �ڱ� �ڽ��̱� ������ ���� 0

�ε��� 1: ���λ簡 "A"/ "AB", ���̻簡 "B", "AB" / ���λ�� ���̻簡 �������� 
���� ������ ���� 0

�ε��� 2("ABA") :  ���λ� "A" / "AB" / "ABA" / ���̻� "A" / "BA" / "ABA"
���� 1("A")

�ε��� 3("ABAA") :
	���λ� : "A", "AB", "ABA", "ABAA"
	���̻� : "A", "AA", "BAA", "ABAA"
���� 1("A")

�ε��� 4("ABAAB")
	���λ� : "A", "AB", "ABA", "ABAA", "ABAAB"
	���̻� : "B", "AB", "AAB", "BAAB", "ABAAB"
���� 2("AB")
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
				cout << i - pattern.size() + 1 << "��°���� ã��" << endl;
				j = table[j];
			}
			else
				j++;
		}
	}
}