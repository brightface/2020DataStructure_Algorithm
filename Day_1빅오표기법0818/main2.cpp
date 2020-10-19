/*
	빅오 표기법.
	알고리즘을 평가하는데 있어서 해당 알고리즘이 얼마나
	효과적인가를 수학적으로 표기하는 방법.

	알고리즘이란.
	알고리즘은 어떤 목적을 달성하거나 결과물을 만들어 내기
	위해 거쳐야 하는 일련의 과정.

	시간 복잡도(Time Complexity) 
	-> 알고리즘이 문제를 해결하기 위한 연산 횟수를 의미한다.
	공간 복잡도(Space Complexity)

	빅오, 빅오메가, 빅세타.
	빅오 : 해당 알고리즘이 최소한 빅오로 표현된 시간보다는 빠르다.
	빅오메가 : 해당 알고리즘이 빨라봐야 빅오메가로 표현된 시간보다는 느리다.
	빅세타 : 해당 알고리즘이 빅오로 표현된 시간보다는 빠르고 오메가로 표현된 시간보다는 느리다.

	1. O(1) : 상수 시간 복잡도
	2. O(log(n)) : 로그 시간 복잡도
	3. O(n) : 선형 시간 복잡도
	4. O(n log(n)) : 선형 로그 시간 복잡도
	5. O(n^2) : 2차 시간 복잡도
	6. O(n^3) : 3차 시간 복잡도
	7. O(c^n) : 지수 시간 복잡도
*/

void Func1(int n)
{
	//상수시간
	int a = 10;//O(1)
	if (a != 10)//O(1)
	{
		int b = 10;//O(1)
	}
	// 3 * O(1)
	//-> O(1)
}

//로그 시간복잡도.
//일반적으로 커다란 문제를 일정한 크기를 갖는 작은
//문제로 쪼갤때 나타나는 유형.
//이진탐색
bool BinarySearch(int* arr, int len, int key)
{
	int start = 0;
	int end = len - 1;
	int mid = 0;

	while (end - start >= 0)
	{
		mid = (start + end) / 2;

		if (arr[mid] == key)
			return true;
		else if (arr[mid] > key)
			end = mid - 1;
		else
			start = mid + 1;
	}

	/*
		n : 탐색해야 할 데이터 개수
		k : 시행 회수
		n / 2^k = 1;
		-> n = 2^k
		-> log(n) = k;
	*/

	//for(int i = 0 ; i < n; i *= i)
}

//선형 시간복잡도
void Func3(int n)
{
	for (int i = 0; i < n; i++) //O(n)
		int a = 10;//O(1)

	//O(n) + O(n)
	//O(n)
}