/*
그래프
	0  -  3

	|  \  |

	1  -  2

	인접 정점
	하나의 정점에서 간선에 의해 직접 연결된 정점
	ex) 정점 0의 인접 정점은 1, 2, 3

	무방향 그래프의 차수(degree)
	하나의 정점에 연결된 다른 정점의 수

	정점 0의 차수 : 3
	무방향 그래프의 모든 차수의 합은 간선 수의 2배
	G의 차수의 합 : 3 + 2 + 3 + 2 = 10;
	G의 간선의 수 : 5
	-> 모든 차수의 합 : 10 = 5 * 2

	방향 그래프의 차수
	진입 차수(in - degree) : 외부에서 오는 간선의 수
	진출 차수(out - degree) : 외부로 향하는 간선의 수
	방향 그래프의 모든 진입(진출) 차수의 합 = 간선의 수

	그래프의 경로
	무방향 그래프의 정점 s로 부터 정점 e까지의 경로
	s, v1, v2, v3, .... vk, e
	나열된 정점들 간에 반드시 간선
	(s, v1), (v1, v2), (v2, v3).....(vk, e) 
	이 존재한다.

	방향 그래프의 정점 s로부터 정점 e까지의 경로
	나열된 정점들 간에 반드시 간선
	<s, v1>, <v1, v2>.... <vk, e>
	이 존재한다.

	경로의 길이(length)
	경로를 구성하는데 사용된 간선의 수

	단순 경로(simple path)
	경로 중에서 반복되는 간선이 없는 경로

	사이클(cycle)
	단순 경로의 시작 정점과 종료 정점이 동일한 경로


	그래프의 연결 정도
	1. 연결 그래프(connected graph)
	완전 그래프(complete graph)라고도 한다.
	무방향 그래프 G에 있는 모든 정점쌍에 대하여
	항상 경로가 존재하는 그래프
	간선의 수 : 정점이 n개가 존재한다면?
	n(n-1)/2 

	무방향 그래프(undirected graph)
	방향 그래프(directed graph)
	완전 그래프(complete graph)
	부분 그래프(subgraph)
	가중치 그래프(weigh graph)
	
	비연결 그래프
	노드들 중, 간선에 의해 연결되어 있지 않은 
	노드가 존재하는 그래프

	신장트리(spanning tree)
	그래프의 모든 정점을 포함하는 트리
	최소 연결부분 그래프(간선의 수가 제일 적은 그래프)

	최소 신장트리
	각 간선에 가중치가 부여되어 있을때, 가중치를
	고려하여 최소 비용의 신장트리를 구하는 것.
	크루스칼(kruskal), 프림(prim) 알고리즘을 이용해 구할수 있다.


	인접 행렬(adjacent matrix)방법
	만약 간선(i, j)가 그래프에 존재한다면
	M[i][j] = 1;
	그렇지 않다면 M[i][j] = 0;

	인접 행렬의 대각선 성분은 모두 0
	(자체 간선을 불허한다, ex) M[0][0] = 0)
	무방향 그래프의 인접 행렬은 대칭

	그래프에 간선이 많이 존재하는 밀집 그래프(dense graph)를
	표현하는 경우에는 적합하나,
	그래프 내에 적은 숫자의 간선만을 가지는 
	희소 그래프(sparse graph)의
	경우에는 메모리 낭비가 크기 때문에 적합하지 않다.

	인접 리스트(adjacency list)방법
	각 정점에 인접한 정점들을 연결리스트로 표현하는 방법
	인접 리스트 표현은 간선의 개수가 적은 희소 그래프의
	표현에 적합하다.

*/

#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

int main()
{
	int m;
	cout << "노드의 개수 입력 : ";
	cin >> m;
	int** graph = new int*[m];
	for (int i = 0; i < m; i++)
		graph[i] = new int[m];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			graph[i][j] = 0;

	int u, v;
	for (int i = 0; i < m; i++)
	{
		system("cls");
		cout << "연결할 정점(u) : ";
		cin >> u;
		cout << endl;
		cout << "연결할 정점(v) : ";
		cin >> v;
		cout << endl;
		graph[u][v] = graph[v][u] = 1;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
				cout << graph[i][j] << "\t";
			cout << endl;
		}
		Sleep(1000);
	}
	system("cls");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
			cout << graph[i][j] << "\t";
		cout << endl;
	}
		
	vector<int> g[6];
	g[1].push_back(2);
	g[1].push_back(3);
	g[2].push_back(3);
	g[2].push_back(4);

	//0번 안쓰는 이유.

	for (int v : g[1])
		cout << v << endl;


	return 0;
}


