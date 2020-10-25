#pragma once
#include "Timer.h"
/*
Quick sort(������)
pivot�� ����ؼ� �����ϴ� ���
�̰��� �������� �������� ���� ū���� ���������� �ű�� ���

�⺻����.
1.pivot�� ����. �� ���̳� �� �� Ȥ�� �߰����̳� ������ ���������� �����ص� ���x
2.������ �����ϱ� ��, �񱳸� �����ϱ� ���� ���� ���ʹ迭�� �ε����� �����ϴ� left,
���� ������ �ε����� �����ϱ� ���� right ������ ����.
3. right���� �� ����. right�� left���� Ŭ����. ���� �迭���� pivot���� ũ��, 
pivot���� ũ��, right�� ���ҽ�Ű�� �� �ݺ�
4. left ������, right, left���� Ŭ���� �ݺ�, ���� �迭���� pivot���� ������
left�� ������Ű�� �񱳹ݺ�
5. left right �� ����.
6. 3.4.5 �� left<right �����Ҷ����� �ݺ�.
7. 6���� �Ϸ�Ǹ� right���� pivot���� swap
8. �� ���ʺ��� pivot -1���� pivot +1���� ���� ������ ���� ������ �ٽ� ����.
*/

int Partition(int* datas, int left, int right) 
{
	int first = left;
	int pivot = datas[first];
	
	left++;
	while (left <= right)
	{
		//pivot���� �۰ų� �������� ã�������� right ����
		while (datas[right] > pivot &&left <= right) right--;

		//pivot���� ū���� ã��������.
		while (datas[left] <= left && left <= right) left++;
		
		if (left < right)
		{
			//��ũ�δ� ��ȣ�� ������Ѵ�.
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
		int index = Partition(datas, start, end);//index�� �Ǻ�
		QSort(datas, start, index - 1);
		QSort(datas, index + 1, end);
	}
}