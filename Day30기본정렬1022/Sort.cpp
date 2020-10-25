#include "Timer.h"
#include "Bubble.h"
#include "Insertion.h"
#include "Selection.h"
#include "Merge.h"
#include "QuickSort.h"
int main()
{
	Timer timer;
	int dataSet[USHRT_MAX];
	//vector<int> dataSet(USHRT_MAX);

	ReadDatas(dataSet);
	timer.Start();
	//Bubble(dataSet, (int)USHRT_MAX);
	//Bubble(dataSet.data(), USHRT_MAX);
	//Insertion(dataSet.data(), USHRT_MAX);
	//Selection(dataSet.data(), USHRT_MAX);

	//MergeSort(dataSet, 0, USHRT_MAX - 1);
	QSort(dataSet, 0, USHRT_MAX - 1);
	cout << fixed << setprecision(5) << timer.End() << endl;

	return 0;
}