#pragma once

/*
�պ�����(Merge)
���� ���� ��� : ū ������ �ɰ��� ������ �ذ��� ������ ���.
������ �迭�� ũ�Ⱑ 1���� �۰ų� ������ ���� �ݺ�.

�պ��� �ΰ��� �迭�� ���Ͽ�, ���ؿ� �´� ���� �ٸ� �迭�� ������ ������.
���������� ��� �迭 A, �迭 B�� ���Ͽ� A�� �մ°��� �� �۴ٸ�
�� �迭�� �������ְ�, A�ε����� ���� ��Ų�� A, B �ݺ��� �����Ѵ�.
�̴� A�� B�� �ϳ��� ��� �迭������ �� �迭�� ������ �� ���� �ݺ��ϸ�,
���δ� �������� ���� ������ ��� �� �迭�� ���� �������ش�.

���� ����.
1. ���� �迭�� ������ �ɰ�. �迭�� ���� ��ġ��, ���� ��ġ�� �޾Ƽ� 
���� ������ 2�� ������ �� ��ġ�� �������� ������.
2. �̸� �ɰ� �迭�� ũ�Ⱑ 0�̰ų� 1�϶����� �ݺ�.

�պ� ����
1. �� �迭 A, B�� ũ�⸦ ��. ���� �迭�� ���� �ε����� i, j�� ����.
2. i���� A�迭�� ���� �ε����� �����ϰ� j���� B�迭�� ���� �ε����� ����.
3. A[i]�� B[j]�� ��, ���������� ��� ���߿� ���� ���� �� �迭 C�� ����.
A[i]�� �� �Ǵٸ�, A[i]�� ���� �迭 C�� �������ְ�, i�� ���� �ϳ� ������Ų��.
4. �̸� i�� j���� �ϳ��� ���� �迭�� ���� ������ �� ���� �ݺ�.
5. ������ ������ ���� �迭�� ���� ������� C�� ����.
6. C�迭�� ������ �迭�� ����.
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

