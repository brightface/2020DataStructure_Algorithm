#include "Prim.h"

int main()
{
	Prim p;
	p.MakeEdge(0, 3, 3);
	p.MakeEdge(0, 4, 4);

	p.MakeEdge(1, 3, 5);
	p.MakeEdge(1, 2, 8);
	p.MakeEdge(1, 4, 6);

	p.MakeEdge(2, 1, 8);
	p.MakeEdge(2, 3, 9);

	p.MakeEdge(3, 0, 3);
	p.MakeEdge(3, 1, 5);
	p.MakeEdge(3, 4, 7);
	p.MakeEdge(3, 2, 9);

	p.MakeEdge(4, 0, 4);
	p.MakeEdge(4, 1, 6);
	p.MakeEdge(4, 3, 7);

	int result = p.MakeMST();


	return 0;
}