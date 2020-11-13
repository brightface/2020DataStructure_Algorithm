#include "KMP.h"

int main()
{
	string parent = "ABCABABABA";
	string pattern = "ABA";

	//o(m*n)
	//KMP
	//M : 문자열 더미의 길이, N이 찾을 패턴의 길이
	//o(m + n)
	//FindString(parent, pattern);
	//vector<int> table = MakeTable(pattern);
	KMP(parent, pattern);

	return 0;
}