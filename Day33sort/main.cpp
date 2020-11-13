#include "Timer.h"
#include "Bubble.h"
#include "Selection.h"
#include "Insertion.h"
#include "Merge.h"
#include "Quick.h"

int main()
{
	Timer timer;

	int dataSet[USHRT_MAX];
	//vector<int> dataSet(USHRT_MAX);
	ReadDatas(dataSet);

	timer.Start();
	//BubbleSort(dataSet, (int)USHRT_MAX);
	//Selection(dataSet, USHRT_MAX);
	//Insertion(dataSet, USHRT_MAX);
	//MergeSort(dataSet, 0, USHRT_MAX - 1);
	QSort(dataSet, 0, USHRT_MAX - 1);
	float time = timer.End();

	//kmp

	cout << fixed << setprecision(5) << time << endl;


	return 0;
}