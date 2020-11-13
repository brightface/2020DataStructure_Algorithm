﻿/*
동적 계획법(dynamic programming)
DP 
분할 정복법
백트래킹
탐욕

어떤 유형의 알고리즘 문제를 어떻게 풀어야하는지
수능보고 문제 유형 어떻게 풀어야하는거구나. 반복을 해봐야하는거지.
고민을 해보다보면 시간이 부족하다. 많이 풀어봐야한다.

처음에는 동적 계획법 잘 짜여진 보니까 대략적으로 4가지로 분류가 되더라.
디자인 패턴. 잘짜여진 프로그램 보니까 이렇게 정리가 되더라. 알고리즘 자체에 대해서 이야기를 한것이다.

동적계획법. 
큰문제를 작은 문제로 나누어서 푸는방식

분할정복.
몇가지 조건이 있다.

동적 계획법의 조건.
1. 겹치는 부분문제
	피보나치 문제 :
	겹치는 부분문제는 어떤 문제가 여러개의 부분문제로 쪼개질수 있을때 사용하는 용어. 
	F(n) = F(n -1) + F(n -2 )
	F(5) = F(4) + F(3)
	
	f(4) = F(3) + f(2)
	f(3) = f(2) + f(1)

	//이식이 동적 계획법이다. 저번에 했을떄 합병정렬. 겹치는 부분문제.
	//이때 항상 새로운 부분문제를 생성해 내기 보다는 계속해서 같은 부분문제가 여러번 재사용 되거나 
	재귀 알고리즘을 통해 해결되는 문제를 뜻한다. 

	겹치는 부분 문제가 있다면, 큰 문제는 작은 문제들을 통해서 정답을 구할수 있다. 작은 문제들을 풀어나가다 보면 큰문제를 풀수가 있다.

2. 최적 부분구조.
	어떤 문제의 최적의 해결책이 그 부분문제의 최적의 해결책으로 부터 설계 될수 있는 경우.

	ex) 서울에서 부산을 가는 가장 빠른 길이 대전과 대구를 순서대로 거쳐야 한다면...
	서울 - 대전 - 대구 - 부산 알고있는 최단경로. 
	대전에서 부산으로 가는 최단경로는
	대전 - 대구 - 부산
	
	가장 빠른 경로가 서울 - 대전 - 울산 - 부산
	대전에서 부산까지의 최단경로
	대전 - 울산 - 부산.

	최적 부분 구조일때 문제의 정답을 작은 문제의 정답으로 부터 구할 수 있다.

	10번째 피보나치 수를 구하면서 구한 4번째 피보나치수 .
	9번째 피보나치 수를 구하면서 구한 4번째 피보나치 수.
	8번째도 같겠지 7번째도 같겠지. 
	매번 새로 계산하는게 비효율 적이다. 

	피보나치 시간복잡도 2^
			최적화 해주면 n
	모두 같은데 매번 값을 구하는것이 비효율적이다. 
	그래서 이때 이를 해결할수 있는 방법이 메모리 제이션이다.
	했던 짓을 또 안해도 된다.

	동적 계획법에서는 각 문제를 단 한번만 풀어야 한다.
	저장해 놓은것을 가져오는걸 의미한다.
	중복되는 부분 문제를 여러번 풀지 않는다.
	최적 부분구조를 만족하기 때문에 같은 문제는
	구할때 마다 정답이 같으므로, 정답을 한 번 구했으면
	그 정답을 캐시에 메모해 놓는다.( 캐쉬라는것은 저장용량을 말하는것이다.) os의 캐쉬가 아니라 저장공간을 이야기 한다.
	이렇게 메모를 하는것을 코드의 구현에서는 배열에 저장하는것으로 할 수 있으며, 이를 메모리제이션이라고 한다.
*/

int Fibonacci(int n)
{
	if (n <= 1)
		return n;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int cache[100];
int Fibonacci2(int n)
{
	if (n <= 1) return n;
	else
	{
		if (cache[n] > 0)
		{
			return cache[n];
		}
		cache[n] = Fibonacci2(n - 1) + Fibonacci2(n - 2);
		return cache[n]; //o(n) 까지 내려오게된다. 작은 부분 문제를 큰문제를 풀 수 있다. 풀었던걸 또 안풀수 있게 한다.
	}
}

/*
동적 계획법 구현할수 있는 구현방식
1. top-down : 큰 문제를 작은 문제로 쪼개가면서 푸는 방식(재귀) : 방금 위에서 한것.
2. botton - up : 작은 문제부터 차례대로 푸는 방식(반복문)
	
	top-down 
		1. 큰 문제를 작은 문제로 나눈다.
		2. 작은 문제를 푼다.
		3. 작은문제를 풀었으니, 이제 큰 문제를 푼다.

	bottom-up
		1. 문제를 크기가 작은 문제부터 차례대로 푼다.
		f(0) + f(1) + f(2) + f(3) + f(4) 나눠놓고 마지막에 다 합친다.
		2. 문제의 크기를 조금씩 크게 만들면서 문제를 점점푼다.
		3. 작은 문제를 풀면서 왔기 때문에, 큰 문제는 항상 풀 수 있다.
		4. 반복하다 보면 가장 큰 문제를 풀수 있다.
*/

//시간 복잡도 이것도 똑같이 O(n)
int cache2[100];
int Fibonacci3(int n)
{
	cache2[0] = 0;
	cache2[1] = 1;
	for (int i = 2; i <= n; i++)
		cache2[i] = cache2[i - 1] + cache2[i - 2];
	return cache2[n];
}

/*
동적 계획법을 통해 문제풀이.작은 문제로 나눌수 있는지. 
먼저, 문제에서 구하려고 하는 답을 문장으로 나타낸다.
(ex. 피보나치 수를 구하는 문제 -> n번째 피보나치 수)
이제 그 문장에서 나와있는 변수의 개수만큼 메모하는 캐시 배열을 만든다.
top-down인 경우에는 재귀 호출의 인자의 개수가 됨.
반복문의 개수 bottom-up이면
마지막으로 문제를 작은 문제로 나누고, 일반식으로 수식을 세우고 나면(작은문제로 나눌수 있다)
수식을 이용해서 문제를 표현한다.

동적계획하면 컨택스트 스위칭 하면 일어나 할당하는 시간이 늘어난다. 
분할정복: 하면서 한다. top down botton up 이나 다 하면서 분할하는거야.

*/
