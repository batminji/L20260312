#include <iostream>
#include <algorithm>

#define NUMBER_SIZE 45
#define PICK_NUMBER_SIZE 6

void Init(int* Numbers, int Size);
void Shuffle(int* Numbers, int Size);
void PickNumbers(int* Numbers, int* MyNumbers, int Size);
void PrintMyNumbers(int* MyNumbers, int Size);

int main()
{
	int* Numbers = new int[NUMBER_SIZE];
	int* MyNumbers = new int[PICK_NUMBER_SIZE];

	Init(Numbers, NUMBER_SIZE);
	//Shuffle(Numbers, NUMBER_SIZE);
	std::random_shuffle(&Numbers[0], &Numbers[NUMBER_SIZE - 1]);
	PickNumbers(Numbers, MyNumbers, PICK_NUMBER_SIZE);
	PrintMyNumbers(MyNumbers, PICK_NUMBER_SIZE);

	return 0;
}

void Init(int* Numbers, int Size)
{
	for (int i = 0; i < Size; ++i)
	{
		Numbers[i] = i + 1;
	}
}

void Shuffle(int* Numbers, int Size)
{
	srand((unsigned int)time(nullptr));

	for (int i = 0; i < Size * 10; ++i)
	{
		int FirstIndex = rand() % Size;
		int SecondIndex = rand() % Size;

		int Temp = Numbers[FirstIndex];
		Numbers[FirstIndex] = Numbers[SecondIndex];
		Numbers[SecondIndex] = Temp;
	}
}

void PickNumbers(int* Numbers, int* MyNumbers, int Size)
{
	for (int i = 0; i < Size; ++i)
	{
		MyNumbers[i] = Numbers[i];
	}
}

void PrintMyNumbers(int* MyNumbers, int Size)
{
	std::cout << "·£´ý ¼ýÀÚ 6°³ : ";
	for (int i = 0; i < Size; ++i)
	{
		std::cout << MyNumbers[i] << " ";
	}
	std::cout << std::endl;
}
