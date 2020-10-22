#include <iostream>
#include "Dijkstra.h"
using namespace std;
int main()
{
	Dijkstra d(6);
	d.MakeEdge(0, 0);
	d.MakeEdge(0, 2);
	d.MakeEdge(0, 5);
	d.MakeEdge(0, 1);
	d.MakeEdge(0, INF);
	d.MakeEdge(0, INF);

	d.MakeEdge(1, 2);
	d.MakeEdge(1, 0);
	d.MakeEdge(1, 3);
	d.MakeEdge(1, 2);
	d.MakeEdge(1, INF);
	d.MakeEdge(1, INF);

	d.MakeEdge(2, 5);
	d.MakeEdge(2, 3);
	d.MakeEdge(2, 0);
	d.MakeEdge(2, 3);
	d.MakeEdge(2, 1);
	d.MakeEdge(2, 5);

	d.MakeEdge(3, 1);
	d.MakeEdge(3, 2);
	d.MakeEdge(3, 3);
	d.MakeEdge(3, 0);
	d.MakeEdge(3, 1);
	d.MakeEdge(3, INF);

	d.MakeEdge(4, INF);
	d.MakeEdge(4, INF);
	d.MakeEdge(4, 1);
	d.MakeEdge(4, 1);
	d.MakeEdge(4, 0);
	d.MakeEdge(4, 2);

	d.MakeEdge(5, INF);
	d.MakeEdge(5, INF);
	d.MakeEdge(5, 5);
	d.MakeEdge(5, INF);
	d.MakeEdge(5, 2);
	d.MakeEdge(5, 0);
	
	d.FindPath(0);
	for (auto node : d.dist) {
		cout << node << " ";
	}
	

	/*d.MakeEdge(3, 5);
	d.MakeEdge(3, 3);
	d.MakeEdge(3, 0);
	d.MakeEdge(3, 3);
	d.MakeEdge(3, 1);
	d.MakeEdge(3, 5);*/

}