#include "��������� 2.0.h"

// 1-49 2-50 3-51 4-52 5-55 6-56 ...
void questions(v& v_)
{
	int en = 0, k = -1;

		for (size_t i = 0; i < 10; i++)
		{
			mciSendString(TEXT("play gong.mp3"), NULL, 0, NULL);
			Sleep(200);
			do
			{	
				if (k!=2)//��� ������������� ������ ����� ���� �� �������
					system("cls");
				
				gotoxy(0, 0);
				SetColor(6, 0);
				std::cout << v_.qw[i];
				SetColor(11, 0);
				if (k==2 || k==3)
				{
					SetColor(3, 0);
				}

				//����� ��������� �������
				for (size_t j = 1; j < 6; j++)
				{
					if (0 < j && j < 5)
					{
						if (k != 3)//���� �� ������������ ��������� 50/50
						{
							std::cout << "\n" << v_.verios_answer[i][j - 1] << " ������� - " << j;
						}
						else if ((v_.true_and_false_answer[1][i] == j || v_.true_and_false_answer[0][i] == j) && k == 3)//���� ������������ ��������� 50/50 ������� ������ �����������
						{
							std::cout << "\n" << v_.verios_answer[i][j - 1] << " ������� - " << j;
						}

					}
					else if (j == 5 && k!=2 && k!=3 && (v_.call_friend_and_fifty_fifty[1] == true || v_.call_friend_and_fifty_fifty[0] == true))/*)*/
					{
						if (k != 3)//���� �� ������������ ��������� 50/50
						{
							std::cout << "\n" << "������� ���������" << " ������� - " << j;
						}
					}
				}
				SetColor(7, 0);
				//�������� ������������
				en = _getch();

				switch (en)
				{
					case 49://1
					{
						if (k != 3)//���� �� ������������ ��������� 50/50
						{
							if (1 == v_.true_and_false_answer[0][i])//�������� ������
								k = 1;
							else
								k = 0;
						}
						else if ((v_.true_and_false_answer[1][i] == 1 || v_.true_and_false_answer[0][i] == 1) && k == 3)//���� ������������ ��������� 50/50 ��������� ������ ��������� ������
						{
							if (1 == v_.true_and_false_answer[0][i])//�������� ������
								k = 1;
							else
								k = 0;
						}
						break;
					}
					case 50://2
					{
						if (k != 3)//���� �� ������������ ��������� 50/50
						{
							if (2 == v_.true_and_false_answer[0][i])//�������� ������
								k = 1;
							else
								k = 0;
						}

						else if ((v_.true_and_false_answer[1][i] == 2 || v_.true_and_false_answer[0][i] == 2) && k == 3)//���� ������������ ��������� 50/50 ��������� ������ ��������� ������
						{
							if (2 == v_.true_and_false_answer[0][i])//�������� ������
								k = 1;
							else
								k = 0;
						}						
						break;
					}
					case 51://3
					{
						if (k != 3)//���� �� ������������ ��������� 50/50
						{
							if (3 == v_.true_and_false_answer[0][i])//�������� ������
								k = 1;
							else
								k = 0;
						}
						else if ((v_.true_and_false_answer[1][i] == 3 || v_.true_and_false_answer[0][i] == 3) && k==3)//���� ������������ ��������� 50/50 ��������� ������ ��������� ������
						{
							if (3 == v_.true_and_false_answer[0][i])//�������� ������
								k = 1;
							else
								k = 0;
						}
						

						break;
					}
					case 52://4
					{
						if (k != 3)//���� �� ������������ ��������� 50/50
						{
							if (4 == v_.true_and_false_answer[0][i])//�������� ������
								k = 1;
							else
								k = 0;
						}
						else if ((v_.true_and_false_answer[1][i] == 4 || v_.true_and_false_answer[0][i] == 4) && k == 3)//���� ������������ ��������� 50/50 ��������� ������ ��������� ������
						{
							if (4 == v_.true_and_false_answer[0][i])//�������� ������
								k = 1;
							else
								k = 0;
						}
						break;
					}
					case 53://5
					{	if (k != 3 && k != 2)
							k = 7;//������ ����� ����� ��������� ��� ��������� ������ ���� ��� ������ 5(5 �������� �� ���������) ������� ���������� �����. �.�. �� ����� � k ��������� 1 � ��������� ���� �� �������� � if �� ������  138
						if (k != 3 && k != 2)//���� �� ������������ ��������� 50/50
						{
							if ((v_.call_friend_and_fifty_fifty[1] == true || v_.call_friend_and_fifty_fifty[0] == true) && k != 2)
								k = hints(v_, i);
						}

						break;
					}
				}

			} while (k!=1 && k!=0);
			//��� ����� ������ 
			if (k == 1)
			{
				//���������� �����
				if (i != 0)
					v_.profit *= 2;
				else if (i == 0)
					v_.profit = 10;

				mciSendString(TEXT("play correct.mp3 wait"), NULL, 0, NULL);
				Sleep(500);
				if (i!=9)//��� ��� ��������� ��������� ������ �� ������� ��� ����� ������ �� ���� 
				{
					system("cls");
					SetColor(6, 0);
					std::cout << "���������� ��� ������� " <<  v_.profit << " ����� � �����? ��� � ��� ������?";
					SetColor(3, 0);
					std::cout << "\n���������� - 1\n������� ��� ��� ���������� � ����� - 2";
					SetColor(7, 0);
					//�������� ������������
					do
					{
						en = _getch();

						if (en == 49)
						{
							NULL;
							break;
						}
						else if (en == 50)
						{
							en = -1;
							break;
						}
					} while (en!=-1);
					if (en == -1)
					{
						break;
					}
				}
			} 
			//��� ����� ������
			else if (k==0)
			{
				mciSendString(TEXT("close background_music.mp3"), NULL, 0, NULL);
				mciSendString(TEXT("play wrong.mp3 wait"), NULL, 0, NULL);
				v_.profit = 0;
				break;
			}
		}
}

//���� �� ��������� � �� ����� �� ���� ��������������� �����.
int hints(v& v_, int i)
{
	//v_.call_friend_and_fifty_fifty[0] - ������ ����� 
	//v_.call_friend_and_fifty_fifty[1] - ������ 50/50
	int en, k=6;//-2 ���� ��� ������� 
	do
	{

		SetColor(10, 0);
		if (v_.call_friend_and_fifty_fifty[0] == true)
			std::cout << "\n" << " - �������� � �����" << " ������� - 1";

		if (v_.call_friend_and_fifty_fifty[1] == true)
			std::cout << "\n" << " - ������� ������ 50/50" << " ������� - 2";

		std::cout << "\n" << " - ������� ���������" << " ������� - 3";
		SetColor(7, 0);

		en = _getch();

		switch (en)
		{
			case 49:
			{	
				if (v_.call_friend_and_fifty_fifty[0] == true)//���� ����� ��� ��� ������������� �� ��������� ��������
				{
					call_friend(v_.true_and_false_answer[0][i]);//������� ������ ������ �����
					v_.call_friend_and_fifty_fifty[0] = false;//��������� ������������
					k = 2; // ���� ��� �� system("cls"); �� ����
					
				}
			break;
			}
			case 50:
			{
				if (v_.call_friend_and_fifty_fifty[1] == true)//���� ����� ��� ��� ������������� �� ��������� ��������
				{
					k = 3;//����� � ������� questions �������� � ��������� �������� ������ ��� ���� ������������ ������� 
					v_.call_friend_and_fifty_fifty[1] = false;//��������� ������������
				}

				break;
			}
			case 51:
			{
				k = -1;//����� ������ � ��������� 
				break;
			}
			default:
			{
				k = NULL; //���� ������ �� ������ ������ �������
				break;
			}
		}
	} while (k != 1 && k != 0 && k != -1 && k !=2 && k != 3);

	return k;
}

//������ ����� "20%" ��� ����������� 
void call_friend(int tr_ans)
{
	switch (rand() % 3)
	{
	case 0:
		mciSendString(TEXT("play sms1.mp3 "), NULL, 0, NULL);
		break;
	case 1:
		mciSendString(TEXT("play sms2.mp3 "), NULL, 0, NULL);
		break;
	case 2:
		mciSendString(TEXT("play sms3.mp3 "), NULL, 0, NULL);
		break;
	}
	SetColor(13, 0);
	std::cout << "\n\n�������� 1 ����� ���������!";

	int rand_namber = rand() % 10, rand_namber1 = rand() % 10;

	if (rand_namber != rand_namber1 || rand_namber != rand_namber1)
	{
		std::cout << "\n������, ������ ���� ����� ����� " << tr_ans << " �� ������ ����� � ������ ��������� ����������))";
	}
	else 
	{
		switch (tr_ans)
		{
		case 1:
			rand_namber = rand() % 3;
			switch (rand_namber)
			{
			case 0:
				std::cout << "\n������, � ������ ������ � �� ����� ������, �� ��� ������� ����� 2 ";
				break;
			case 1:
				std::cout << "\n�������, ���������� ��� ����� � ��� ���������! �� ���� ������� �� ������, �������� ��� 3 ";
				break;
			case 2:
				std::cout << "\n����������, ��������� �������, �� � ��� ��� �� ������� �����, ��� ��� ��� �������� ����� 4 ";
				break;
			}
			break;
		case 2:
			rand_namber = rand() % 3;
			switch (rand_namber)
			{
			case 0:
				std::cout << "\n������, � ������ ������ � �� ����� ������, �� ��� ������� ����� 1 ";
				break;
			case 1:
				std::cout << "\n�������, ���������� ��� ����� � ��� ���������! �� ���� ������� �� ������, �������� ��� 4 ";
				break;
			case 2:
				std::cout << "\n����������, ��������� �������, �� � ��� ��� �� ������� �����, ��� ��� ��� �������� ����� 3 ";
				break;
			}
			break;
		case 3:
			rand_namber = rand() % 3;
			switch (rand_namber)
			{
			case 0:
				std::cout << "\n������, � ������ ������ � �� ����� ������, �� ��� ������� ����� 4 ";
				break;
			case 1:
				std::cout << "\n�������, ���������� ��� ����� � ��� ���������! �� ���� ������� �� ������, �������� ��� 2 ";
				break;
			case 2:
				std::cout << "\n����������, ��������� �������, �� � ��� ��� �� ������� �����, ��� ��� ��� �������� ����� 1 ";
				break;
			}
			break;
		case 4:
			rand_namber = rand() % 3;
			switch (rand_namber)
			{
			case 0:
				std::cout << "\n������, � ������ ������ � �� ����� ������, �� ��� ������� ����� 2 ";
				break;
			case 1:
				std::cout << "\n�������, ���������� ��� ����� � ��� ���������! �� ���� ������� �� ������, �������� ��� 3 ";
				break;
			case 2:
				std::cout << "\n����������, ��������� �������, �� � ��� ��� �� ������� �����, ��� ��� ��� �������� ����� 1 ";
				break;
			}
			break;
		}
	}
	SetColor(7, 0);
}

// ������� ����
void rools()
{
	mciSendString(TEXT("play start.mp3"), NULL, 0, NULL);
	std::cout << std::setw(70) << "�������!" << "\n\n��� ������ ���� ������ ��������� �������� �� �������, ���� ��������� ���� ����������� � ��� �������� ������.\n�� �� ������������� � ��� ���� ���� ������ �����(������� �������� ��� �������) � ������ 50/50(��� ����� � ������� �������� ���� ���������� � ���� ����������� ),\n�� ���� ��� ����� ������������ ���-������ ����";
	std::cout << "\n\n�� ����� ����� �������, ���� �� � ������ �� ���� ������, � �� �������! �� ������ ���������� ����� �� ��������� 10 �����, \n�� ������ ��������� ���������� �����, ���������� ������������� � ����!";
	std::cout << "\n\n����� ������ ������� �� ����� ������ �� ����������";
	_getch();
	mciSendString(TEXT("close start.mp3"), NULL, 0, NULL);

}

//���������� ���� 
void end(v& v_)
{
	mciSendString(TEXT("play end.mp3"), NULL, 0, NULL);

	if (v_.profit == 0)
		std::cout << "\n\n� ��������� �� ���������\n�� ��� �� ����� ������������� ���� � ����� ���� ����� ���� �����������! ����� � �����!";

	else if (v_.profit > 0)
	{
		if (v_.profit < 10240)
			std::cout << "\n� ��������� �� ��������� ��� ������ �������, � ���� ���� �������� ����������!";
		std::cout << "\n��� ���� ���������� " << v_.profit << " �����";
		std::cout << "\n��� ������������!!!";
	}
	std::cout << "\n\n����� ������� ������� �� ����� ������ �� ����������";
	_getch();
}

enum ConsoleColor {
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void gotoxy(short x, short y)
{
	COORD coord = { x, y };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, coord);
}

//���� ����� �������� ��-�� ����� �����(����� ������� �� ���������� ������������� ������� �� ������ ���� �� ���� �����) 
//������� ���������� ����� ������� en = _getch(); � � ��������� ������ ����� _getch(); 

//void click()
//{
//	switch (rand() % 3)
//	{
//	case 0:
//		mciSendString(TEXT("play click1.mp3 wait"), NULL, 0, NULL);
//		break;
//	case 1:
//		mciSendString(TEXT("play click2.mp3 wait"), NULL, 0, NULL);
//		break;
//	case 2:
//		mciSendString(TEXT("play click3.mp3 wait"), NULL, 0, NULL);
//		break;
//	}
//}