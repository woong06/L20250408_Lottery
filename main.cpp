#include <iostream>

#define Lottery_Balls 45

using namespace std;

int Lottery[Lottery_Balls] = { 0, };
int User[6] = { 0, };

// �ʱ�ȭ
void Initialize()
{

	for (int Index = 0; Index < Lottery_Balls; Index++)
	{
		Lottery[Index] = Index + 1;
	}
}
// ����
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
// ����� ��ȣ �Է�
void UserNumber()
{
	cout << "�ζ� ��ȣ�� �Է��ϼ��� : ";
	for (int Count = 0; Count < 6; Count++)
	{
		cin >> User[Count];
		if (User[Count] < 1 || User[Count] > 45)
		{
			cout << "�߸��� ��ȣ�Դϴ�.";
		}
	}
	cout << endl;
}
// ���
void Result()
{
	cout << "�ζ� ��ȣ : ";
	for (int Count = 0; Count < 6; Count++)
	{
		cout << Lottery[Count] << " ";
	}
	cout << endl;
	cout << "���ʽ� ��ȣ : " << Lottery[6] << endl;
	cout << endl;
}
void PrizeCondition()
{

	// 1�� : 6�� ��ġ
	// 2�� : 5�� + ���ʽ� ��ȣ
	// 3�� : 5�� ��ġ
	// 4�� : 4�� ��ġ
	// 5�� : 3�� ��ġ
	// �� : 2�� ����
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
		cout << "1���Դϴ�!" << endl;
	}
	else if (MatchCount == 5 && Bonus_Match)
	{
		cout << "2���Դϴ�!" << endl;
	}
	else if (MatchCount == 5)
	{
		cout << "3���Դϴ�!" << endl;
	}
	else if (MatchCount == 4)
	{
		cout << "4���Դϴ�!" << endl;
	}
	else if (MatchCount == 3)
	{
		cout << "5���Դϴ�!" << endl;
	}
	else
	{
		cout << "���Դϴ�!" << endl;
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