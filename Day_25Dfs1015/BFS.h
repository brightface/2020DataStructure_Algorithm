#pragma once

/*
�׷����� Ž��
	- �ϳ��� �������κ��� �����ؼ� ���ʴ�� ��� �������� �ѹ��� �湮�ϴ°�.
	���� �켱 Ž�� / �ʺ� �켱 Ž���� �ִ�.

	�ʺ� �켱 Ž��(BFS, Breadth - first search)

	��Ʈ ���(Ȥ�� ������ �ٸ� ���)���� �����ؼ� ������ ��带 ���� Ž���ϴ� ���
	���� �������� ����� ������ ���� �湮�ϰ� �ָ� ������ �ִ� ������ ���߿�
	��ȸ�ϴ� ����̴�.
	�� ��� Ž���ϱ� ���� �а� Ž���ϴ� ����̴�.

����ϴ� ���
	-> �� ��� ������ �ִܰ�� Ȥ�� ������ ��θ� ã������� ����Ѵ�.

	ex)�츮������ ��� ���� �׷����� ǥ�� �� �� ���￡�� �λ���� ���� ��θ� ã�´ٰ� ������
	���� �켱 - > ��� ���� �� ������� ������ �𸥴�.
	�ʺ� �켱 - > ����� ����� ����� Ž���ϱ� �����ؼ� �λ���� �����ϸ� Ž���� ������. 

�ʺ� �켱 Ž���� Ư¡
	-> ���������� ���� ���� �ִ�.
	-> ��������� �������� �ʴ´�.
	-> � ��带 �湮�߾������� ����� �ؾ� �Ѵ�. ���ϸ� ���ѷ����� ������ �ִ�.
	-> �湮�� ������ ���ʷ� ������ �� ���� �� �ִ� ť�� ����Ѵ�.

	prim dikstra �˰���� ������

Ž�� ����
	1. ���۳�带 �湮�Ѵ�.(�湮�� ��带 üũ�Ѵ�)
		-> ť�� �湮�� ��带 ����
		-> �ʱ� ������ ť�� ���۳�常�� ����ȴ�.
	2. ť���� ���� ���� ������ ������ ��� ���ʷ� �湮�Ѵ�.
		-> ť���� ���� ���� ������ ��尡 ���ٸ�, ť�� �տ��� ��带 ������.
		-> ť�� �湮�� ��带 �����Ѵ�.

	3. ť�� ������������� �ݺ��Ѵ�.
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
		start�������� �����ؼ� BFS�� �����ϰ�
		���������� �� ���������� �ִܰŸ��� �ʺ�켱Ž�� ����Ʈ���� ����Ѵ�.
		dist[i] = start���� i������ �ִܰŸ�
		parent[i] = �ʺ�켱Ž�� ����Ʈ������ i�� �θ��� ��ȣ
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