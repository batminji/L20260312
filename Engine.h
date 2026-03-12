#pragma once

extern int Map[10][10];

struct FVector2i
{
	int X;
	int Y;
};

extern FVector2i PlayerPosition;

int Input();
void Tick(int KeyCode);
void Clear();
void Render();
void GotoXY(int x, int y);
void AddPlayerOffset(int DeltaX, int DeltaY);
void AddPlayerOffset(FVector2i DeltaPosition);