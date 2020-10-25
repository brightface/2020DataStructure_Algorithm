#pragma once

#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

/*
	함수 인라이닝.
	기계어 레벨에서 함수 호출을 제거하고 그대신 그 자리에 직접 함수의 정의를 대입
	이를 통해 함수 호출 오버헤드를 제거함은 물론, 문맥에 따른 고수준 최적화를 가능하게 해준다.

	/ob 
	0 : 기본값. 인라인 확장 사용 안함.
	1 : __inline, __forceinline, inline 인라인 키워드가 표시된 함수만 확장하거나
	클래스에 선언에 정의된 C++맴버 함수를 확장할수 있음.
	2 : 컴파일러가 인라이닝 되지 않도록 명시적으로 표시되지 않은 모든 함수를
	확장할수 있음
	3 : 2번옵션보다 더 적극적인 인라인화를 시도한다.

	/RTC 컴파일러가 탐지 기능을 삽입해 넣기때문 성능에 영향을 미치는 옵션.
	최적화 옵션을 사용할수 없음.
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