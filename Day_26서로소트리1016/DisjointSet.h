#pragma once

/*
DisjointSet : ���μ� ����
Union : DisjointSet�� ǥ���Ҷ� ����ϴ� �ڷᱸ��
-> ������ �����ϴ� �ڷᱸ��.
-> ���� �ߺ����� ���� �κ� ���յ�� ������ ���ҵ鿡
���� ������ �����ϰ� �����ϴ� �ڷᱸ����.

��ü ������ ���� �� ���� ��ҵ��� ��ġ�� �ʵ��� �����Ҷ�
���� ����ϰ� �ȴ�.

	-> Set�� ��ҵ��� �����̴�.(������ ������� �ʴ´�)
	-> Set A�� ��� ���Ұ� Set B�� ���Եɶ�
	A�� B�� �κ�����(subset)�̶� �Ѵ�.
	�� �� B�� A�� �ʿ� ����(superset)
	-> ������ Set�� ����(partition)�Ѵٴ� ���� �� �κ�������
	���� �ΰ��� �Ӽ��� �����ϴ� DisjointSet�� �ǵ��� set��
	�ɰ��� ���� ���Ѵ�.
		1. ���ҵ� �κ������� ��ġ�� ������ set�� �ȴ�.
		2. ���ҵ� �κ����� ������ ��ġ�� ���Ұ� ����.
		(mutually disjoint)

	ex) S = 1,2,3,4 / A = 1,2 / B = 3,4, / c = 2,3,4 / D = 4
	A�� B�� S�� �����̴�.
	�� �� A�� B�� disjoint set�̴�.

	A�� C�� S�� ������ �ƴϴ�. ��ġ�� ���� ����
	A�� D�� S�� ������ �ƴϴ�. ���� ���ĵ� S�� �ƴ�.

	1. ��� A�� ��� B�� ���� ���տ� ���ϴ��� Ȯ�� ����
	2. ��� A�� ���� ���հ� ��� B�� ���� ������ ���� ����
*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class DisjointSet
{
public:
	DisjointSet(int nodeCount)
	{
		/*
			�ʱ� ���´� ���� ��Ұ� ���ε��� ���տ�
			���ϴ� ����.
			i���� ��Ҵ� i��° ���տ� ���Ѵٶ�� ����.
		*/
		for (int i = 0; i < nodeCount; i++)
			group.push_back(i);
	}

	bool IsSameSet(int v1, int v2)
	{
		return group[v1] == group[v2];
	}

	void Merge(int v1, int v2)
	{
		//v1���� �պ��Ѵ�.
		int groupNum = group[v2];
		for (int i = 0; i < group.size(); i++)
			if (group[i] == groupNum)
				group[i] = group[v1];
		//0 1 2 3 4 5
		//0 0 2 3 4 5
		//0 0 0 3 4 5
		//0 0 0 0 4 5
		//0 0 0 0 0 5
		//0 0 0 0 0 0
	}

private:
	vector<int> group; //group[i] : i���� ��Ұ� ���� ������ ��ȣ
};

/*
	group[i]�� ��Ұ� ����� ������ ��ȣ�� �����ϴ� ��ſ�
	parent[i] Ʈ���� �θ� ����.

	�� ��������� ������ ��ȣ�� ��Ʈ ����� ��ȣ�� ����ϰ� �ȴ�.

	������ ��ȣ(group[i])�� ã�� ������,
	��Ʈ ��带 ã�� �ö󰡸� ��.

	i�� ��Ʈ�϶��� parent[i] = i�� �����Ѵ�.
*/

//int GetRoot(int now)
//{
//	if (parent[now] == now) return now;
//	return parent[now] = GetRoot(parent[now]);
//}

//void Merge(int v1, int v2)
//{
//	//v1 ���� ����
//	v1 = GetRoot(v1);
//	v2 = GetRoot(v2);
//	parent[v2] = v1;
//}

class DisjointSetTree
{
public:
	DisjointSetTree(int nodeCount)
	{
		for (int i = 0; i < nodeCount; i++)
		{
			parent.push_back(i);
			height.push_back(1);
			groupSize.push_back(1);
		}
	}

	int GetRoot(int now)
	{
		if (parent[now] == now)
			return now;
		return parent[now] = GetRoot(parent[now]);
	}

	bool IsSameSet(int v1, int v2)
	{
		return GetRoot(v1) == GetRoot(v2);
	}

	void Merge(int v1, int v2)
	{
		v1 = GetRoot(v1);
		v2 = GetRoot(v2);

		if (v1 == v2) return;

		if (height[v1] < height[v2])
			swap(v1, v2);

		parent[v2] = v1;
		groupSize[v1] += groupSize[v2];
		if (height[v1] == height[v2])
			height[v1]++;
	}

private:
	vector<int> parent;
	vector<int> height;
	vector<int> groupSize;
};
/*
����ȭ�� ��ġ��,
�� ������ ��� �ð� ���⵵�� ��Ŀ�� �Լ��� ���Լ�....�ε�...
O(1) ���ٴ� ������ O(logn)���ٴ� ������.

��� ��Ұ� �ϳ��� ���տ� ���� �� ������ �� �ð� ���⵵��
O(n)���� ������ O(n log n)���� ������.
*/
