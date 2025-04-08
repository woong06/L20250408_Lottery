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
	for (int Index = 1; Index < Lottery_Balls + 1; Index++)
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
}
// 1�� : 6�� ��ġ
// 2�� : 5�� + ���ʽ� ��ȣ
// 3�� : 5�� ��ġ
// 4�� : 4�� ��ġ
// 5�� : 3�� ��ġ
// �� : 2�� ����

int main()
{
	Initialize();
	Shuffle();
	UserNumber();
	Result();

	return 0;
}