#pragma once

/*
합병정렬(Merge)
분할 정복 방식 : 큰 문제를 쪼개서 문제를 해결해 나가는 방식.
분할은 배열의 크기가 1보다 작거나 같을떄 까지 반복.

합병은 두개의 배열을 비교하여, 기준에 맞는 값을 다른 배열에 저장해 나간다.
오름차순의 경우 배열 A, 배열 B를 비교하여 A에 잇는값이 더 작다면
새 배열에 저장해주고, A인덱스를 증가 시킨후 A, B 반복을 진행한다.
이는 A나 B중 하나가 모든 배열값들을 새 배열에 저장할 때 까지 반복하며,
전부다 저장하지 못한 값들은 모두 새 배열의 값에 저장해준다.

분할 로직.
1. 현재 배열을 반으로 쪼갬. 배열의 시작 위치와, 종료 위치를 받아서 
둘을 더한후 2로 나눠서 그 위치를 기준으로 나눈다.
2. 이를 쪼갠 배열의 크기가 0이거나 1일때까지 반복.

합병 로직
1. 두 배열 A, B의 크기를 비교. 각각 배열의 현재 인덱스를 i, j로 가정.
2. i에는 A배열의 시작 인덱스를 저장하고 j에는 B배열의 시작 인덱스를 저장.
3. A[i]와 B[j]를 비교, 오름차순의 경우 이중에 작은 값을 새 배열 C에 저장.
A[i]가 더 컸다면, A[i]의 값을 배열 C에 저장해주고, i의 값을 하나 증가시킨다.
4. 이를 i나 j둘중 하나가 각자 배열의 끝에 도달할 때 까지 반복.
5. 끝가지 저장을 못한 배열의 값을 순서대로 C에 저장.
6. C배열을 원래의 배열에 저장.
*/

void Merge(int* data, int start, int end, int middle)
{
	int temp[USHRT_MAX];
	int tempIndex = 0;

	int i = start;
	int j = middle + 1;

	while (i <= middle && j <= end)
	{
		if (data[i] < data[j])
			temp[tempIndex++] = data[i++];
		else
			temp[tempIndex++] = data[j++];
	}

	while (i <= middle)
		temp[tempIndex++] = data[i++];
	while (j <= end)
		temp[tempIndex++] = data[j++];

	for (int k = start, tempIndex = 0; k <= end; k++)
		data[k] = temp[tempIndex++];
}

void MergeSort(int* data, int start, int end)
{
	if (start < end)
	{
		int middle = (start + end) / 2;
		MergeSort(data, start, middle);
		MergeSort(data, middle + 1, end);
		Merge(data, start, end, middle);
	}
}

