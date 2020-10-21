#pragma once
/*
Prim's Algoritm
	가중치가 있는 연결된 무향 그래프의 모든 꼭짓점을 포함하면서
	각 변의 비용의 합이 최소가 되는 부분 그래프인 트리. 즉 최소비용
	신장트리를 찾는 알고리즘.

	크루스칼 알고리즘과 같은 용도지만, 응용 상황에서 두 알고리즘의 효율성이 
	달라질 수 있다.

	배열이나 최소힙에서 가중치가 가장 작은 정점을 선택 한 후,
	그 정점의 인접한 정점들에 대해 key값과 연결된 가중치 값을 비교해서
	key값을 갱신할지 말 지 결정하게 된다.

	프림은 정점 위주의 알고리즘
	크루스칼은 간선 위주의 알고리즘.

	프림은 시작점을 정하고, 시작점에서 가까운 정점을 선택하면서
	트리를 구성하기 때문에, 그 과정에서 사이클을 이루지 않지만,
	크루스칼은 시작점을 따로 정하지 않고 최소비용의 간선을 차례로
	대입하면서 트리를 구성하기 떄문에, 사이클이 이루어 지는지 항상 확인해야함.

	프림의 경우 최소 거리의 정점을 찾는 부분에서 자료구조의
	성능에 영향을 받지만, 크루스칼은 어차피 union_find를 쓰기때문에
	일정하다.

	크루스칼은 간선을 기준으로 정렬하는 과정이 오래걸림.

	간선의 개수가 작은 경우에는 크루스칼,
	간선의 개수가 많은 경우에는 프림

	구현 순서.

	1. 임의의 정점을 선택하여 비어있는 T에 포함시킨다.(T는 노드가 한개인 트리)
	2. T에 있는 노드들과 T에 없는 노드들 사이의 간선 중 가중치가 최소인 간선을 찾는다.
	3. 찾은 간선이 연결하는 두 노드 중, T에 없던 노드를 T에 포함시킨다.
	4. 2번 3번을 모든 노드가 T에 포함 될 때 까지 반복한다.

*/

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> PII;

const int NodeCount = 5;

class Prim
{
public:
	//N : 현재 노드, next : 연결할 노드, weight : 연결할 노드와의 가중치
	void MakeEdge(int N, int next, int weight)
	{
		ad[N].push_back(make_pair(next, weight));
	}

	int MakeMST()
	{
		int result = 0;

		for (int i = 0; i < NodeCount; i++)
		{
			dist[i] = INT32_MAX;
			selected[i] = false;
		}

		dist[0] = 0;
		for (int i = 0; i < NodeCount; i++)
		{
			//1,2,3,4,5
			//v(T) = { 1, 2, 3, }
			//3, 4
			//3, 5
			/*
				dist[i]에는 T에 있는 노드와 i노드 사이의 간선 중 최소 가중치가
				들어있다.
				그렇기 때문에 dist[T에 없는 노드]최소값을 찾으면 된다.
				이렇게 하면 T에 있는 노드와 T에 없는 노드 사이의 최소 가중치와
				같은 결과가 나오게 된다.

				now는 어떤 노드와 연결된 간선인지를 저장하기 변수
			*/
			int now = -1;
			int minDist = INT32_MAX;
			for (int j = 0; j < NodeCount; j++)
			{
				if (selected[j] == false && minDist > dist[j])
				{	//트리에 없고 j노드에 연결되어있는 한번도 선택이 안된 간선(또는 최소비용간선?)
					minDist = dist[j];
					now = j;
				}
			}

			if (now < 0)
				return INT32_MAX; //비연결 그래프임

			result += minDist;
			selected[now] = true;
			for (auto edge : ad[now])
			{
				dist[edge.first] = min(dist[edge.first], edge.second);
			}
		}
		return result;
	}

private:
	vector<pair<int, int>> ad[NodeCount];
	//ad[i] : i 노드가 출발지인 간선들, first 목적지, second 가중치
	int dist[NodeCount];
	//dist[i] : 선택된 노드들과 i노드가 연결되 있는 간선의 비용중 최소비용
	bool selected[NodeCount];
	//selected[i] == false : i가 트리에 포함되지 않음
};

/*
	dist 배열을 버리고, 최소힙을 애용해서 트리에 포함시킬 간선을 찾을거임.
	dist : T에 포함된 노드에서 출발하는 간선들을 넣은 최소힙.

	less<pair<int,int>>
	first를 가지고 먼저 정렬.
	first가 같다면, second를 가지고 정렬.
*/
class Prim2
{
public:
	void AddEdge(int node)
	{
		for (auto edge : ad[node])
			dist.push(edge);
	}

	int MakeMST()
	{
		int result = 0;
		for (int i = 0; i < NodeCount; i++)
			selected[i] = false;

		dist.push(PII(0, 0));
		for (int i = 0; i < NodeCount; i++)
		{
			int now = -1;
			int minDist = INT32_MAX;
			while (dist.empty() == false)
			{
				now = dist.top().second;
				if (selected[now] == false)
				{
					minDist = dist.top().first;
					break;
				}
				dist.pop();
			}

			if (minDist == INT32_MAX)
				return INT32_MAX;

			result += minDist;
			selected[now] = true;
			AddEdge(now);
		}
		return result;
	}

private:
	vector<PII> ad[NodeCount]; //adjacent
	priority_queue<PII, vector<PII>, greater<PII>> dist; //최소힙
	bool selected[NodeCount];
};