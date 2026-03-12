#include<iostream>
#include "StringUtil.h"
using namespace std;


int main()
{
	/* 포인터설명

	int A = 10;
	//P는 별명, 정수형 변수의 주소를 기억하는 숫자 공간을 요청
	int* P = &A; //A 변수에 주소를 주세요, 정수형 변수A의 주소를 주세요
	int* P2 = nullptr;

	P2 = P;
	cout << "&A:" << &A << endl;
	cout << "P:" << P << endl;
	cout << "P2:" << P2 << endl;

	*P2=30; //-> P2라는 변수는 몬지 모르지만 다른 변수의 위치를 기억하는 변수
	//P2가 가르키는 녀석을 30으로 교체
	cout << "*P:" << *P << endl;
	//P가 가르키는 녀석도 30으로 출력됨
	cout << "*P2:" << *P2 << endl;

	//배열과 포인터
	int Number[4] = { 1,2,3,4 };
	int* P3 = Number; // Number = &Number[0]
	cout << *(P3+1)<<endl;
	cout << *(Number + 1) << endl;
	cout << P3[1] << endl;
	cout << Number[1] << endl;
	
	*/

	/* 문자관련 과제
	char test[10] = "abcabbbbc";
	int length = StringLength(test,256); //입력최대글자 256
	cout << "StringLength: " << length << endl;

	ChangeCertainChar(test, length, 'a', 'e');
	cout << "ChangeCertainString: " << test << endl;

	cout << "SeachTargetCharPlace c:";
	int* TempArrayPointer = SeachTargetCharPlace(test, length,'c');
	PrintPlaceArray(TempArrayPointer, length);
	cout << endl;
	delete[] TempArrayPointer;
	TempArrayPointer = nullptr;

	cout << "SeachTargetCharPlace s:";
	int* TempArrayPointer2 =SeachTargetCharPlace(test, length,'s');
	PrintPlaceArray(TempArrayPointer2, length);
	cout << endl;
	delete[] TempArrayPointer2;
	TempArrayPointer2 = nullptr;
	*/

	/*
	//포인터 과제
	int Size = 0;
	cin >> Size;
	int* DynamicArray = new int[Size];
	//예외처리
	if (DynamicArray == nullptr) // -> if(DynamicArray)이거랑 같은거임
	{
		return -1;
	}
	//값 대입
	for (int i = 0; i < Size; i++)
	{
		DynamicArray[i] = i + 1;
	}
	//값 출력
	for (int i = 0; i < Size; i++)
	{
		cout << DynamicArray[i];
	}
	cout << endl;
	delete[] DynamicArray;
	DynamicArray = nullptr;
	*/

	//무작위 공뽑기 과제
	int InitPocket[45] = { 0 }; //45개의 공 생성
	int SuffledPocket[45] = { 0 };
	for (int i = 0; i < 45; i++) // InitPocket 45개의 공 초기화
	{
		InitPocket[i] = i+1;
	}
	for (int i = 0; i < 45; i++) // SuffledPocket와 InitPocket 동기화
	{
		SuffledPocket[i] = InitPocket[i];
	}

	//45개의 공 셔플
	srand((unsigned)time(nullptr)); //시드 초기화
	int Temp = 0; //셔플을 위한 공간
	int FirstIndex = 0;
	int SecondIndex = 0;
	for (int i = 0; i < 180; i++) //대충 적당한 횟수로 섞어주셈
	{
		FirstIndex = rand() % 45;
		SecondIndex = rand() % 45;

		//Swap
		Temp = SuffledPocket[FirstIndex];
		SuffledPocket[FirstIndex] = SuffledPocket[SecondIndex];
		SuffledPocket[SecondIndex] = Temp;
	}

	//6개의 공 뽑기
	cout << "뽑은 공 숫자:";
	for (int i = 0; i < 6; i++)
	{
		cout << " " << SuffledPocket[i];
	}
	cout << endl;
	return 0;
}