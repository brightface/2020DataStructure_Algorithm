#include <iostream>
using namespace std;

int arr[10];
int n,k;
int check[10];
void dfs(int r)
{	
	//검사 로 풀면 시간 더 걸린다. 먼저 
	if (r > n) {
		int flag = 0;
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= k; j++) {
				if (arr[i] == arr[j]) {
					flag = 1;
				}
			}
		}
		if (!flag)
		{
			for (int i = 1; i <= k; i++) {
				cout << arr[i];
			}cout << endl;
		}
	}
	else {
		for (int i = 1; i <= k; i++) {
			arr[r] = i;
			check[r] = 1;
			dfs(r + 1);
			check[r] = 0;
		}
	}
}
int main()
{
	cin >> n >>k;
	dfs(1);
}