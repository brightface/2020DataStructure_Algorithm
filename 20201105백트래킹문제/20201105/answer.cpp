

#include <iostream>
using namespace std;

const int MAX = 9;
int arr[MAX];
bool visited[MAX];
int n, m;

void Function(int count)
{
	if (count == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}cout << endl; return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == false)
		{
			//check배열로 체크한느구나
			arr[count] = i;
			visited[i] = true;
			Function(count + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	cin >> n >> m;
	Function(0);

	return 0;
}