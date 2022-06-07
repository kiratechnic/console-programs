#include "кости.h"

int main()
{
	mciSendString(TEXT("open \"bones.mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);
	mciSendString(TEXT("open \"gong.mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);
	mciSendString(TEXT("open \"end.mp3\" type mpegvideo alias mp3"), NULL, 0, NULL);

	setlocale(LC_ALL, "RU-ru");
	srand(time(NULL));

	int number_of_rounds = 0;
	data d;

	SetColor(14, 0);
	std::cout << "Кто ходит первый?\nЯ - 1\nКомпьютер - 2\n> ";
	std::cin >> number_of_rounds;
	SetColor(4, 0);

	while (number_of_rounds!=1 && number_of_rounds!=2)
	{
		std::cout << "Ошибка!";
		std::cin >> number_of_rounds;
	}

	SetColor(14, 0);

	system("cls");

	if (number_of_rounds == 1)
	{
		d.player1_ = "Игрок";
		d.player2_ = "Компьютер";
	}
	else if (number_of_rounds == 2)
	{
		d.player1_ = "Компьютер";
		d.player2_ = "Игрок";
	}

	std::cout << "Первый ходит " << d.player1_;

	std::cout << "\n\n\nНажмите на любую кнопку чтобы продолжить!";
	_getch();
	system("cls");

	number_of_rounds = 6;
	play(d, number_of_rounds);

	end_play(d);

	SetColor(0, 0);
	return 0;
}