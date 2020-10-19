#include "DisjointSet.h"

int main()
{
	DisjointSet dj(6);
	dj.Merge(0, 1);
	dj.Merge(0, 2);
	dj.Merge(0, 3);
	dj.Merge(4, 5);

	cout << dj.IsSameSet(0, 2) << endl;

	return 0;
}