#pragma once

#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

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