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

	//포인터 과제
	int Size = 0;
	cin >> Size;
	int* DynamicArray = new int[Size];
	for (int i = 0; i < Size; i++)
	{
		DynamicArray[i] = i + 1;
	}
	for (int i = 0; i < Size; i++)
	{
		cout << DynamicArray[i];
	}
	cout << endl;
	delete[] DynamicArray;
	DynamicArray = nullptr;

	return 0;
}