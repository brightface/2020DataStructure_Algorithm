#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main()
{
	set<int> a;
	a.insert(1);
	vector<int> t;
	for (int number : a)
	{
		cout << number;
		t.push_back(number);
	}

	

		
	
}