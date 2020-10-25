#pragma once

#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

/*
	�Լ� �ζ��̴�.
	���� �������� �Լ� ȣ���� �����ϰ� �״�� �� �ڸ��� ���� �Լ��� ���Ǹ� ����
	�̸� ���� �Լ� ȣ�� ������带 �������� ����, ���ƿ� ���� ����� ����ȭ�� �����ϰ� ���ش�.

	/ob 
	0 : �⺻��. �ζ��� Ȯ�� ��� ����.
	1 : __inline, __forceinline, inline �ζ��� Ű���尡 ǥ�õ� �Լ��� Ȯ���ϰų�
	Ŭ������ ���� ���ǵ� C++�ɹ� �Լ��� Ȯ���Ҽ� ����.
	2 : �����Ϸ��� �ζ��̴� ���� �ʵ��� ��������� ǥ�õ��� ���� ��� �Լ���
	Ȯ���Ҽ� ����
	3 : 2���ɼǺ��� �� �������� �ζ���ȭ�� �õ��Ѵ�.

	/RTC �����Ϸ��� Ž�� ����� ������ �ֱ⶧�� ���ɿ� ������ ��ġ�� �ɼ�.
	����ȭ �ɼ��� ����Ҽ� ����.
*/

inline void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

#define SWAP(T, a, b) { T temp = a; a = b; b = temp; }

void ReadDatas(int* datas)
{
	FILE* file;
	fopen_s(&file, "RandData.txt", "r");
	{
		for (UINT i = 0; i < USHRT_MAX; i++)
			fscanf_s(file, "%d", &datas[i]);
	}
	fclose(file);
}

void ReadDatas(vector<int>& datas)
{
	FILE* file;
	fopen_s(&file, "RandData.txt", "r");
	{
		for (UINT i = 0; i < USHRT_MAX; i++)
			fscanf_s(file, "%d", &datas[i]);
	}
	fclose(file);
}

class Timer
{
public:
	Timer()
	{
		QueryPerformanceFrequency((LARGE_INTEGER*)&tick);
	}

	void Start()
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&start);
	}

	float End()
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&end);
		return (float)((double)(end - start) / tick * 1000);
	}

private:
	__int64 tick;
	__int64 start, end;
};