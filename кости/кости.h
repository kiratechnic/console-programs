#pragma once
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <iomanip>
#include <conio.h>
#include <Mmsystem.h>
#include <mciapi.h>
#pragma comment(lib, "Winmm.lib")

class data
{
public:
	int player1 = 0, player2 = 0;
	std::string player1_, player2_;

	data()
	{
		player1 = player2 = 0;
		player1_ = player2_ = "";
	}
	~data()
	{

	}
	friend void play(data& d, int number_of_rounds);
	friend void end_play(data& d);
};

void play(data& d, int number_of_rounds);
void end_play(data& d);
void print_kub(int a);

void gotoxy(short x, short y);

enum ConsoleColor;
void SetColor(int text, int background);