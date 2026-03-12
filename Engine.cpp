#include "Engine.h"
#include "conio.h"
#include <iostream>
#include <Windows.h>

int Map[10][10] =
{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int PlayerX = 1;
int PlayerY = 1;

int Input()
{
	return _getch();
}

void Tick(int KeyCode)
{
	if (KeyCode == 'W' || KeyCode == 'w')
	{
		AddPlayerOffset(0, -1);
	}
	if (KeyCode == 'S' || KeyCode == 's')
	{
		AddPlayerOffset(0, 1);
	}
	if (KeyCode == 'A' || KeyCode == 'a')
	{
		AddPlayerOffset(-1, 0);
	}
	if (KeyCode == 'D' || KeyCode == 'd')
	{
		AddPlayerOffset(1, 0);
	}
}


void Clear()
{
	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < 10; ++X)
		{
			GotoXY(2 * X, Y);
			std::cout << "  ";
		}
	}
}

void Render()
{
	Clear();

	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < 10; ++X)
		{
			GotoXY(2* X, Y);
			if (PlayerX == X && PlayerY == Y)
			{
				std::cout << "P ";
			}
			else if (Map[Y][X] == 1)
			{
				std::cout << "# " << std::endl;
			}
			else
			{
				std::cout << "  " << std::endl;
			}
		}
	}
}

void GotoXY(int x, int y)
{ 
	COORD Pos = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
}

void AddPlayerOffset(int DeltaX, int DeltaY)
{
	PlayerX += DeltaX;
	PlayerY += DeltaY;
}