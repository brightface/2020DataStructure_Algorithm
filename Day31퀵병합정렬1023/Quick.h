#pragma once

/*
Quick sort(퀵정렬)

pivot을 사용해서 정렬하는 방식.
이 값을 기준으로 작은값은 왼쪽, 큰값은 오른쪽으로 옮기는 방식.

기본로직.
1. pivot을 설정. 맨 앞이나 맨 뒤 혹은 중간값이나 심지어 랜덤값으로 설정해도 상관x
2. 분할을 진행하기 전, 비교를 진행하기 위해 가장 왼쪽 배열의 인덱스를 저장하는 left,
가장 오른쪽 인덱스를 저장하기 위한 right변수를 생성.
3. right부터 비교 진행. right가 left보다 클때만 반복. 비교한 배열값이
pivot보다 크면, right를 감소시키고 비교 반복.
4. left비교 진행. right left보다 클때만 반복. 비교한 배열값이 pivot보다 작으면
left를 증가시키고 비교 반복.
5. left right 스왑
6. 3,4,5 left < right 을 만족할때까지 반복.
7. 6번이 완료되면 right값과 pivot 스왑.
8. 맨 왼쪽부터 pivot -1까지, pivot + 1부터 제일 오른쪽까지로 나눠서 다시 진행.
*/

int Partition(int* datas, int left, int right)
{
	int first = left;
	int pivot = datas[first];

	left++;
	while (left <= right)
	{
		//pivot보다 작거나 같은값을 찾을때까지 right 감소
		while (datas[right] > pivot && left <= right)
			right--;

		//pivot보다 큰값을 찾을때까지 left증가
		while (datas[left] <= pivot && left <= right)
			left++;

		if (left < right)
		{
			SWAP(int, datas[left], datas[right]);
		}
		else
			break;
	}
	SWAP(int, datas[first], datas[right]);
	return right;
}

void QSort(int* datas, int start, int end)
{
	if (start < end)
	{
		int index = Partition(datas, start, end);
		QSort(datas, start, index - 1);
		QSort(datas, index + 1, end);
	}
}