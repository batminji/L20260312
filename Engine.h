#pragma once

extern int Map[10][10];

extern int PlayerX;
extern int PlayerY;

int Input();
void Tick(int KeyCode);
void Clear();
void Render();
void GotoXY(int x, int y);
void AddPlayerOffset(int DeltaX, int DeltaY);