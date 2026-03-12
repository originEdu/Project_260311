#include<iostream>
#include "StringUtil.h"
#include "PocketUtil.h"
#include <conio.h>
#include <windows.h>
using namespace std;

//맵 전역변수로 생성
int Map[10][10] =
{
	 {1,1,1,1,1,1,1,1,1,1}
	,{1,0,0,0,0,0,0,0,0,1}
	,{1,0,0,0,0,0,0,0,0,1}
	,{1,0,0,0,0,0,0,0,0,1}
	,{1,0,0,0,0,0,0,0,0,1}
	,{1,0,0,0,0,0,0,0,0,1}
	,{1,0,0,0,0,0,0,0,0,1}
	,{1,0,0,0,0,0,0,0,0,1}
	,{1,0,0,0,0,0,0,0,0,1}
	,{1,1,1,1,1,1,1,1,1,1}
};

//플레이어 생성 -> //초기 위치 1,1 
//구조체나 클래스사용금지
int PlayerX = 1;
int PlayerY = 1;

//int Direct[4][2] =
//{
//	 { 1, 0} //UP
//	,{-1, 0} //Down
//	,{ 0, 1} //Right
//	,{ 0,-1} //Left
//};

#define ESC 27
void UpdatePlayerPlace(int Input);
void Rander();
void Gotoxy(int x, int y);

int main()
{

	char Input;
	while(true){
		Rander();
		Input = _getch();
		if (Input == ESC)
		{
			cout << "End!";
			break;
		}
		//플레이어 위치조정
		UpdatePlayerPlace(Input);//wasd로 이동 -> 이동시 벽이면 움직임 막자
		
	}
	
	return 0;
}

void Rander()
{
	//system("cls"); //화면 클리어
	Gotoxy(0, 0); //화면 클리어 업그레이드
	//이중포문으로 1이면 *호출
	//0이면 빈공간
	//만약 플레이어 XY와 위치가 같다면 P소환
	for (int y=0; y < 10; y++)
	{
		for (int x=0; x < 10; x++)
		{
			if ((PlayerY == y) && (PlayerX == x))
			{
				cout << "P";
			}
			else if (Map[y][x] == 1)
			{
				cout << "*";
			}
			else if (Map[y][x] == 0)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}

void UpdatePlayerPlace(int Input)
{
	if (Input == 'w') // UP
	{
		if (PlayerY<9 && PlayerY>1)
		{
			PlayerY--;
		}
	}
	if (Input == 's') // Down
	{
		if (PlayerY < 8 && PlayerY>0)
		{
			PlayerY++;
		}
	}
	if (Input == 'a') // Left
	{
		if (PlayerX < 9 && PlayerX>1)
		{
			PlayerX--;
		}
	}
	if (Input == 'd') // Right
	{
		if (PlayerX < 8 && PlayerX>0)
		{
			PlayerX++;
		}
	}
}

void Gotoxy(int x, int y) {
	COORD Pos = {(SHORT)x,(SHORT)y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

/* 수업내용
	//포인터설명
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

	//무작위 공뽑기 과제
	int Size = 45; //공 크기
	int* Pocket= CreatePocket(Size); //주머니 생성
	int* SuffledPocket = CreatePocket(Size); //주머니 생성

	SynchronizingPocket(Pocket, SuffledPocket, Size); //Pocket과 SuffledPocket 동기화
													  //물론 지금은 의미없는 행위
	Shuffle(SuffledPocket,Size); //공 셔플
	PullOut(SuffledPocket, 6); //공 뽑기

	//동적할당해제
	delete[] Pocket;
	delete[] SuffledPocket;
	Pocket = nullptr;
	SuffledPocket = nullptr;
*/
