#include "UinonFind.h"
//#include <iostream>
#include <fstream>
#include <iostream>

int main()
{

	ifstream in;
	in.open("input.txt");
	
	int node, edgeCount;
	in >> node >> edgeCount;
	//cout << node << edgeCount;
	Kruskal k;
	//int max_temp = -1;
	for (int i = 0; i < edgeCount; i++)
	{
		int st, end, weight;
		in >> st >> end >> weight;
		Kruskal::Edge e;
		e.v1 = st;
		e.v2 = end;
		e.cost = weight;
		//if (weight > max_temp) max_temp = weight;
		k.AddEdge(e);
	}
	//cout << k.max_tmp<<endl;
	std::cout<< k.MakeMST(node);
	

}
