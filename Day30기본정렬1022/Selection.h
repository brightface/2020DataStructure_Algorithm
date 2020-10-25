#pragma once
#include "Timer.h"
/*
선택정렬(selection)
현재 위치에 저장될 값의 크기가 작냐 크냐에 따라서 최소 선택정렬, 최대 선택정렬로 구분.
최소 선택정렬은 오름차순, 최대 선택정렬은 내림차순.

기본로직.
1. 정렬되지 않은 인덱스의 맨 앞부터, 이를 포함한 그 이후의 배열값 중 가장 작은 값을 탐색.
2. 가장 작은값을 찾으면, 그 값을 현재 인덱스와 교환.
3. 다음 인덱스에서 반복.

*/

//5243
void Selection(int* data, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		int t = i;
		for (int j = i + 1; j < length; j++)
			if(data[t] >= data[j])
				t = j;
		SWAP(int, data[i], data[t]);
	}
}