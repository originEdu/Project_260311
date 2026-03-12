#include<iostream>

/*
* 주머니 초기화
* 인자 : 주머니 사이즈
* 반환값 : 배열의 주소
*/
int* CreatePocket(int Size)
{
	int* InitPocket = new int[Size]; //Size개의 공 생성

	for (int i = 0; i < Size; i++) // InitPocket 초기화
	{
		InitPocket[i] = i + 1;
	}

	return InitPocket;
}

/*
* 두 주머니 동기화
* 인자 : 기준 주머니, 동기화할 주머니, 크기
* 반환값 : X
*/
void SynchronizingPocket(int* BasePocket, int* TargetPocket, int Size)
{
	for (int i = 0; i < Size; i++) // BasePocket와 TargetPocket 동기화
	{
		TargetPocket[i] = BasePocket[i];
	}
}

/*
* 주머니 셔플
* 인자 : 주머니, 크기
* 반환값 : X
*/
void Suffle(int* Pocket, int Size)
{
	srand((unsigned)time(nullptr)); //시드 초기화
	int Temp = 0; //셔플을 위한 공간
	int FirstIndex = 0;
	int SecondIndex = 0;
	for (int i = 0; i < Size * 4; i++) //Size*4 횟수로 섞어주셈
	{
		FirstIndex = rand() % 45;
		SecondIndex = rand() % 45;

		//Swap
		Temp = Pocket[FirstIndex];
		Pocket[FirstIndex] = Pocket[SecondIndex];
		Pocket[SecondIndex] = Temp;
	}
}

/*
* 공 뽑기
* 인자 : 주머니, 뽑을 횟수
* 반환값 : X
* 뽑은 주머니 번호 콘솔출력
*/
void PullOut(int* SuffledPocket, int Number)
{
	std::cout << "뽑은 공 숫자:";
	for (int i = 0; i < Number; i++)
	{
		std::cout << " " << SuffledPocket[i];
	}
	std::cout << std::endl;
}