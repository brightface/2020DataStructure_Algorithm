#pragma once
//크루스칼 알고리즘
//신장트리를 만드는 방식에 따라서 가중치의 합이 최소가 되게
//크루스칼이 의 알고리즘 
//크루스칼 알고리즘
//무향 연결 그래프가 주어질떄 최소비용 신장트리라고 부르는 서브 그래프를 찾는 알고리즘.
//크루스칼 알고리즘은 Union_Find 자료구조를 사용한다.
//신장트리는 해당 그래프의 모든 정점을 포함하는 트리 형태의 서브 그래프를 의미한다.
//
//신장트리는 해당 그래프의 모든 정점을 포함한 트리 형태의 서브 그래프를 의미한다.
//그래프에서 신장트리는 여러개가 존재할 수 있다.
//글너 신장트리들 중에서 간선의 가중치의 합이 가장 작은 신장트리를 
//최소비용 신장트리라고 한다.(MST : minimum spanning tree)

/*
여러개의 도시가 있을 때 각 도시의 도로를 이용해 연결하고자 할때 비용을 최소한으로 하고자 할때 실제로 적용되는 알고리즘
네이버 지도 최적경로.

구현방법
	1. 모든 간선을 끊어 놓는다.
	//연결이 안되어있다고 가정을 하고 가중치 값만 가지고 있다.
	//초기상태는 연결정보가 다 없다고 가정하는거야.

	2. 가중치 순으로 간선들을 정렬한다(오름차순으로)
	 - 내림차순으로 하는 것은 최대비용 신장트리 . 최악의 경우에 어떻다고 하면 되겠지.
	3. 정렬된 간선을 순서대로 선택한다.
	4. 선택한 간선의 두 정점이 연결되어 있지 않으면, 해당 간선을 최소비용 신장트리에 포함시키고 두 정점을 연결한다.

	(사이클은 생기면 안돼.)
	(사이클이 있으면 안됨)
	(간접적으로 연결이 되어 있어도 연결이 되어있다고 친다)
	최소비용 신장트리에서 간선의 개수가 있다.
	(최소 비용 신장트리의 총 간선의 수 : 총 노드의 개수 -1)
*/
#include <vector>
#include <algorithm>

using namespace std;

class Union_Find
{
public:
	void Init(int nodeCount)
	{
		for (int i = 0; i < nodeCount; i++)
		{
			
			parent.push_back(i);
			height.push_back(1);
			groupSize.push_back(1);
		}
	}
	//제일 먼저 선행되어야 하는것.
	//루트를 알아야겠지
	//-같은 트리안에 있는가 없는가 알지
	int GetRoot(int now)
	{
		if (parent[now] == now) return now;
		return parent[now] = GetRoot(parent[now]);
	}

	bool IsSameSet(int v1, int v2)
	{
		return GetRoot(v1) == GetRoot(v2);
	}

	void Merge(int v1, int v2)
	{
		//루트노드가 속한 집합 집합을 찾아와야한다.
		v1 = GetRoot(v1);
		v2 = GetRoot(v2);

		if (v1 == v2) return;
		if (height[v1] < height[v2])
			swap(v1, v2);

		parent[v2] = v1;
		groupSize[v1] += groupSize[v2];
		if (height[v1] == height[v2])
			height[v1]++; //같을 때는 증가하고 자시고 할게 없다.
	}

private:
	vector<int> parent;
	vector<int> height;
	vector<int> groupSize;
};

class Kruskal
{
	public:
		struct Edge
		{
			int v1, v2; //노드들
			int cost; //가중치
			//Rvalue면 애초에 상수잖아. 받을때 상수로 받아야해. 못바꾸게 만든다는 소리.
			/*반환 받는놈을 수정못하겠다.*/const bool operator < (const Edge& e1) /**/const //코드 안에서 멤버변수를 바꾸지 못하겠다. 멤버변수를 상수화 시킨다.
			{

				return cost < e1.cost;
			}
		};

		//상수버전으로 호출하면 상수버전으로만 호출할수 있다.
		//상수객체: 언제쓰냐면
		//상수 매개변수가 넘어 왔을때

	/*	const Edge e;
		void Function() 
		{
			e.Funcion();
		}*/
public:
	void AddEdge(Edge edge)
	{
		edges.push_back(edge);
	}

	int MakeMST(int nodeCount)
	{
		uf.Init(nodeCount + 1); //0부터 쓰면 정신이 없으니까 1번부터 쓰려는거야.
		sort(edges.begin(), edges.end());
		int result = 0;
		int max_tmp = -1;
		for (Edge e : edges)
		{	
			
			if (uf.IsSameSet(e.v1, e.v2) == false)
			{
				uf.Merge(e.v1, e.v2);
				result += e.cost;
				if (e.cost > max_tmp) max_tmp = e.cost;
			}
		}
		//cout << max_tmp;
		return result-max_tmp;
	}

	//사이클 체크하는것은 하나 해봐. IsSameSet에서 잡힌다.
	private:
		vector<Edge> edges;
		Union_Find uf;//객체로 잡아줄게. 집합/ 간선의 정보를 넣어서 집합을 만든다.
	/*public:	
		int max_tmp;*/
};
