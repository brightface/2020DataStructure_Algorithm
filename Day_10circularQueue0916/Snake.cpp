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
int GetchCon(int x, int y);

EDir dir;

bool MoveSnake();
void Gotoxy(int x, int y);
void ProcessKey();
void InitStage(int stage);

int main()
{
	CONSOLE_CURSOR_INFO info{ 1, false };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

	InitStage(0);

	MoveSnake();

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

	while (true)
	{
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

		tail = tail == QS - 1 ? 0 : tail + 1;

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
}

void InitStage(int stage)
{
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
}
