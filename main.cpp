#include <iostream>
#include <algorithm>

#define NUMBER_SIZE 30
#define PICK_NUMBER_SIZE 6

/*
배열을 초기화
Numbers : int 배열
Size : 배열의 크기
*/
void Init(int* Numbers, int Size);

/*
배열을 랜덤하게 섞음
Numbers : int 배열
Size : 배열의 크기
*/
void Shuffle(int* Numbers, int Size);

/*
배열을 랜덤하게 뽑음
Numbers : 뽑을 배열
MuNumbers : 뽑은 int를 저장할 배열
Size : 뽑을 개수
*/
void PickNumbers(const int* Numbers, int* MyNumbers, int Size);

/*
배열을 출력
Numbers : 배열을 출력
Size : 배열의 크기
*/
void PrintMyNumbers(const int* Numbers, int Size);

int main()
{
	int* Numbers = new int[NUMBER_SIZE];
	int* MyNumbers = new int[PICK_NUMBER_SIZE];

	srand((unsigned int)time(nullptr));

	Init(Numbers, NUMBER_SIZE);
	//Shuffle(Numbers, NUMBER_SIZE);
	std::random_shuffle(&Numbers[0], &Numbers[NUMBER_SIZE]);
	PickNumbers(Numbers, MyNumbers, PICK_NUMBER_SIZE);
	PrintMyNumbers(Numbers, NUMBER_SIZE);
	PrintMyNumbers(MyNumbers, PICK_NUMBER_SIZE);
	
	delete[] Numbers;
	delete[] MyNumbers;
	Numbers = nullptr;
	MyNumbers = nullptr;

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
	for (int i = 0; i < Size * 10; ++i)
	{
		int FirstIndex = rand() % Size;
		int SecondIndex = rand() % Size;

		int Temp = Numbers[FirstIndex];
		Numbers[FirstIndex] = Numbers[SecondIndex];
		Numbers[SecondIndex] = Temp;
	}
}

void PickNumbers(const int* Numbers, int* MyNumbers, int Size)
{
	for (int i = 0; i < Size; ++i)
	{
		MyNumbers[i] = Numbers[i];
	}
}

void PrintMyNumbers(const int* Numbers, int Size)
{
	std::cout << "랜덤 숫자 " << Size << "개 : ";
	for (int i = 0; i < Size; ++i)
	{
		std::cout << Numbers[i] << " ";
	}
	std::cout << std::endl;
}
