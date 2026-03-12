# gitignore 실수한 프로젝트

# main.cpp
- 포인터 설명 코드
- 문자열 과제 -> StringUtil.cpp 참고
- 포인터 과제
- 공뽑기 과제 -> PocketUtil.cpp 참고

# StringUtil.cpp
- 문자열 갯수 세기 함수 -> int StringLength(char* String, int InputMaxLength);
- 문자열 중에서 특정 문자를 특정 문자로 바꾸기 함수 -> void ChangeCertainChar(char* String, int Size, char TargetChar, char ReplaceChar);
- 문자열 중에서 특정 문자 위치 찾기 함수 구현 -> int* SeachTargetCharPlace(char* String, int Size, char TargetChar);
- 특정 문자의 위치를 가진배열 출력 함수 구현 -> void PrintPlaceArray(int* PlaceArray, int Size);

# PocketUtil.cpp
- 주머니 초기화 함수 -> int* CreatePocket(int Size)
- 두 주머니 동기화 함수 -> void SynchronizingPocket(int* BasePocket, int* TargetPocket, int Size); 
- 주머니 셔플 함수 -> void Suffle(int* Pocket, int Size); 
- 공 뽑기 함수 -> void PullOut(int* SuffledPocket, int Number);
