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
	for (int Index = 0; Index < Lottery_Balls; Index++)
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
	cout << "보너스 번호 : " << Lottery[6] << endl;
	cout << endl;
}
void PrizeCondition()
{

	// 1등 : 6개 일치
	// 2등 : 5개 + 보너스 번호
	// 3등 : 5개 일치
	// 4등 : 4개 일치
	// 5등 : 3개 일치
	// 꽝 : 2개 이하
	int MatchCount = 0;
	bool Bonus_Match = false;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (User[i] == Lottery[j])
			{
				MatchCount++;
				break;
			}
		}
		if (User[i] == Lottery[6])
		{
			Bonus_Match = true;
		}
	}

	if (MatchCount == 6)
	{
		cout << "1등입니다!" << endl;
	}
	else if (MatchCount == 5 && Bonus_Match)
	{
		cout << "2등입니다!" << endl;
	}
	else if (MatchCount == 5)
	{
		cout << "3등입니다!" << endl;
	}
	else if (MatchCount == 4)
	{
		cout << "4등입니다!" << endl;
	}
	else if (MatchCount == 3)
	{
		cout << "5등입니다!" << endl;
	}
	else
	{
		cout << "꽝입니다!" << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	Initialize();
	Shuffle();
	UserNumber();
	Result();
	PrizeCondition();

	return 0;
}