#pragma once

#include "Timer.h"

/*
Insertion
삽입 정렬

현재 위치에서, 그 이하의 배열들을 비교하며 자신이 들어갈 위치를 찾아,
그 위치에 삽입하는 알고리즘.

기본로직.
1. 두번째 인덱스 부터 시작. 현재 인덱스는 별도의 변수에 저장해주고, 비교 인덱스를
현재 인덱스의 -1로 잡는다.
2. 별도로 저장해 둔 삽입을 위한 변수와, 비교 인덱스의 배열값을 비교한다.
3. 삽입 변수의 값이 더 작으면, 현재 인덱스에 비교인덱스에 대입하고 비교 인덱스를 -1하여 비교 반복한다.
4. 만약 삽입 변수가 더 크면, 비교 인덱스 + 1 에 삽입변수를 저장한다.

*/

//3459
void Insertion(int* data, int length)
{
	for (int i = 1; i < length; i++)
	{
		int key = data[i];
		int j = i - 1;
		while (j >= 0 && key < data[j])
		{
			SWAP(int, data[j + 1], data[j]);
			j--;
		}
		data[j + 1] = key;
	}
}