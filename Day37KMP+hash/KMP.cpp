#include "KMP.h"

int main()
{
	string parent = "ABCABABABA";
	string pattern = "ABA";

	//o(m*n)
	//KMP
	//M : ���ڿ� ������ ����, N�� ã�� ������ ����
	//o(m + n)
	//FindString(parent, pattern);
	//vector<int> table = MakeTable(pattern);
	KMP(parent, pattern);

	return 0;
}