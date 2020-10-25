#pragma once
#include "Timer.h"
/*
합병정렬.
분할 정복 방식 : 큰 문제를 쪼개서 문제를 해결해 나가는 방식.
분할은 배열의 크기가 1보다 작거나 같을때까지 반복.

합병은 두개의 배열을 비교하여, 기준에 맞는 값을 다른 배열에 저장해 나간다.
오름차순의 경우 배열 A, 배열 B를 비교하여 A에 잇는 값이 더 작다면
새 배열을 저장해주고, A인덱스를 증가시킨후 A,B 반복을 진행한다.
이는 A나 B중 하나가 모든 배열값들을 새 배열에 저장할 때까지 반복하며,
전부다 저장하지 못한 값들은 모두 새 배열의 값에 저장해준다.

분할 로직.
1. 현재 배열을 반으로 쪼갬. 배열의 시작 위치와, 종료 위치를 받아서
둘을 더한후 2로 나눠서 그 위치를 기준으로 나눈다.
ex)1개 짜리 배열이 쭉 만들어 지겠지.
2. 이를 쪼갠 배열의 크기가 0 이거나 1때까지 반복

합병 로직
1. 두배열 A, B의 크기를 비교, 각각배열의 현재 인덱스를 i,j로 가정.
메모리 배열을 계속 낭비하면서 만들수 없다. 실제적으로 쪼개가지고 함수를 
2. i에는 a배열의 시작 인덱스를 저장하고 j에는 B배열의 시작 인덱스를 저장. 
3. A[i]와 B[j]를 비교해서 오름차순의 경우 이중에 작은 값을 새배열 C에 저장.덮어 씌워서 원본배열에다가 정렬된 배열에 복사해서 넣는다.
A[i]가 더 컸다면, A[i]의 값을 배열 C에 저장해주고, i의값을 하나 증가시킨다.
4. 이를 i나 j둘중 하나가 각자 배열의 끝에 도달할때까지 반복.
5. 끝까지 저장을 못한 배열의 값을 순서대로 c에 저장.
6. c배열을 원래에 배열에 저장.

*/


void Merge(int*data, int start, int end, int middle)
{
	int temp[USHRT_MAX];
	int tempIndex = 0; //삽입할 위치

	int i = start;
	int j = middle + 1;// 뒤의 시작위치.

	while (i <= middle && j <= end)
	{
		if (data[i] < data[j])
			temp[tempIndex++] = data[i++];
		else
			temp[tempIndex++] = data[j++];
	}

	while (i <= middle)
	{
		temp[tempIndex++] = data[i++];
	}
	while (j <= end)
		temp[tempIndex++] = data[j++];

	//원본배열에 저장
	//0부터 채워넣는게 아니다
	for (int k = start, tempIndex = 0; k <= end; k++)
	{
		data[k] = temp[tempIndex++];
	}
}

void MergeSort(int* data, int start, int end)
{	//역전이 안되어있다고 가정을 하고하자.
	if (start < end)
	{
		int middle = (start + end) / 2;
		MergeSort(data, start, middle);
		MergeSort(data, middle + 1, end);
		Merge(data, start, end,middle);
	}
}