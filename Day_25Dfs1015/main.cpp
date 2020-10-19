/*
���� ���
	�׷����� ������ ���� �����ϴ� ���� �׷���(dense graph)�� ǥ���ϴ� ��쿡 ����
	�׷��� ���� ���� ������ �������� ������ ��� �׷���(sparse graph)�� ��쿡��
	�޸� ���� ũ�� ������ �������� �ʴ�.

���� ����Ʈ
	�� ������ ������ �������� ���Ḯ��Ʈ�� ǥ���ϴ� ���
	������ ������ ���� ��� �׷����� ǥ���� �����ϴ�.
*/

#include <vector>
#include <iostream>
#include "BFS.h"
using namespace std;

int main()
{
	//vector<int> g[6]; //�ε��� 0���� ������
	//g[1].push_back(2); // 1 -> 2
	//g[1].push_back(3); // 1 -> 3     [1] -> 2 -> 3
	//g[2].push_back(3); // [2]->3
	//g[3].push_back(4); 

	//for (int v : g[1])
	//	cout << v << endl;

	//BFS DFS
	//BFS(breath - first search) �ʺ� �켱 Ž��
	//DFS(depth - first search) ���� �켱 Ž��

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