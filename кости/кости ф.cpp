#include "кости.h"

void play(data& d, int number_of_rounds)
{
	int a = 0;
	for (int i = 0; i < number_of_rounds; i++)
	{
		SetColor(14, 0);
		std::cout << "" << i + 1 << " раунд";

		mciSendString(TEXT("play gong.mp3 wait"), NULL, 0, NULL);
		std::cout << "\nБросок " << d.player1_ << "а";
		Sleep(500);

		mciSendString(TEXT("play bones.mp3"), NULL, 0, NULL);
		Sleep(500);
		a = rand() % 6 + 1;
		std::cout << "\n\nпервый кубик\n";
		print_kub(a);
		d.player1 += a;
		a = rand() % 6 + 1; 
		std::cout << "\n\nвторой кубик\n";
		print_kub(a);
		d.player1 += a;
		Sleep(2000);

		std::cout << "\n\nКол-во очков " << d.player1;

		std::cout << "\n\n\nНажмите на любую кнопку чтобы продолжить!";
		_getch();

		system("cls");
		//----------------------------------------------------------------------------------

		std::cout << i + 1 << " раунд";

		std::cout << "\n\nБросок " << d.player2_ << "а";
		Sleep(500);

		mciSendString(TEXT("play bones.mp3"), NULL, 0, NULL); 
		Sleep(500);
		a = rand() % 6 + 1; 
		std::cout << "\n\nпервый кубик\n";
		print_kub(a);
		d.player2 += a;
		a = rand() % 6 + 1; 
		std::cout << "\nвторой кубик\n";
		print_kub(a);
		d.player2 += a;
		Sleep(2000);

		std::cout << "\n\nКол-во очков " << d.player2;

		std::cout << "\n\n\nНажмите на любую кнопку чтобы продолжить!";
		_getch();

		system("cls");
	}
}

void end_play(data& d)
{
	mciSendString(TEXT("play gong.mp3"), NULL, 0, NULL);
	SetColor(4, 0);
	std::cout << "\nПодсчет очков! Подождите ...";
	Sleep(2000);
	system("cls");
	mciSendString(TEXT("play end.mp3"), NULL, 0, NULL);
	SetColor(14, 0);
	std::cout << "\n" << d.player1 << " кол-во очков у " << d.player1_;
	std::cout << "\n" << d.player2 << " кол-во очков у " << d.player2_;


	if (d.player2 > d.player1)
	{
		std::cout << "\n\nПобедил " << d.player2_;
	}
	else if (d.player2 < d.player1)
	{
		std::cout << "\n\nПобедил " << d.player1_;
	}
	else if (d.player2 == d.player1)
	{
		std::cout << "\n\nНичья\n";
	}

	std::cout << "\n\n\nНажмите на любую кнопку чтобы продолжить!";
	_getch();
}

void print_kub(int a)
{
	if (a==1)
	{
		SetColor(1, 0);
		std::cout << "o-------o\n|       |\n|   .   |\n|       |\no-------o";
		SetColor(14, 0);
	}
	else if (a == 2)
	{
		SetColor(5, 0);
		std::cout << "o-------o\n| .     |\n|       |\n|     . |\no-------o";
		SetColor(14, 0);
	}
	else if (a == 3)
	{
		SetColor(6, 0);
		std::cout << "o-------o\n| .     |\n|   .   |\n|     . |\no-------o";
		SetColor(14, 0);
	}
	else if (a == 4)
	{
		SetColor(12, 0);
		std::cout << "o-------o\n| .   . |\n|       |\n| .   . |\no-------o";
		SetColor(14, 0);
	}
	else if (a == 5)
	{
		SetColor(10, 0);
		std::cout << "o-------o\n| .   . |\n|   .   |\n| .   . |\no-------o";
		SetColor(14, 0);
	}
	else if (a == 6)
	{
		SetColor(11, 0);
		std::cout << "o-------o\n| .   . |\n| .   . |\n| .   . |\no-------o";
		SetColor(14, 0);
	}
}

 void gotoxy(short x, short y)
{
	COORD coord = { x, y };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, coord);
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