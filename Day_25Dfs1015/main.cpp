/*
인접 행렬
	그래프에 간선이 많이 존재하는 밀집 그래프(dense graph)를 표현하는 경우에 적합
	그래프 내에 적은 숫자의 간선만을 가지는 희소 그래프(sparse graph)의 경우에는
	메모리 낭비가 크기 때문에 적합하지 않다.

인접 리스트
	각 정점에 인접한 정점들을 연결리스트로 표현하는 방법
	간선의 개수가 적은 희소 그래프의 표현에 적합하다.
*/

#include <vector>
#include <iostream>
#include "BFS.h"
using namespace std;

int main()
{
	//vector<int> g[6]; //인덱스 0번은 제외함
	//g[1].push_back(2); // 1 -> 2
	//g[1].push_back(3); // 1 -> 3     [1] -> 2 -> 3
	//g[2].push_back(3); // [2]->3
	//g[3].push_back(4); 

	//for (int v : g[1])
	//	cout << v << endl;

	//BFS DFS
	//BFS(breath - first search) 너비 우선 탐색
	//DFS(depth - first search) 깊이 우선 탐색

	Graph2 g(9);
	g.MakeLink(0, 1);
	g.MakeLink(0, 3);
	g.MakeLink(0, 4);
	g.MakeLink(0, 8);

	g.MakeLink(1, 0);
	g.MakeLink(1, 2);
	g.MakeLink(1, 3);

	g.MakeLink(2, 1);
	g.MakeLink(2, 5);
	g.MakeLink(2, 6);

	g.MakeLink(3, 0);
	g.MakeLink(3, 1);
	g.MakeLink(3, 6);

	g.MakeLink(4, 5);
	g.MakeLink(4, 0);

	g.MakeLink(5, 4);
	g.MakeLink(5, 2);

	g.MakeLink(6, 2);
	g.MakeLink(6, 3);
	g.MakeLink(6, 7);

	g.MakeLink(7, 6);

	g.MakeLink(8, 0);

	g.Display();
	//g.BFS(5);

	return 0;
}