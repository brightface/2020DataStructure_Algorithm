

#include <iostream>
using namespace std;

const int MAX = 9;
int arr[MAX];
bool visited[MAX];
int n, m;

void Function(int count)
{
	if (count > m) return;
	else if (count == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}cout << "\n"; return;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (visited[i] == false)
			{
				//check�迭�� üũ�Ѵ�����
				arr[count] = i;
				visited[i] = true;
				Function(count + 1);
				visited[i] = false;
				//false�̸� ���� ����Ʈ���� �Ѿ�°Ű� true�� ��Ʈ��ŷ�� �ϴ°Ű�
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	Function(0);
	return 0;
}