#include<iostream>

//문자열 갯수 세기 -> 이게 무슨말일까
//                    1, "geg", '2', 56, "asqzxc" 이런식으로 저장된 배열에서 문자열의 갯수를 찾는건가?
// 일단 주어진 문자배열의 길이를 구하는 함수
int StringLength(char* String, int InputMaxLength)
{
	int Length = 0;
	for (int i = 0; i < InputMaxLength; i++)
	{
		if (String[i] == '\0')
		{
			break;
		}
		Length++;
	}
	return Length;
}

//문자열 중에서 특정 문자를 특정문 바꾸기 -> 한글자만 바꾸는 것인지 아니면 문자열로 바꾸는 것인지 확인
//일단 한글자만 바꾸는 것으로
void ChangeCertainChar(char* String, int Size, char TargetChar, char ReplaceChar)
{
	for (int i = 0; i < Size; i++)
	{
		if (String[i] == TargetChar)
		{
			String[i] = ReplaceChar;
		}
	}
}

//문자열 중에서 특정 문자 위치 찾기 -> 제일 먼저 찾은 위치 반환할지, 찾은 위치 모두 반환할지
//일단 제일 먼저 찾은 위치 반환하는 걸로 -> 찾은 위치 모두 반환하는 코드로 변경함
int* SeachTargetCharPlace(char* String, int Size, char TargetChar)
{
	int* PlaceArray = new int[Size]; //찾은 문자 위치 저장하는 배열, 일단 문자 최대값 -> 나중에 동적할당
	int ArrayIndex = 0; //PlaceArray의 인덱스
	for (int i = 0; i < Size; i++) //찾는 것이 없을시 구분 + 출력을 위해 모든값에 -1 삽입
	{
		PlaceArray[i] = -1;
	}

	for (int i = 0; i < Size; i++)
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
void PrintPlaceArray(int* PlaceArray, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		if (PlaceArray[i] == -1)
		{
			break;
		}
		else
		{
			std::cout << " " << PlaceArray[i];
		}
	}
}