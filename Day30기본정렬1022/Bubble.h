#pragma once
#include "Timer.h"
/*
삽입, 퀵, 버블, 선택, 병합

버블 정렬(Bubble)
매번 연속된 두개의 인덱스를 비교하여, 정한 기준의 값을 뒤로 넘겨서 정렬하는 방법.
오름차순으로 정렬하고 할 떄, 비교시마다 큰 값이 뒤로 이동하여, 1바퀴 돌때 가장 큰 값이 맨 뒤에 저장이 된다.
맨 마지막에는 비교하는 수들 중 가장 큰 값이 저장이 되기 때문에,
전체 배열의 크기 - 현재까지 순회한 바퀴수 만큼만 반복해주면 된다.

기본로직.
1. 두번째 인덱스 부터 시작한다. 현재 인덱스 값과, 바로 이전의 인덱스 값을 비교.
2. 만약 이전 인덱스 가 더 크면, 현재 인덱스와 바꿔준다.
3. 현재 인덱스가 더 크면, 교환하지 않고 다음 두 연속된 배열값을 비교한다.
4. 전체 배열의 크기 - 현재까지 순환한 바퀴수 만큼 반복.

*/

void Bubble(int* data, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 1; j < length - i; j++)
		{
			if (data[j - 1] > data[j])
			{
				/*
					1. 알고리즘에 있는 swap 95.394
					2. 직접 swap함수 구현 30.831, inline : 36373, inline-On 6318
					3. 여기다 그냥 씀 11.072
					4. 매크로 11.255, vec : 11380
				*/
				/*int temp = data[j - 1];
				data[j - 1] = data[j];
				data[j] = temp;*/
				//Swap(data[j - 1], data[j]);
				SWAP(int, data[j - 1], data[j]);
				//swap(data[j - 1], data[j]);
			}
		}
	}
}

void Bubble(vector<int>& data)
{
	//65534 * (65535 - i)
	//4,294,770,690 - (65534i)
	for (int i = 0; i < data.size() - 1; i++)//USHRT_MAX - 1 * USHRT_MAX - i;
	{
		for (int j = 1; j < data.size() - i; j++)
		{
			if (data[j - 1] > data[j])
			{
				//swap(data[j - 1], data[j]);
				SWAP(int, data[j - 1], data[j]);
			}
		}
	}
}