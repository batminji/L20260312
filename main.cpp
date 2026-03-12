#include <iostream>

void Init(int* Numbers);
void Shuffle(int* Numbers);
void PickNumbers(int* Numbers, int* MyNumbers);
void PrintMyNumbers(int* MyNumbers);

int main()
{
	int Numbers[45] = { 0, };
	int MyNumbers[6] = { 0, };

	Init(Numbers);
	Shuffle(Numbers);
	PickNumbers(Numbers, MyNumbers);
	PrintMyNumbers(MyNumbers);

	return 0;
}

void Init(int* Numbers)
{
	for (int i = 0; i < 45; ++i)
	{
		Numbers[i] = i + 1;
	}
}

void Shuffle(int* Numbers)
{
	srand((unsigned int)time(nullptr));

	for (int i = 0; i < 100; ++i)
	{
		int FirstIndex = rand() % 45;
		int SecondIndex = rand() % 45;

		int Temp = Numbers[FirstIndex];
		Numbers[FirstIndex] = Numbers[SecondIndex];
		Numbers[SecondIndex] = Temp;
	}
}

void PickNumbers(int* Numbers, int* MyNumbers)
{
	for (int i = 0; i < 6; ++i)
	{
		MyNumbers[i] = Numbers[i];
	}
}

void PrintMyNumbers(int* MyNumbers)
{
	std::cout << "·£´ı ¼ıÀÚ 6°³ : ";
	for (int i = 0; i < 6; ++i)
	{
		std::cout << MyNumbers[i] << " ";
	}
	std::cout << std::endl;
}
