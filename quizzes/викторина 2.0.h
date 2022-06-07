#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>
#include <Mmsystem.h>
#include <mciapi.h>
#include <conio.h>
#pragma comment(lib, "Winmm.lib")

class v
{
private:
	int profit = 1;
	bool call_friend_and_fifty_fifty[2] = { true, true };
	
	//вопросы
	std::string qw[10] = 
	{ 
		"Какое животное обитает только в Китае?",
		"Чем питаются колибри?",
		"Какой рыбы не существует?", 
		"Закончите название басни И. Крылова: \"Стрекоза и ….\"",
		"У какой птицы самый большой размах крыльев? ", 
		"Какая наука изучает ископаемых животных?",
		"К каким животным относится морской конёк?", 
		"Символом чего считается сова?", 
		"Динозавр — это …",
		"Какая порода собак использовалась для охраны овечьих стад?" 
	}; 

	//варианты ответы
	std::string verios_answer[10][4] = 
	{
		{"Коала", "Верблюд", "Панда", "Слон"},
		{"Нектаром и мелкими насекомыми", "Цветами и фруктами", "Мелкой рыбой", "Семенами трав"},
		{"Рыба-пила", "Рыба-молот", "Рыба-плоскогубцы", "Рыба-игла"},
		{"Муравей", "Овод", "Гусеница", "Жук"},
		{"Коршун", "Альбатрос", "Орлан", "Журавль"},
		{"Сейсмология", "Орнитология", "Психология", "Палеонтология"},
		{"Моллюски", "Копытные", "Рыбы", "Ракообразные"},
		{"Лени", "Мудрости", "Доброты", "Терпения"},
		{"Млекопитающее", "Амфибия", "Рептилия", "Насекомое"},
		{"Пудель", "Лайка", "Овчарка", "Бульдог"}
	};    

	int true_and_false_answer[2][10] = { { 3,1,3,1,2,4,3,2,3,3 },
										 { 1,2,4,4,3,1,1,1,1,2 } };


public:
	v()
	{
		profit = 0;
		call_friend_and_fifty_fifty[0] = true;
		call_friend_and_fifty_fifty[1] = true;
	}

	~v(){}

	friend void end(v& v_);
	friend void rools();
	friend int  hints(v& v_, int counter);
	friend void call_friend(int tr_ans);
	friend void questions(v& v_);
	friend int  fifty_fifty(v& v_, int counter);
};

void end(v& v_);

// правила игры
void rools();

//есть ли подсказки и не хочет ли ими воспользоваться польз.
int hints(v& v_, int counter);

//звонок другу
void call_friend(int tr_ans);

// вопросы
void questions(v& v_);

int fifty_fifty(v& v_, int counter);

enum class Keys;

enum ConsoleColor;

void SetColor(int text, int background);

void gotoxy(short x, short y);