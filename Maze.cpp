#include <iostream>
#include <conio.h>
#include <Windows.h>

void Init(int** Map, int Row, int Col);
void Draw(int** Map, int PlayerX, int PlayerY, int Row, int Col);
void MovePlayer(int** Map, int* PlayerX, int* PlayerY, int Input);
bool CheckWall(int** Map, int PlayerX, int PlayerY);

int main()
{
	int Row = 10;
	int Col = 10;

	int** Map = new int*[Row];
	for (int i = 0; i < 10; ++i)
	{
		Map[i] = new int[10];
	}

	int PlayerX = 1;
	int PlayerY = 1;

	Init(Map, Row, Col);
	Draw(Map, PlayerX, PlayerY, Row, Col);
	
	int Input = 0;

	while (true)
	{
		Input = _getch();
		MovePlayer(Map, &PlayerX, &PlayerY, Input);

		system("cls");

		Draw(Map, PlayerX, PlayerY, Row, Col);
	}

	for (int i = 0; i < Row; ++i)
	{
		delete[] Map[i];
	}
	delete[] Map;
}

void Init(int** Map, int Row, int Col)
{
	for (int i = 0; i < Row; ++i)
	{
		for (int j = 0; j < Col; ++j)
		{
			if (i == 0)
			{
				Map[i][j] = 1;
			}
			else if (i == Row - 1)
			{
				Map[i][j] = 1;
			}
			else if (j == 0)
			{
				Map[i][j] = 1;
			}
			else if (j == Col - 1)
			{
				Map[i][j] = 1;
			}
			else
			{
				Map[i][j] = 0;
			}
		}
	}
}

void Draw(int** Map, int PlayerX, int PlayerY, int Row, int Col)
{
	for (int i = 0; i < Row; ++i)
	{
		for (int j = 0; j < Col; ++j)
		{
			if (i == PlayerY && j == PlayerX)
			{
				std::cout << "P ";
			}
			else if (Map[i][j] == 1)
			{
				std::cout << "* ";
			}
			else if (Map[i][j] == 0)
			{
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}
}

void MovePlayer(int** Map, int* PlayerX, int* PlayerY, int Input)
{
	if (Input == 'W' || Input == 'w')
	{
		--*PlayerY;
		if (!CheckWall(Map, *PlayerX, *PlayerY))
		{
			++*PlayerY;
		}
	}
	else if (Input == 'S' || Input == 's')
	{
		++*PlayerY;
		if (!CheckWall(Map, *PlayerX, *PlayerY))
		{
			--*PlayerY;
		}
	}
	else if (Input == 'A' || Input == 'a')
	{
		--*PlayerX;
		if (!CheckWall(Map, *PlayerX, *PlayerY))
		{
			++*PlayerX;
		}
	}
	else if (Input == 'D' || Input == 'd')
	{
		++*PlayerX;
		if (!CheckWall(Map, *PlayerX, *PlayerY))
		{
			--*PlayerX;
		}
	}

	return;
}

bool CheckWall(int** Map, int PlayerX, int PlayerY)
{
	if (Map[PlayerY][PlayerX] == 1)
	{
		return false;
	}
	return true;
}
