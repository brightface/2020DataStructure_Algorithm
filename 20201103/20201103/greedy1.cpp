#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int p[1005];
int result = 0;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);
	sort(p, p + n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			result += p[j];

	printf("%d", result);
	return 0;
}
