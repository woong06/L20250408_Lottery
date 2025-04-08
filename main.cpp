#include <iostream>

#define Lottery_Balls 45

using namespace std;

int Lottery[Lottery_Balls] = { 0, };
int User[6] = { 0, };

// 초기화
void Initialize()
{

	for (int Index = 0; Index < Lottery_Balls; Index++)
	{
		Lottery[Index] = Index + 1;
	}
}
// 섞기
void Shuffle()
{
	int temp = 0;
	for (int Index = 1; Index < Lottery_Balls + 1; Index++)
	{
		int Random = rand() % Lottery_Balls;
		temp = Lottery[Index];
		Lottery[Index] = Lottery[Random];
		Lottery[Random] = temp;
	}
}
// 사용자 번호 입력
void UserNumber()
{
	cout << "로또 번호를 입력하세요 : ";
	for (int Count = 0; Count < 6; Count++)
	{
		cin >> User[Count];
		if (User[Count] < 1 || User[Count] > 45)
		{
			cout << "잘못된 번호입니다.";
		}
	}
	cout << endl;
}
// 결과
void Result()
{
	cout << "로또 번호 : ";
	for (int Count = 0; Count < 6; Count++)
	{
		cout << Lottery[Count] << " ";
	}
	cout << endl;
}
// 1등 : 6개 일치
// 2등 : 5개 + 보너스 번호
// 3등 : 5개 일치
// 4등 : 4개 일치
// 5등 : 3개 일치
// 꽝 : 2개 이하

int main()
{
	Initialize();
	Shuffle();
	UserNumber();
	Result();

	return 0;
}