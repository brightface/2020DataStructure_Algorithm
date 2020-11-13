#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
int result[3];
int map[2200][2200];

//단위 종이 내 모든 칸들이 모두 같은지 아닌지.
bool Check(int row, int col, int num)
{
	int start = map[row][col];
	for (int i = row; i < row + num; i++)
	{
		for (int j = col; j < col + num; j++)
		{
			if (start != map[i][j]) return false;
		}
	}
	return true;
}

//9분할 하는 함수
void Divide(int row, int col, int num)
{
	if (Check(row, col, num) == true)
		result[map[row][col]]++;
	//같으면 쁠쁠
	else
	{
		int size = num / 3;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				Divide(row + size * i, col + size * j, size*num);
			}
		}
	}
}

int main()
{
	//전형적인 분할정복의 방법이야.
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int input;
			scanf("%d", &input);
			input++; //-1 0 1 을 각각 0 1 2 로 표현
			map[i][j] = input;
		}
	}

	Divide(0, 0, n);
	printf("%d\n%d\n%d", result[0], result[1], result[2]);
}
