#include <iostream>
#include <algorithm>

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
	int NumberSize = 0;
	int PickSize = 0;
	std::cout << "총 공의 개수를 입력 : ";
	std::cin >> NumberSize;

	std::cout << "뽑을 공의 개수를 입력 : ";
	std::cin >> PickSize;

	int* Numbers = new int[NumberSize];
	int* MyNumbers = new int[PickSize];

	Init(Numbers, NumberSize);
	// Shuffle(Numbers, NUMBER_SIZE);
	std::random_shuffle(&Numbers[0], &Numbers[NumberSize]);
	PickNumbers(Numbers, MyNumbers, PickSize);
	// PrintMyNumbers(Numbers, NUMBER_SIZE);
	PrintMyNumbers(MyNumbers, PickSize);
	
	delete[] Numbers;
	delete[] MyNumbers;
	Numbers = nullptr;
	MyNumbers = nullptr;

	return 0;
}

void Init(int* Numbers, int Size)
{
	// 초기화 함수이기 때문에, srand 함수를 초기화에 넣는다
	srand((unsigned int)time(nullptr));

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
