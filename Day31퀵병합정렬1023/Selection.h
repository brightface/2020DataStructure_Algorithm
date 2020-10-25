#pragma once
#include "Timer.h"
/*
Selection
선택 정렬.

현재 위치에 들어갈 값을 찾아가면서 정렬
현재 위치에 저장될 값의 크기가 작냐, 크냐에 따라 최소 선택정렬, 최대 선택정렬로 구분.
최소 선택정렬 오름차순, 최대 선택정렬 내림차순.

기본로직
1. 정렬되지 않은 인덱스의 맨 앞부터, 이를 포함한 그 이후의 배열값 중 가장 작은 값을 탐색
2. 가장 작은값을, 그 값을 현재 인덱스의 값과 스왑.
3. 이걸 반복.

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