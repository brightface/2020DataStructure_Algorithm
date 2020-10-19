//ũ�罺Į �˰���
//����Ʈ���� ����� ��Ŀ� ���� ����ġ�� ���� �ּҰ� �ǰ�
//ũ�罺Į�� �� �˰��� 
//ũ�罺Į �˰���
//���� ���� �׷����� �־����� �ּҺ�� ����Ʈ����� �θ��� ���� �׷����� ã�� �˰���.
//ũ�罺Į �˰����� Union_Find �ڷᱸ���� ����Ѵ�.
//����Ʈ���� �ش� �׷����� ��� ������ �����ϴ� Ʈ�� ������ ���� �׷����� �ǹ��Ѵ�.
//
//����Ʈ���� �ش� �׷����� ��� ������ ���Ԥ����Ѥ� Ʈ�� ������ ���� �׷����� �ǹ��Ѵ�.
//�׷������� ����Ʈ���� �������� ������ �� �ִ�.
//�۳� ����Ʈ���� �߿��� ������ ���ڤ̤�ġ�� ���� ���� ���� ����Ʈ���� 
//�ּҺ�� ����Ʈ����� �Ѵ�.(MST : minimum spanning tree)

/*
�������� ���ð� ���� �� �� ������ ���θ� �̿��� �����ϰ��� �Ҷ� ����� �ּ������� �ϰ��� �Ҷ� ������ ����Ǵ� �˰���
���̹� ���� �������. 

�������
	1. ��� ������ ���� ���´�.
	//������ �ȵǾ��ִٰ� ������ �ϰ� ����ġ ���� ������ �ִ�.
	//�ʱ���´� ���������� �� ���ٰ� �����ϴ°ž�.

	2. ����ġ ������ �������� �����Ѵ�(������������)
	 - ������������ �ϴ� ���� �ִ��� ����Ʈ�� . �־��� ��쿡 ��ٰ� �ϸ� �ǰ���.
	3. ���ĵ� ������ ������� �����Ѵ�.
	4. ������ ������ �� ������ ����Ǿ� ���� ������, �ش� ������ �ּҺ�� ����Ʈ���� ���Խ�Ű�� �� ������ �����Ѵ�.

	(����Ŭ�� ����� �ȵ�.)
	(����Ŭ�� ������ �ȵ�)
	(���������� ������ �Ǿ� �־ ������ �Ǿ��ִٰ� ģ��)
	�ּҺ�� ����Ʈ������ ������ ������ �ִ�.
	(�ּ� ��� ����Ʈ���� �� ������ �� : �� ����� ���� -1)




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
	//���� ���� ����Ǿ�� �ϴ°�.
	//��Ʈ�� �˾ƾ߰���
	//-���� Ʈ���ȿ� �ִ°� ���°� ����
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
		//��Ʈ��尡 ���� ���� ������ ã�ƿ;��Ѵ�.
		v1 = GetRoot(v1);
		v2 = GetRoot(v2);

		if (v1 == v2) return;
		if (height[v1] < height[v2])
			swap(v1, v2);

		parent[v2] = v1;
		groupSize[v1] += groupSize[v2];
		if (height[v1] == height[v2])
			height[v1]++; //���� ���� �����ϰ� �ڽð� �Ұ� ����.
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
		int v1, v2; //����
		int cost; //����ġ
		//Rvalue�� ���ʿ� ����ݾ�. ������ ����� �޾ƾ���. ���ٲٰ� ����ٴ� �Ҹ�.
		/*��ȯ �޴³��� �������ϰڴ�.*/const bool operator < (const Edge& e1) /**/const //�ڵ� �ȿ��� ��������� �ٲ��� ���ϰڴ�. ��������� ���ȭ ��Ų��.
		{

			return cost < e1.cost;
		}
	};

	//����������� ȣ���ϸ� ����������θ� ȣ���Ҽ� �ִ�.
	//�����ü: �������ĸ�
	//��� �Ű������� �Ѿ� ������

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
		uf.Init(nodeCount + 1); //0���� ���� ������ �����ϱ� 1������ �����°ž�.
		sort(edges.begin(), edges.end());
		int result = 0;
		for (Edge e : edges)
		{
			if (uf.IsSameSet(e.v1, e.v2) == false)
			{
				uf.Merge(e.v1, e.v2);
				result += e.cost;
			}
		}
		return result;
	}

	//����Ŭ üũ�ϴ°��� �ϳ� �غ�. IsSameSet���� ������.
private:
	vector<Edge> edges;
	Union_Find uf;//��ü�� ����ٰ�. ����/ ������ ������ �־ ������ �����.

};
//#include "UinonFind.h"
//#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	//ifstream in;
	//in.open("input.txt");
	//int k;
	//in >> k;
	int node, edgeCount;
	cin >> node >> edgeCount;
	//cout << node << edgeCount;
	Kruskal k;
	for (int i = 0; i < edgeCount; i++)
	{
		int st, end, weight;
		cin >> st >> end >> weight;
		Kruskal::Edge e;
		e.v1 = st;
		e.v2 = end;
		e.cost = weight;
		k.AddEdge(e);	
	}
	cout<<k.MakeMST(node);


}