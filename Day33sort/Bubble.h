#pragma once

/*
Bubble.h

매번 연속된 두개의 인덱스를 비교하여, 정한 기준의 값을 뒤로 넘겨서 정렬 방법
오름차순으로 정렬하고싶은 경우, 비교시마다 큰 값이 이동하여, 1바퀴 돌 시 가장 큰값이
맨 마지막에 저장된다.
맨 마지막에는 비교하는 수들 중 가장 큰값이 저장되기 때문에, 
전체 배열의 크기 - 현재까지 순회한 바퀴수 만큼 반복해주면 된다.

기본로직.
1. 두번쨰 인덱스부터 시작. 현재 인덱스 값과, 바로 이전의 인덱스 값을 비교한다.
2. 만약 이전 인덱스가 더 크면, 현재 인덱스와 바꿔준다.
3. 현재 인덱스가 더 크면, 교환하지 않고 다음 두 연속된 배열값을 비교한다.
4. 전체 배열의 크기 - 현재까지 순환환 바퀴수 만큼 반복.

*/

/*
함수 인라이닝.
기계어 레벨에서 함수 호출을 제거하고 그대신 그 자리에 직접 함수의 정의를 대입하는 작업.
이를 통해 함수호출 오버헤드를 제거함은 물론, 문맥에 따른 고수준의 최적화를 가능하게 해준다.

/ob
0. 기본값. 인라인 확장 사용 안함.
1. inline, __inline, __forceinline표시된 함수만 확장하거나 클래스 선언에
정의된 c++ 맴버 함수를 확장할수 있음.
2. 컴퍼일러가 인라이닝 되지 않도록 명시적으로 표시 되지않은 모든 함수를 확장할수 있다.
3. 2번옵션보다 더 적극적인 인라인 함수 확장을 할수 있지만. 2019부터

/rtc 컴파일러가 탐지기능을 삽입해 넣기 때문에 성능이 더 느려진다.
*/



inline void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void BubbleSort(int* data, int length)
{
	for (int i = 0; i < length - 1; i++) //65534
	{
		for (int j = 1; j < length - i; j++) //65534 - i
		{
			if (data[j - 1] > data[j])
			{
				/*
					1. 스왑하는 함수 만들어서 호출 //37114
					2. 알고리즘 헤더의 swap 호출 //95838
					3. 그냥 여기서 swap //11294
					4. 매크로 //11158
				*/
				/*int temp = data[j - 1];
				data[j - 1] = data[j];
				data[j] = temp;*/
				//Swap(data[j - 1], data[j]);
				//swap(data[j - 1], data[j]);
				SWAP(int, data[j - 1], data[j]);
			}
		}
	}
}

void BubbleSort(vector<int>& data, int length)
{
	for (int i = 0; i < data.size() - 1; i++)
	{
		for (int j = 1; j < data.size() - i; j++)
		{
			if (data[j - 1] > data[j])
			{
				/*
					1. 스왑하는 함수 만들어서 호출 //37114
					2. 알고리즘 헤더의 swap 호출 //95838
					3. 그냥 여기서 swap //11294
					4. 매크로 //11158
				*/
				/*int temp = data[j - 1];
				data[j - 1] = data[j];
				data[j] = temp;*/
				//Swap(data[j - 1], data[j]);
				//swap(data[j - 1], data[j]);
				SWAP(int, data[j - 1], data[j]);
			}
		}
	}
}