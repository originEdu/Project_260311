#pragma once


//문자열 갯수 세기
int StringLength(char* String, int InputMaxLength);

// 문자열 중에서 특정 문자를 특정문 바꾸기
void ChangeCertainChar(char* String, int Size, char TargetChar, char ReplaceChar);

//문자열 중에서 특정 문자 위치 찾기
int* SeachTargetCharPlace(char* String, int Size, char TargetChar);

//특정 문자의 위치를 가진배열 출력
void PrintPlaceArray(int* PlaceArray, int Size);