#include "викторина 2.0.h"

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
				if (k!=2)//при использование помощи друга чтоб не стерало
					system("cls");
				
				gotoxy(0, 0);
				SetColor(6, 0);
				std::cout << v_.qw[i];
				SetColor(11, 0);
				if (k==2 || k==3)
				{
					SetColor(3, 0);
				}

				//вывод вариантов ответов
				for (size_t j = 1; j < 6; j++)
				{
					if (0 < j && j < 5)
					{
						if (k != 3)//если не использована подсказка 50/50
						{
							std::cout << "\n" << v_.verios_answer[i][j - 1] << " нажмите - " << j;
						}
						else if ((v_.true_and_false_answer[1][i] == j || v_.true_and_false_answer[0][i] == j) && k == 3)//если использована подсказка 50/50 выводит только определеные
						{
							std::cout << "\n" << v_.verios_answer[i][j - 1] << " нажмите - " << j;
						}

					}
					else if (j == 5 && k!=2 && k!=3 && (v_.call_friend_and_fifty_fifty[1] == true || v_.call_friend_and_fifty_fifty[0] == true))/*)*/
					{
						if (k != 3)//если не использована подсказка 50/50
						{
							std::cout << "\n" << "Открыть подсказки" << " нажмите - " << j;
						}
					}
				}
				SetColor(7, 0);
				//действие пользователя
				en = _getch();

				switch (en)
				{
					case 49://1
					{
						if (k != 3)//если не использована подсказка 50/50
						{
							if (1 == v_.true_and_false_answer[0][i])//проверка ответа
								k = 1;
							else
								k = 0;
						}
						else if ((v_.true_and_false_answer[1][i] == 1 || v_.true_and_false_answer[0][i] == 1) && k == 3)//если использована подсказка 50/50 принемает только некоторые ответы
						{
							if (1 == v_.true_and_false_answer[0][i])//проверка ответа
								k = 1;
							else
								k = 0;
						}
						break;
					}
					case 50://2
					{
						if (k != 3)//если не использована подсказка 50/50
						{
							if (2 == v_.true_and_false_answer[0][i])//проверка ответа
								k = 1;
							else
								k = 0;
						}

						else if ((v_.true_and_false_answer[1][i] == 2 || v_.true_and_false_answer[0][i] == 2) && k == 3)//если использована подсказка 50/50 принемает только некоторые ответы
						{
							if (2 == v_.true_and_false_answer[0][i])//проверка ответа
								k = 1;
							else
								k = 0;
						}						
						break;
					}
					case 51://3
					{
						if (k != 3)//если не использована подсказка 50/50
						{
							if (3 == v_.true_and_false_answer[0][i])//проверка ответа
								k = 1;
							else
								k = 0;
						}
						else if ((v_.true_and_false_answer[1][i] == 3 || v_.true_and_false_answer[0][i] == 3) && k==3)//если использована подсказка 50/50 принемает только некоторые ответы
						{
							if (3 == v_.true_and_false_answer[0][i])//проверка ответа
								k = 1;
							else
								k = 0;
						}
						

						break;
					}
					case 52://4
					{
						if (k != 3)//если не использована подсказка 50/50
						{
							if (4 == v_.true_and_false_answer[0][i])//проверка ответа
								k = 1;
							else
								k = 0;
						}
						else if ((v_.true_and_false_answer[1][i] == 4 || v_.true_and_false_answer[0][i] == 4) && k == 3)//если использована подсказка 50/50 принемает только некоторые ответы
						{
							if (4 == v_.true_and_false_answer[0][i])//проверка ответа
								k = 1;
							else
								k = 0;
						}
						break;
					}
					case 53://5
					{	if (k != 3 && k != 2)
							k = 7;//защита чтобы когда кончились все подсказки нельзя было при воводе 5(5 отвечает за подсказки) сделать правильным ответ. Т.к. до этого в k храниться 1 в следствие чего мы попадали в if на строке  138
						if (k != 3 && k != 2)//если не использована подсказка 50/50
						{
							if ((v_.call_friend_and_fifty_fifty[1] == true || v_.call_friend_and_fifty_fifty[0] == true) && k != 2)
								k = hints(v_, i);
						}

						break;
					}
				}

			} while (k!=1 && k!=0);
			//при верно ответе 
			if (k == 1)
			{
				//начисление очков
				if (i != 0)
					v_.profit *= 2;
				else if (i == 0)
					v_.profit = 10;

				mciSendString(TEXT("play correct.mp3 wait"), NULL, 0, NULL);
				Sleep(500);
				if (i!=9)//что при последнем правильно ответе не вылизал все равно выйдет из игры 
				{
					system("cls");
					SetColor(6, 0);
					std::cout << "Продолжить или забрать " <<  v_.profit << " очков и выйти? Вот в чем вопрос?";
					SetColor(3, 0);
					std::cout << "\nПродолжить - 1\nЗабрать все что накопилось и выйти - 2";
					SetColor(7, 0);
					//действие пользователя
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
			//при ложно ответе
			else if (k==0)
			{
				mciSendString(TEXT("close background_music.mp3"), NULL, 0, NULL);
				mciSendString(TEXT("play wrong.mp3 wait"), NULL, 0, NULL);
				v_.profit = 0;
				break;
			}
		}
}

//есть ли подсказки и не хочет ли имим воспользоваться польз.
int hints(v& v_, int i)
{
	//v_.call_friend_and_fifty_fifty[0] - помощь друга 
	//v_.call_friend_and_fifty_fifty[1] - вопрос 50/50
	int en, k=6;//-2 чтоб при нажатие 
	do
	{

		SetColor(10, 0);
		if (v_.call_friend_and_fifty_fifty[0] == true)
			std::cout << "\n" << " - Спросить у друга" << " нажмите - 1";

		if (v_.call_friend_and_fifty_fifty[1] == true)
			std::cout << "\n" << " - Сделать вопрос 50/50" << " нажмите - 2";

		std::cout << "\n" << " - Закрыть подсказки" << " нажмите - 3";
		SetColor(7, 0);

		en = _getch();

		switch (en)
		{
			case 49:
			{	
				if (v_.call_friend_and_fifty_fifty[0] == true)//надо чтобы при уже использование не принемало значение
				{
					call_friend(v_.true_and_false_answer[0][i]);//функция вывода ответа друга
					v_.call_friend_and_fifty_fifty[0] = false;//подсказка использована
					k = 2; // надо что бы system("cls"); не стер
					
				}
			break;
			}
			case 50:
			{
				if (v_.call_friend_and_fifty_fifty[1] == true)//надо чтобы при уже использование не принемало значение
				{
					k = 3;//чтобы в функции questions выводила и принимало значения только для двух определенных ответов 
					v_.call_friend_and_fifty_fifty[1] = false;//подсказка использована
				}

				break;
			}
			case 51:
			{
				k = -1;//выход только с подсказок 
				break;
			}
			default:
			{
				k = NULL; //если нажали на совсем другую клавишу
				break;
			}
		}
	} while (k != 1 && k != 0 && k != -1 && k !=2 && k != 3);

	return k;
}

//звонок другу "20%" что неправильно 
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
	std::cout << "\n\nПолучено 1 новое сообщение!";

	int rand_namber = rand() % 10, rand_namber1 = rand() % 10;

	if (rand_namber != rand_namber1 || rand_namber != rand_namber1)
	{
		std::cout << "\nПривет, кароче инфа сотка ответ " << tr_ans << " Не забудь потом с другом выигрышем поделиться))";
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
				std::cout << "\nПривет, я прочел вопрос и не очень уверен, но мне кажется ответ 2 ";
				break;
			case 1:
				std::cout << "\nЗдорова, поздравляю что попал в эту викторину! На счет вопроса не уверин, возможно это 3 ";
				break;
			case 2:
				std::cout << "\nЗдравствуй, поболтать хочется, но у вас там по времяни вроде, так что тут наверное ответ 4 ";
				break;
			}
			break;
		case 2:
			rand_namber = rand() % 3;
			switch (rand_namber)
			{
			case 0:
				std::cout << "\nПривет, я прочел вопрос и не очень уверен, но мне кажется ответ 1 ";
				break;
			case 1:
				std::cout << "\nЗдорова, поздравляю что попал в эту викторину! На счет вопроса не уверин, возможно это 4 ";
				break;
			case 2:
				std::cout << "\nЗдравствуй, поболтать хочется, но у вас там по времяни вроде, так что тут наверное ответ 3 ";
				break;
			}
			break;
		case 3:
			rand_namber = rand() % 3;
			switch (rand_namber)
			{
			case 0:
				std::cout << "\nПривет, я прочел вопрос и не очень уверен, но мне кажется ответ 4 ";
				break;
			case 1:
				std::cout << "\nЗдорова, поздравляю что попал в эту викторину! На счет вопроса не уверин, возможно это 2 ";
				break;
			case 2:
				std::cout << "\nЗдравствуй, поболтать хочется, но у вас там по времяни вроде, так что тут наверное ответ 1 ";
				break;
			}
			break;
		case 4:
			rand_namber = rand() % 3;
			switch (rand_namber)
			{
			case 0:
				std::cout << "\nПривет, я прочел вопрос и не очень уверен, но мне кажется ответ 2 ";
				break;
			case 1:
				std::cout << "\nЗдорова, поздравляю что попал в эту викторину! На счет вопроса не уверин, возможно это 3 ";
				break;
			case 2:
				std::cout << "\nЗдравствуй, поболтать хочется, но у вас там по времяни вроде, так что тут наверное ответ 1 ";
				break;
			}
			break;
		}
	}
	SetColor(7, 0);
}

// правила игры
void rools()
{
	mciSendString(TEXT("play start.mp3"), NULL, 0, NULL);
	std::cout << std::setw(70) << "Правила!" << "\n\nОни просты ваша задача правильно отвечать на вопросы, если ошибетесь игра закончиться и ваш выйгрышь сгорит.\nНо не растраеватесь у вас есть один звонок другу(который возможно вам поможет) и вопрос 50/50(это когда в вопросе остается один правильный и один неправильны ),\nза один раз можно использовать что-нибудь одно";
	std::cout << "\n\nОх забыл самое главное, видь не с проста вы сюда пришли, а за призами! За первый правильный ответ вы получаете 10 очков, \nза каждый следующий правильный ответ, начисление увеличивается в двое!";
	std::cout << "\n\nЧтобы начать нажмите на любую кнопку на клавиатуре";
	_getch();
	mciSendString(TEXT("close start.mp3"), NULL, 0, NULL);

}

//завершение игры 
void end(v& v_)
{
	mciSendString(TEXT("play end.mp3"), NULL, 0, NULL);

	if (v_.profit == 0)
		std::cout << "\n\nК сожелению вы проиграли\nНо это не повод растраиваться видь в жизни есть много чего интересного! Удачи и добра!";

	else if (v_.profit > 0)
	{
		if (v_.profit < 10240)
			std::cout << "\nК сожелению вы покидаете нас раньше времяни, с вами было интерсно пообщаться!";
		std::cout << "\nваш приз состовляет " << v_.profit << " очков";
		std::cout << "\nМои поздравления!!!";
	}
	std::cout << "\n\nЧтобы закрыть нажмите на любую кнопку на клавиатуре";
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

//была дикая задержка из-за этого убрал(после нажатие на клавиатуре проигрывалось нажатие на кнопку одну их трех видов) 
//функция вызывалась после каждого en = _getch(); и в некоторых местах после _getch(); 

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