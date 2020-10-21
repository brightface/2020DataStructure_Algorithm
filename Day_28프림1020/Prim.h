#pragma once
/*
Prim's Algoritm
	����ġ�� �ִ� ����� ���� �׷����� ��� �������� �����ϸ鼭
	�� ���� ����� ���� �ּҰ� �Ǵ� �κ� �׷����� Ʈ��. �� �ּҺ��
	����Ʈ���� ã�� �˰���.

	ũ�罺Į �˰���� ���� �뵵����, ���� ��Ȳ���� �� �˰����� ȿ������ 
	�޶��� �� �ִ�.

	�迭�̳� �ּ������� ����ġ�� ���� ���� ������ ���� �� ��,
	�� ������ ������ �����鿡 ���� key���� ����� ����ġ ���� ���ؼ�
	key���� �������� �� �� �����ϰ� �ȴ�.

	������ ���� ������ �˰���
	ũ�罺Į�� ���� ������ �˰���.

	������ �������� ���ϰ�, ���������� ����� ������ �����ϸ鼭
	Ʈ���� �����ϱ� ������, �� �������� ����Ŭ�� �̷��� ������,
	ũ�罺Į�� �������� ���� ������ �ʰ� �ּҺ���� ������ ���ʷ�
	�����ϸ鼭 Ʈ���� �����ϱ� ������, ����Ŭ�� �̷�� ������ �׻� Ȯ���ؾ���.

	������ ��� �ּ� �Ÿ��� ������ ã�� �κп��� �ڷᱸ����
	���ɿ� ������ ������, ũ�罺Į�� ������ union_find�� ���⶧����
	�����ϴ�.

	ũ�罺Į�� ������ �������� �����ϴ� ������ �����ɸ�.

	������ ������ ���� ��쿡�� ũ�罺Į,
	������ ������ ���� ��쿡�� ����

	���� ����.

	1. ������ ������ �����Ͽ� ����ִ� T�� ���Խ�Ų��.(T�� ��尡 �Ѱ��� Ʈ��)
	2. T�� �ִ� ����� T�� ���� ���� ������ ���� �� ����ġ�� �ּ��� ������ ã�´�.
	3. ã�� ������ �����ϴ� �� ��� ��, T�� ���� ��带 T�� ���Խ�Ų��.
	4. 2�� 3���� ��� ��尡 T�� ���� �� �� ���� �ݺ��Ѵ�.

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
	//N : ���� ���, next : ������ ���, weight : ������ ������ ����ġ
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
				dist[i]���� T�� �ִ� ���� i��� ������ ���� �� �ּ� ����ġ��
				����ִ�.
				�׷��� ������ dist[T�� ���� ���]�ּҰ��� ã���� �ȴ�.
				�̷��� �ϸ� T�� �ִ� ���� T�� ���� ��� ������ �ּ� ����ġ��
				���� ����� ������ �ȴ�.

				now�� � ���� ����� ���������� �����ϱ� ����
			*/
			int now = -1;
			int minDist = INT32_MAX;
			for (int j = 0; j < NodeCount; j++)
			{
				if (selected[j] == false && minDist > dist[j])
				{	//Ʈ���� ���� j��忡 ����Ǿ��ִ� �ѹ��� ������ �ȵ� ����(�Ǵ� �ּҺ�밣��?)
					minDist = dist[j];
					now = j;
				}
			}

			if (now < 0)
				return INT32_MAX; //�񿬰� �׷�����

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
	//ad[i] : i ��尡 ������� ������, first ������, second ����ġ
	int dist[NodeCount];
	//dist[i] : ���õ� ����� i��尡 ����� �ִ� ������ ����� �ּҺ��
	bool selected[NodeCount];
	//selected[i] == false : i�� Ʈ���� ���Ե��� ����
};

/*
	dist �迭�� ������, �ּ����� �ֿ��ؼ� Ʈ���� ���Խ�ų ������ ã������.
	dist : T�� ���Ե� ��忡�� ����ϴ� �������� ���� �ּ���.

	less<pair<int,int>>
	first�� ������ ���� ����.
	first�� ���ٸ�, second�� ������ ����.
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
	priority_queue<PII, vector<PII>, greater<PII>> dist; //�ּ���
	bool selected[NodeCount];
};