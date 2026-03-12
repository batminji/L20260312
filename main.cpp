#include <iostream>
#include "Engine.h"

int main()
{
	bool bIsRunning = true;

	while (bIsRunning) // Frame
	{
		int KeyCode = Input();
		Tick(KeyCode);
		Render();
	}
}