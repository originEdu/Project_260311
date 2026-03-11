#include<iostream>

using namespace std;

//문자열 갯수 세기
int CountStringLength(char* string);

// 문자열 중에서 특정 문자를 특정문 바꾸기
void ChangeCertainString(char TargetChar, char ReplaceChar, char* String);

//문자열 중에서 특정 문자 위치 찾기
int* SeachTargetCharPlace(char TargetChar, char* String);

//특정 문자의 위치를 가진배열 출력
void PrintPlaceArray(int* PlaceArray);

int main()
{
	/*
	
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


	char test[10] = "abcabbbbc";
	cout << "CountStringLength: " << CountStringLength(test) << endl;

	ChangeCertainString('a', 'e',test);
	cout << "ChangeCertainString: " << test << endl;

	cout << "SeachTargetCharPlace c:";
	int* TempArrayPointer = SeachTargetCharPlace('c', test);
	PrintPlaceArray(TempArrayPointer);
	cout << endl;
	delete[] TempArrayPointer;

	cout << "SeachTargetCharPlace s:";
	int* TempArrayPointer2 =SeachTargetCharPlace('s', test);
	PrintPlaceArray(TempArrayPointer2);
	cout << endl;
	delete[] TempArrayPointer2;
	return 0;
}

//문자열 갯수 세기 -> 이게 무슨말일까
//                    1, "geg", '2', 56, "asqzxc" 이런식으로 저장된 배열에서 문자열의 갯수를 찾는건가?
// 일단 주어진 문자배열의 길이를 구하는 함수
int CountStringLength(char* String)
{
	int MaxStringLength = 256;  //입력받을 수 있는 문자의 최대길이
	                            //일단 최대 넘어가는 문자입력 제외
	int LengthCount = 0;
	for (int i = 0; i < MaxStringLength; i++)
	{
		if (String[i] == '\0')
		{
			break;
		}
		LengthCount++;
	}
	return LengthCount;
}

//문자열 중에서 특정 문자를 특정문 바꾸기 -> 한글자만 바꾸는 것인지 아니면 문자열로 바꾸는 것인지 확인
//일단 한글자만 바꾸는 것으로
void ChangeCertainString(char TargetChar, char ReplaceChar, char* String)
{
	int StringLength = CountStringLength(String);
	for (int i = 0; i < StringLength; i++)
	{
		if (String[i] == TargetChar)
		{
			String[i] = ReplaceChar;
		}
	}
}

//문자열 중에서 특정 문자 위치 찾기 -> 제일 먼저 찾은 위치 반환할지, 찾은 위치 모두 반환할지
//일단 제일 먼저 찾은 위치 반환하는 걸로 -> 찾은 위치 모두 반환하는 코드로 변경함
int* SeachTargetCharPlace(char TargetChar, char* String)
{
	int StringLength = 0; 
	StringLength = CountStringLength(String);
	int* PlaceArray = new int[256]; //찾은 문자 위치 저장하는 배열, 일단 문자 최대값 -> 나중에 동적할당
	int ArrayIndex = 0; //PlaceArray의 인덱스
	for (int i = 0; i < 256; i++) //찾는 것이 없을시 구분 + 출력을 위해 모든값에 -1 삽입
	{
		PlaceArray[i] = -1;
	}
	
	for (int i = 0; i < StringLength; i++)
	{
		if (String[i] == TargetChar)
		{
			PlaceArray[ArrayIndex] = i + 1;
			ArrayIndex++;
		}
	}
	
	return PlaceArray;
}

//찾은 문자 위치 저장하는 배열 출력 함수
void PrintPlaceArray(int* PlaceArray)
{

	for (int i = 0; i < 256;i++) //최대길이 256이니깐
	{
		if (PlaceArray[i] == -1)
		{
			break;
		}
		else 
		{
			cout << " " << PlaceArray[i];
		}
	}
}