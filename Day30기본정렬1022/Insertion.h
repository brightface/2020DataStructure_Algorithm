#pragma once

#include "Timer.h"

/*
삽입 정렬(Insertion)
현재 위치에서, 그 이하의 배열들을 비교해 가며 자신이 들어갈 위치를 찾아서 
그 위치에 삽입하는 정렬 알고리즘.

기본로직.
1. 두번째 인덱스부터 시작. 현재 인덱스는 별도의 변수에 저장해놓고, 비교 인덱스를 현재 
인덷스의 -1로 잡는다.
2. 별도로 저장해 둔 삽입을 위한 변수와, 비교 인덱스의 배열값을 비교.
3. 삽입 변수의 값이 더 작으면 현재 인덱스에 비교 인덱스의 값을 저장해주고, 
비교 인덱스를 -1하여 비교를 계속한다.
4. 만약 삽입  변수가 더 크면, 비교 인덱스의 + 1 에 삽입 변수를 저장한다.

*/

//3518
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