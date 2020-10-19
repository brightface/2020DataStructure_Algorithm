#pragma once

/*
DisjointSet : 서로소 집합
Union : DisjointSet을 표현할때 사용하는 자료구조
-> 집합을 관리하는 자료구조.
-> 서로 중복되지 않은 부분 집합들로 나눠진 원소들에
대한 정보를 저장하고 조작하는 자료구조다.

전체 집합이 있을 때 구성 요소들이 겹치지 않도록 분할할때
많이 사용하게 된다.

	-> Set은 요소들의 집합이다.(순서는 고려하지 않는다)
	-> Set A의 모든 원소가 Set B에 포함될때
	A를 B의 부분집합(subset)이라 한다.
	이 때 B는 A의 초월 집합(superset)
	-> 임의의 Set을 분할(partition)한다는 것은 각 부분집합이
	다음 두가지 속성을 만족하는 DisjointSet이 되도록 set을
	쪼개는 것을 뜻한다.
		1. 분할된 부분집합을 합치면 원래의 set이 된다.
		2. 분할된 부분집합 끼리는 겹치는 원소가 없다.
		(mutually disjoint)

	ex) S = 1,2,3,4 / A = 1,2 / B = 3,4, / c = 2,3,4 / D = 4
	A와 B는 S의 분할이다.
	이 떄 A와 B가 disjoint set이다.

	A와 C는 S의 분할이 아니다. 겹치는 원소 있음
	A와 D는 S의 분할이 아니다. 둘을 합쳐도 S가 아님.

	1. 요소 A와 요소 B가 같은 집합에 속하는지 확인 가능
	2. 요소 A가 속한 집합과 요소 B가 속한 집합을 병합 가능
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
			초기 상태는 각각 요소가 따로따로 집합에
			속하는 상태.
			i번쨰 요소는 i번째 집합에 속한다라고 가정.
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
		//v1으로 합병한다.
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
	vector<int> group; //group[i] : i번쨰 요소가 속한 집합의 번호
};

/*
	group[i]에 요소가 저장된 집합의 번호를 저장하는 대신에
	parent[i] 트리의 부모를 저장.

	이 방법에서는 집합의 번호를 루트 노드의 번호로 대신하게 된다.

	집합의 번호(group[i])를 찾고 싶을땐,
	루트 노드를 찾아 올라가면 됨.

	i가 루트일때는 parent[i] = i로 저장한다.
*/

//int GetRoot(int now)
//{
//	if (parent[now] == now) return now;
//	return parent[now] = GetRoot(parent[now]);
//}

//void Merge(int v1, int v2)
//{
//	//v1 으로 병합
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
최적화를 거치면,
각 연산의 평균 시간 복잡도는 아커만 함수의 역함수....인데...
O(1) 보다는 느리고 O(logn)보다는 빠르다.

모든 요소가 하나의 집합에 속할 때 까지의 총 시간 복잡도는
O(n)보다 느리고 O(n log n)보다 빠르다.
*/
