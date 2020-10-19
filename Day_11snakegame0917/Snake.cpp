#define _CRT_NONSTDC_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
using namespace std;

/*
	putch
	출력 버퍼를 사용하지 않고 문자 하나를 콘솔에 바로 출력해주는 함수.

	getch
	입력 버퍼를 사용하지 않고 입력된 키를 바로 변수에 저장한다.
*/

struct Point
{
	int x, y;
};

enum EDir
{
	LEFT = 75,	// 0xE0 (240 75)
	RIGHT = 77,
	UP = 72,
	DOWN = 80,
};

#define QS 255
#define PutchXY(x, y, ch) { Gotoxy(x, y); putch(ch); }

Point snake[QS];
Point now;
int head, tail;
int speed;
int incTail;
int maxNumber;
int stage;
int multi;
int life;

int GetchCon(int x, int y);

EDir dir;

bool MoveSnake();
void Gotoxy(int x, int y);
void ProcessKey();
void InitStage(int stage);
void WaitAnyKey();

int main()
{
	CONSOLE_CURSOR_INFO info{ 1, false };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

	int x = 10, y = 10;
	int number;
	int ch;
	life = 5;

	while (true)
	{
		InitStage(stage);
		Gotoxy(0, 23);
		printf("스테이지 : %d", stage + 1);
		Gotoxy(20, 23); 
		printf("남은 목숨 : %d", life);

		for (number = 0; number < maxNumber; number++)
		{
			Gotoxy(40, 23); 
			printf("남은 먹이 : %d", maxNumber - number);
			Gotoxy(60, 23); 
			printf("꼬리 길이 : 2");

			do
			{
				x = rand() % 80;
				y = rand() % 22;

			} while (GetchCon(x, y) != ' ');

			Gotoxy(x, y);
			printf("%d", rand() % 9 + 1);

			if (number == 0)
			{
				ch = getch();
				if (ch == 0xE0)
					getch();
				else
				{
					if (tolower(ch) == 'p')	// prev Stage
					{
						stage = stage == 0 ? 4 : stage - 1;
						break;
					}
					else if (tolower(ch) == 'n') // next Stage
					{
						stage = stage == 4 ? 0 : stage + 1;
						break;
					}
				}
			}

			if (MoveSnake() == true)
			{
				if (--life == 0)
				{
					Gotoxy(36, 10);
					puts("게임 오버");
					Gotoxy(0, 30);

					return 0;
				}

				Sleep(1500);
				break;
			}
		} // End For Number

		if (number == maxNumber)
		{
			Gotoxy(21, 10);
			puts("아무 키나 누르면 다음 스테이지로 이동");
			WaitAnyKey();

			stage++;
		}
	} // End while true

	return 0;
}

int GetchCon(int x, int y)
{
	COORD cur{ x, y };
	TCHAR ch;
	DWORD dwRead;
	ReadConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), &ch, 1, cur, &dwRead);

	return ch;
}

bool MoveSnake()
{
	int headCh;
	int prev;
	int length;


	while (true)
	{
		length = head - tail;
		if (length < 0)
			length += QS;
		Gotoxy(60, 23);
		printf("꼬리 길이 : %d", length);
		Gotoxy(60, 24);
		printf("늘어날 꼬리 길이 : %2d", incTail);

		ProcessKey();
		switch (dir)
		{
		case LEFT:
		{
			now.x--;
		}
		break;
		case RIGHT:
		{
			now.x++;
		}
		break;
		case UP:
		{
			now.y--;
		}
		break;
		case DOWN:
		{
			now.y++;
		}
		break;
		} // END Switch Dir

		head = head == QS - 1 ? 0 : head + 1;
		snake[head] = now;

		if (incTail == 0)
			tail = tail == QS - 1 ? 0 : tail + 1;
		else
			incTail--;

		headCh = GetchCon(now.x, now.y);

		PutchXY(snake[head].x, snake[head].y, 'S');
		prev = head == 0 ? QS - 1 : head - 1;

		PutchXY(snake[prev].x, snake[prev].y, '#');
		prev = tail == 0 ? QS - 1 : tail - 1;

		PutchXY(snake[prev].x, snake[prev].y, ' ');

		if (headCh != ' ')
			break;

		Sleep(speed);
	}

	if (headCh == '#' || headCh == 'M')
		return true;

	incTail += headCh - '0';

	return false;
}

void Gotoxy(int x, int y)
{
	COORD pos{ x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void ProcessKey()
{
	int ch;

	if (kbhit() == 0) return;

	ch = getch();
	if (ch == 0xE0 || ch == 0)
	{
		ch = getch();

		switch (ch)
		{
			case LEFT:
			{
				if (dir != RIGHT)
					dir = LEFT;
			}
			break;
			case RIGHT:
			{
				if (dir != LEFT)
					dir = RIGHT;
			}
			break;
			case UP:
			{
				if (dir != DOWN)
					dir = UP;
			}
			break;
			case DOWN:
			{
				if (dir != UP)
					dir = DOWN;
			}
			break;
		}
	}
	else
	{
		if (ch == VK_ESCAPE)
			exit(0);
	}
}

void InitStage(int stage)
{
	system("cls");

	snake[0].x = 5; snake[0].y = 5;
	snake[1].x = 6; snake[1].y = 5;
	snake[2].x = 7; snake[2].y = 5;

	Gotoxy(5, 5); puts("##S");
	// puts 함수는 콘솔창으로 문자열을 출력시키는 함수이다.

	head = 2;
	tail = 0;
	now.x = 7;
	now.y = 5;
	dir = RIGHT;
	speed = 150;
	incTail = 0;

	for (int i = 0; i < 80; i++)
	{
		PutchXY(i, 0, 'M');
		PutchXY(i, 22, 'M');
	}

	for (int i = 0; i < 23; i++)
	{
		PutchXY(0, i, 'M');
		PutchXY(79, i, 'M');
	}

	switch (stage)
	{
		case 0:
		{
			maxNumber = 3; speed = 150; multi = 3;
			for (int i = 30; i <= 50; i++)
				PutchXY(i, 11, 'M');
			break;
		}
		case 1:
		{
			maxNumber = 5; speed = 100; multi = 5;
			break;
		}
		case 2:
		{
			maxNumber = 10; speed = 80; multi = 7;
			break;
		}
		case 3:
		{
			maxNumber = 15; speed = 50; multi = 9;
			break;
		}
		case 4:
		{
			maxNumber = 20; speed = 35; multi = 11;
			break;
		}
	}
}

void WaitAnyKey()
{
	int ch;
	ch = getch();

	if (ch == 0xE0 || ch == 0)
		getch();
}
