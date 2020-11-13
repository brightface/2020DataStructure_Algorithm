#pragma once
#include "Timer.h"
/*
Selection
���� ����.

���� ��ġ�� �� ���� ã�ư��鼭 ����
���� ��ġ�� ����� ���� ũ�Ⱑ �۳�, ũ�Ŀ� ���� �ּ� ��������, �ִ� �������ķ� ����.
�ּ� �������� ��������, �ִ� �������� ��������.

�⺻����
1. ���ĵ��� ���� �ε����� �� �պ���, �̸� ������ �� ������ �迭�� �� ���� ���� ���� Ž��
2. ���� ��������, �� ���� ���� �ε����� ���� ����.
3. �̰� �ݺ�.

*/

void Selection(vector<int>& data)
{
	for (int i = 0; i < data.size() - 1; i++)
	{
		int temp = i;
		for (int j = i + 1; j < data.size(); j++)
			if (data[temp] >= data[j])
				temp = j;

		SWAP(int, data[i], data[temp]);
	}
}

//4939
void Selection(int* data, int length)
{
	int t;
	for (int i = 0; i < length - 1; i++)
	{
		t = i;
		for (int j = i + 1; j < length; j++)
			if (data[t] >= data[j])
				t = j;

		SWAP(int, data[i], data[t]);
	}
}