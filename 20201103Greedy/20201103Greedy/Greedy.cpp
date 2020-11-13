#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;
	num = 1000 - num;
	int cnt = 0;
	int coin[6] = { 500,100,50,10,5,1 };
	while (num > 0) {
		for (int i = 0; i < 6; i++)
		{
			if (num >= coin[i]) {
				num -= coin[i]; cnt++; break;
			}

		}
		/*if (num >= 500) {
			num -= 500; cnt++; continue;
		}
		else {
			if (num >= 100) {
				cnt ++; num -= 100; continue;
			}
			else {
				if (num >= 50) {
					cnt++;	num -= 50;	continue;
				}
				else {
					if (num >= 10) {
						cnt++; num -= 10; continue;
					}
					else {
						if (num >= 5) {
							cnt++;	num -= 5; continue;
						}
						else {
							cnt++; num -= 1;
						}
					}
				}
			}
		}*/
	}
	cout << cnt;
}