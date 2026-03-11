#include<iostream>

using namespace std;
int main()
{
	int A = 10;
	//P는 별명, 정수형 변수의 주소를 기억하는 숫자 공간을 요청
	int* P = &A; //A 변수에 주소를 주세요, 정수형 변수A의 주소를 주세요
	int* P2 = nullptr;

	P2 = P;
	/*cout << "&A:" << &A << endl;
	cout << "P:" << P << endl;
	cout << "P2:" << P2 << endl;*/

	*P2=30; //-> P2라는 변수는 몬지 모르지만 다른 변수의 위치를 기억하는 변수
	//P2가 가르키는 녀석을 30으로 교체
	cout << "*P:" << *P << endl;
	//P가 가르키는 녀석도 30으로 출력됨
	cout << "*P2:" << *P2 << endl;
	return 0;
}