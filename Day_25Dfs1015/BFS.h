#pragma once

/*
그래프의 탐색
	- 하나의 정점으로부터 시작해서 차례대로 모든 정점들을 한번씩 방문하는것.
	깊이 우선 탐색 / 너비 우선 탐색이 있다.

	너비 우선 탐색(BFS, Breadth - first search)

	루트 노드(혹은 임의의 다른 노드)에서 시작해서 인접한 노드를 먼저 탐색하는 방법
	시작 정점에서 가까운 정점을 먼저 방문하고 멀리 떨어져 있는 정점을 나중에
	순회하는 방식이다.
	즉 깊게 탐색하기 전에 넓게 탐색하는 방식이다.

사용하는 경우
	-> 두 노드 사이의 최단경로 혹은 임의의 경로를 찾고싶을때 사용한다.

	ex)우리나라의 모든 길을 그래프로 표현 한 후 서울에서 부산까지 가는 경로를 찾는다고 했을때
	깊이 우선 - > 모든 길을 다 살펴봐야 할지도 모른다.
	너비 우선 - > 서울과 가까운 길부터 탐색하기 시작해서 부산까지 도달하면 탐색이 끝난다. 

너비 우선 탐색의 특징
	-> 직관적이지 않은 면이 있다.
	-> 재귀적으로 동작하지 않는다.
	-> 어떤 노드를 방문했었느지를 기록을 해야 한다. 안하면 무한루프에 빠질수 있다.
	-> 방문한 노드들을 차례로 저장한 후 꺼낼 수 있는 큐를 사용한다.

	prim dikstra 알고리즘과 유사함

탐색 과정
	1. 시작노드를 방문한다.(방문한 노드를 체크한다)
		-> 큐에 방문된 노드를 삽입
		-> 초기 상태의 큐는 시작노드만이 저장된다.
	2. 큐에서 꺼낸 노드와 인접한 노드들을 모두 차례로 방문한다.
		-> 큐에서 꺼낸 노드와 인접한 노드가 없다면, 큐의 앞에서 노드를 꺼낸다.
		-> 큐에 방문한 노드를 삽입한다.

	3. 큐가 비어있을때까지 반복한다.
*/

#include <Windows.h>
#include <iostream>
#include <queue>
using namespace std;

class Graph
{
public:
	Graph(int nodeCount)
		: nodeCount(nodeCount)
	{
		graph = new int*[nodeCount];
		for (int i = 0; i < nodeCount; i++)
			graph[i] = new int[nodeCount];

		for (int i = 0; i < nodeCount; i++)
			ZeroMemory(graph[i], sizeof(int) * nodeCount);
		
		visited = new int[nodeCount];
		ZeroMemory(visited, sizeof(int) * nodeCount);
	}

	~Graph()
	{
		for (int i = 0; i < nodeCount; i++)
			delete[] graph[i];
		delete[] graph;

		delete[] visited;
	}

	void MakeLink(int x, int y)
	{
		if (x == y || graph[x][y] == 1 || x >= nodeCount || y >= nodeCount)
			return;

		graph[x][y] = graph[y][x] = 1;
	}

	void Display()
	{
		for (int i = 0; i < nodeCount; i++)
		{
			for (int j = 0; j < nodeCount; j++)
				cout << graph[i][j] << "\t";
			cout << endl;
		}
	}

	void BFS(int start)
	{
		cout << start << " ";
		q.push(start);
		visited[start] = 1;

		while (q.empty() == false)
		{
			int node = q.front();
			q.pop();
			for (int i = 0; i < nodeCount; i++)
			{
				if (graph[node][i] == 1 && visited[i] == 0)
				{
					visited[i] = 1;
					cout << i << " ";
					q.push(i);
				}
			}
		}
	}

private:
	int** graph = nullptr;
	int* visited = nullptr;
	int nodeCount = 0;
	queue<int> q;

};

class Graph2
{
public:
	Graph2(int nodeCount)
		: nodeCount(nodeCount)
	{
		graph.assign(nodeCount, vector<int>());
	}

	void MakeLink(int node, int next)
	{
		graph[node].push_back(next);
	}

	void Display()
	{
		for (int i = 0; i < nodeCount; i++)
		{
			cout << "[" << i << "] -> ";
			for (int v : graph[i])
				cout << v << " ";
			cout << endl;
		}
	}

	/*
		start에서부터 시작해서 BFS를 수행하고
		시작점부터 각 정점까지의 최단거리와 너비우선탐색 신장트리를 계산한다.
		dist[i] = start부터 i까지의 최단거리
		parent[i] = 너비우선탐색 신장트리에서 i의 부모의 번호
	*/
	void BFS(int start, vector<int>& dist, vector<int>& parent)
	{
		dist = vector<int>(graph.size(), -1);
		parent = vector<int>(graph.size(), -1);

		queue<int> q;
		dist[start] = 0;
		parent[start] = start;

		q.push(start);

		while (q.empty() == false)
		{
			int curr = q.front();
			q.pop();

			for (int i = 0; i < graph[curr].size(); i++)
			{
				int next = graph[curr][i];
				if (dist[next] == -1)
				{
					dist[next] = dist[curr] + 1;
					parent[next] = curr;
					q.push(next);
				}
			}
		}
	}

private:
	vector<vector<int>> graph;
	int nodeCount;
};