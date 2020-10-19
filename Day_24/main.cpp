/*
	<< 그래프란 무엇인가? >>
	- 연결되어 있는 객체간의 관계를 표현하는 자료구조이다.

	<< 유향 그래프 ( Directed Graph ) >>
	- 방향이 있는 그래프
	- (A, B) 소괄호를 사용하여 간선을 표현하게 된다. (무향 표현법)

	<< 무향 그래프 ( inDirected Graph ) >>
	- 방향이 없는 그래프
	- <A, B> A 정점에서 B 정점으로 가는 간선.	(유향 표현법)

	<< 가중치 그래프 >>
	- 가중치가 있는 그래프

	<< 부분 그래프 >>
	- 부분집합으로 포함되는 그래프는 부분 그래프로 불린다.

	<< 인접 정점 >>
	- 하나의 정점에서 간선에 의해 직접 연결된 정점

	<< 무방향 그래프의 차수 >>
	- 하나의 정점에 연결된 다른 정점의 수. 인접 정점의 갯수.
	- 모든 차수의 합은 모든 간선의 2 배 이다. ( 간선의 수 * 2 = 차수의 합 )
	
	<< 방향 그래프의 차수 >>
	- 진입 차수 (In-Degree) : 외부에서 오는 간선의 수
	- 진출 차수 (Out-Degree) : 외부로 향하는 간선의 수
	- 방향 그래프의 모든 진입(진출) 차수의 합은 간선의 수이다.

	<< 무방향 그래프의 경로가 존재 할 때 >>
	- 정점의 나열은 s, v1, v2, v3, .... vk, e 까지 정점이 존재한다.
	- 나열된 정점들 간에 반드시 간선 (s, v1), (v1, v2), ....(vk, e) 까지 연결하는 간선이 존재한다.

	<< 방향 그래프의 경로가 존재 한다면 >>
	- 정점의 나열은 s, v1, v2, v3, .... vk, e 까지 정점이 존재한다.
	- 나열된 정점들 간에 반드시 간선 <s, v1>, <v1, v2>, ....<vk, e> 까지 연결하는 간선이 존재한다.

	<< 경로의 길이 (Length) >>
	- 경로를 구성하는데 사용된 간선의 수

	<< 단순 경로 (Simple Path) >>
	- 경로 중에서 반복되는 간선이 없는 경로가 단순 경로이다.

	<< 사이클 (Cycle) >>
	- 단순 경로의 시작 정점과 종료 정점이 동일한 경로.
	
	<< 그래프의 연결 정도 >>
	1. 연결 그래프 ( Connected Graph )는 일반적으로 완전 그래프 ( Complete Graph ) 를 이야기한다.
	무방향 그래프 G 에 있는 모든 정점 쌍에 대하여 항상 경로가 존재하는 그래프.
	간선의 수 : 정점이 n 개일때 // n(n - 1) / 2;

	2. 무방향 그래프 ( UnDirected Graph )

	3. 방향 그래프 ( Directed Graph )

	4. 완전 그래프 ( Complete Graph )

	5. 부분 그래프 ( SubGraph )

	6. 가중치 그래프 ( Weight Graph )

	7. 비연결 그래프 ( 노드들 중, 간선에 의해 연결되어 있지 않은 노드가 존재하는 그래프 )

	8. 신장 트리 ( Snapping Tree )
	- 그래프의 모든 정점을 포함하는 트리

	9. 최소 연결부분 그래프
	- 간선의 수가 제일 적은 그래프

	10. 최소 신장트리
	- 각 간선의 가중치가 부여되어 있을 때, 가중치를 고려하여 최소 비용의 신장 트리를 구하는것
	- 크루스칼 ( kruskal ), 프림 ( prim ) 알고리즘을 이용해 구할 수 있다.

	<< 인접 행렬 ( Adjacent Matrix ) 방법 >>
	- 만약 간선(i, j)가 그래프에 존재한다면, M[i][j] = 1; 그렇지 않다면 M[i][j] = 0;
	
*/

#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	int m;
	cout << "정점의 개수 입력 : ";
	cin >> m;

	int** graph = new int*[m];
	for (int i = 0; i < m; i++)
		graph[i] = new int[m];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			graph[i][j] = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
			cout << graph[i][j] << "\t";
		cout << endl;
	}

	int u, v;
	for (int i = 0; i < m; i++)
	{
		system("cls");

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
				cout << graph[i][j] << "\t";
			cout << endl;
		}

		cout << "연결한 정점 (u) : ";
		cin >> u;
		cout << "연결한 정점 (v) : ";
		cin >> v;

		cout << endl;
		graph[u][v] = graph[v][u] = 1;
	}

	return 0;
}