#include <iostream> //600 или -200р. экран 120x25 днивник k: Прошло 5 часов с 10 утра. Я выпил 1л сока и и половину бутылки содовой (0.75 л), раз 5 сходил по делам и три раза поел. Хочу спать! Тем временем написал: вывод одного пользователя, старт, рег и вход. Ща занимаюсь главным меню ...
#include <map> 
#include <vector> 
#include <string> 
#include <conio.h> 
#include <fstream>
#include <iomanip>
#include <windows.h> /*#include "сваха_header17.02.22.h"*/
#include <algorithm>
using std::vector; using std::string; using std::map; using std::vector; using std::pair;

//constexpr string cod_false = "#3343";//!!!!!!!!!!!!!!!!!!!важно код пустой строки 

enum ConsoleColor {
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
void SetColor(int text, int background) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void gotoxy(short x, short y) {
	COORD coord = { x, y };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, coord);
}

class parameters {
	string /*nick = "",*/ name = "", city = "", education = "";
	bool gender = NULL;
	size_t password = 0, age = 0;
	vector<string> interests/* = { NULL, NULL, NULL, NULL, NULL}*/;
public:
	parameters() {} //
	parameters(string name_, string city_, string education_, bool gen, size_t password_, size_t age_, vector<string> interests_) {
		name = name_;
		city = city_;
		education = education_;
		gender = gen;
		password = password_;
		age = age_;
		interests = interests_;
	}

	string& get_name() { return name; }
	string& get_city() { return city; }
	string& get_education() { return education; }
	bool& get_gender() { return gender; }
	size_t& get_password() { return password; }
	size_t& get_age() { return age; }
	vector<string>& get_interests() { return interests; }
};

void print_party(map <string, parameters> party) {
	vector<string>::iterator iter;
	map <string, parameters> ::iterator it;
	for (it = party.begin(); it != party.end(); it++) {
		std::cout << it->first << " "
			<< it->second.get_name() << "\n"
			<< it->second.get_age() << "\n"
			<< (it->second.get_gender() ? "m" : "w") << "\n"
			<< it->second.get_city() << "\n"
			<< it->second.get_education() << "\n" << "\ninterests: ";
		for (iter = it->second.get_interests().begin(); iter != it->second.get_interests().end(); iter++) {
			if (*iter != "#3343")
				std::cout << *iter << "\t";
		}
	}
}
void print_user(string nik, parameters obj)
{
	std::cout << nik << "\n"
		<< "name " << obj.get_name() << "\t"
		<< "age " << obj.get_age() << "\t"
		<< "gen " << (obj.get_gender() ? "M" : "W") << "\t"
		<< "city " << obj.get_city() << "\t"
		<< "education " << obj.get_education() << "\t"
		<< "\ninterests: ";
	for (size_t i = 0; i < obj.get_interests().size(); i++) {
		if (obj.get_interests()[i] != "#3343")
			std::cout << obj.get_interests()[i] << "\t";
	}
}

int choice(int x = 0, int y = 8, int interval = 0, string var1 = "М", string var2 = "Ж", string var3 = "") {
	int key = 0, num = 0;
	do {
		if (num == 0) { SetColor(2, 0); } gotoxy(x, y); std::cout << var1; SetColor(15, 0);
		if (num == 1) { SetColor(2, 0); } gotoxy(x + interval + 3, y); std::cout << var2; SetColor(15, 0);
		if (num == 2 && var3 != "") { SetColor(2, 0); } gotoxy(x + interval + 12, y); std::cout << var3; SetColor(15, 0);
		key = _getch();
		if (key == 224) {
			key = _getch();
			if (key == 75 && num != 0) num--;
			else if (key == 77 && num != (var3 == "") ? 1 : 2) num++;
		}
		else if (key == 13) {
			if (num == 0) return 1;
			else if (num == 1) return 0;
			else if (num == 2) return 2;
		}//
	} while (true);
}

size_t start() {
	size_t key = 0, cursor = 0;
	do {
		if (cursor == 0) { SetColor(0, 10); }	gotoxy(52, 10); std::cout << "   ВХОД    "; SetColor(15, 0); std::cout << " ";//для отрисовки верной
		if (cursor == 1) { SetColor(0, 10); }	gotoxy(52, 11); std::cout << "РЕГИСТРАЦИЯ"; SetColor(15, 0);
		if (cursor == 2) { SetColor(0, 10); }	gotoxy(52, 12); std::cout << "   ВЫХОД   "; SetColor(15, 0);
		key = _getch();
		if (key == 224) {
			key = _getch();
			if (key == 72)  cursor = (cursor == 0) ? 2 : cursor - 1;
			else if (key == 80)  cursor = (cursor == 2) ? 0 : cursor + 1;
		}
		else if (key == 13)
			if (cursor == 0) return cursor;
			else if (cursor == 1) return cursor;
			else if (cursor == 2) return cursor;
	} while (true);
}

string log_in(map <string, parameters>& party) {
	string nik = "", text = "";	int num = 0;
	system("cls");
	do {
		system("cls");	gotoxy(10, 1); std::cout << "log_in";
		gotoxy(10, 4); std::cout << "ваш логин: "; gotoxy(21, 4); std::cin >> nik;
		if (party.find(nik) != party.end()) { break; }
		else { gotoxy(15, 3); std::cout << "такого логина не существует! попробуйте ещё раз через пару секунд"; Sleep(2000); }
	} while (true);//try catch
	do {
		gotoxy(10, 7); std::cout << "введите пароль: "; gotoxy(26, 7); std::cin >> num;
		if (num == party[nik].get_password()) { break; }
		else {
			gotoxy(15, 6); std::cout << "неверный пароль! попробуйте ещё раз через пару секунд"; Sleep(2000);
			system("cls"); 	gotoxy(10, 1); std::cout << "log_in"; gotoxy(10, 4); std::cout << "ваш логиy: " << nik;
		}
	} while (true);
	system("cls"); gotoxy(10, 4); std::cout << party[nik].get_name() << ", добро пожаловать!";
	return nik;
}

void registration_preferences(string nik, map <string, parameters>& party_preferences) {
	string text = "";	int num = 0;
	system("cls"); 	gotoxy(10, 2); std::cout << "заполнение профиля";/*отвечайте на вопросы чесно чтобы найти себе подходящую половинку*/
	gotoxy(10, 4); std::cout << "Как будут звать половинку? "; std::cin >> party_preferences[nik].get_name();//try catch 
	gotoxy(10, 6); std::cout << "сколько лет? "; std::cin >> party_preferences[nik].get_age();//try catch 
	gotoxy(10, 8); std::cout << "где проживает? "; std::cin >> party_preferences[nik].get_city();//try catch 
	gotoxy(10, 10); std::cout << "какое образования? "; std::cin >> party_preferences[nik].get_name();//try catch 
	//gotoxy(10, 12); std::cout << "интересы:\n";
	num = 1;
	do {
		system("cls");  gotoxy(10, 4); std::cout << "по каким интересам искать:\n";
		gotoxy(15, 5); std::cout << num++ << "> "; std::cin >> text; std::cout << "\n";
		party_preferences[nik].get_interests().push_back(text);
		gotoxy(8, 6); std::cout << "продолжаем? ";
	} while (choice(20, 6, 0, "да", "нет"));
}
string registration(map <string, parameters>& party, map <string, parameters>& party_preferences) {
	string nik = "", text = "";	int num = 0;
	system("cls");
	do {
		gotoxy(10, 1); std::cout << "reg";
		gotoxy(10, 4); std::cout << "придумайте логин: "; gotoxy(28, 4); std::cin >> nik;
		if (party.find(nik) != party.end()) {
			gotoxy(27, 3); std::cout << "этот логин занят! попробуйте ещё раз через пару секунд"; Sleep(2000);
			system("cls");
		}
		else { break; }
	} while (true);//try catch
	gotoxy(10, 6); std::cout << "придумайте пароль из цифр: "; std::cin >> party[nik].get_password();//try catch потом спрашиваем готовы перейти к редактировании профеля или надо чето поправить
	system("cls"); 	gotoxy(10, 2); std::cout << "заполнение профиля";/*отвечайте на вопросы чесно чтобы найти себе подходящую половинку*/
	gotoxy(10, 4); std::cout << "как вас зовут? "; std::cin >> party[nik].get_name();//try catch 
	gotoxy(10, 6); std::cout << "полных лет? "; std::cin >> party[nik].get_age();//try catch 
	gotoxy(10, 8); std::cout << "ваш пол? ";
	party[nik].get_gender() = choice(19, 8);
	gotoxy(10, 10); std::cout << "город проживания? "; std::cin >> party[nik].get_city();//try catch 
	gotoxy(10, 12); std::cout << "какое у вас образования? "; std::cin >> party[nik].get_name();//try catch 
	gotoxy(10, 14); std::cout << "напишите 5 ваших интересов(если интересов меньше пяти ставте '-')";
	num = 1;
	do {
		system("cls");  gotoxy(10, 4); std::cout << "какие у вас интересы:\n";
		gotoxy(15, 5); std::cout << num++ << "> "; std::cin >> text; std::cout << "\n";
		party_preferences[nik].get_interests().push_back(text);
		gotoxy(8, 6); std::cout << "продолжаем? ";
	} while (choice(20, 6, 0, "да", "нет"));
	party_preferences[nik].get_gender() = !(party[nik].get_gender()); party_preferences[nik].get_password() = party[nik].get_password();
	registration_preferences(nik, party_preferences);
	return nik;
}

int user_settings_profile(string nik, map <string, parameters>& party) {
	size_t key = 0, num = 0; int cursor = 0;
	do {
		SetColor(15, 0); system("cls"); gotoxy(0, 0); std::cout << "настройки профиля";
		if (cursor >= 0 && cursor < 8) { SetColor(0, 10); }	gotoxy(10, 3); std::cout << "Изменить:"; SetColor(15, 0);
		if (cursor == 1) { SetColor(0, 11); }	gotoxy(10, 4); std::cout << "- имя"; SetColor(15, 0);
		if (cursor == 2) { SetColor(0, 11); }	gotoxy(10, 5); std::cout << "- пароль"; SetColor(15, 0);
		if (cursor == 3) { SetColor(0, 11); }	gotoxy(10, 6); std::cout << "- возрост"; SetColor(15, 0);
		if (cursor == 4) { SetColor(0, 11); }	gotoxy(10, 7); std::cout << "- город"; SetColor(15, 0);
		if (cursor == 5) { SetColor(0, 11); }	gotoxy(10, 8); std::cout << "- образование"; SetColor(15, 0);
		if (cursor == 6) { SetColor(0, 11); }	gotoxy(10, 9); std::cout << "- интересы"; SetColor(15, 0);
		if (cursor == 7) { SetColor(0, 11); }	gotoxy(10, 10); std::cout << "- добавить интереС"; SetColor(15, 0);
		if (cursor == 8) { SetColor(0, 10); }	gotoxy(10, 11); std::cout << "Выход"; SetColor(15, 0);
		key = _getch();
		if (key == 224) {
			key = _getch();
			if (key == 72)  cursor = (cursor == 0) ? 8 : cursor - 1;
			else if (key == 80)  cursor = (cursor == 8) ? 0 : cursor + 1;
		}
		else if (key == 13)
			if (cursor == 8) { break; }
			else {
				switch (cursor)
				{
				case 1: {
					SetColor(15, 4);	gotoxy(10, 4); std::cout << "- имя"; SetColor(15, 0);
					gotoxy(10, 13); std::cout << "Введите новое имя: "; std::cin >> party[nik].get_name();
					break;
				}
				case 2: {
					SetColor(15, 4); 	gotoxy(10, 5); std::cout << "- пароль"; SetColor(15, 0);
					gotoxy(10, 14); std::cout << "Введите новый пароль: "; std::cin >> party[nik].get_password();
					break;
				}
				case 3: {
					SetColor(15, 4); 	gotoxy(10, 6); std::cout << "- возрост"; SetColor(15, 0);
					gotoxy(10, 13); std::cout << "Введите возрост: "; std::cin >> party[nik].get_age();
					break;
				}
				case 4: {
					SetColor(15, 4);	gotoxy(10, 7); std::cout << "- город"; SetColor(15, 0);
					gotoxy(10, 13); std::cout << "Введите город: "; std::cin >> party[nik].get_city();
					break;
				}
				case 5: {
					SetColor(15, 4);	gotoxy(10, 8); std::cout << "- образование"; SetColor(15, 0);
					gotoxy(10, 13); std::cout << "Введите образование: "; std::cin >> party[nik].get_education();
					break;
				}
				case 6: {
					SetColor(15, 4); 	gotoxy(10, 9); std::cout << "- интересы"; SetColor(15, 0);
					num = 0;
					for (size_t i = 0; i < party[nik].get_interests().size(); i++) {
						gotoxy(8, 14 + num); std::cout << "Что с этим интересом сделать - " << party[nik].get_interests()[i];
						if (party[nik].get_interests()[i] == "#3343") { i += 1; }
						else {
							int vrem = (choice(8, 15 + num, 5, "удалить"/*1*/, "оставить"/*0*/, "изменить"/*2*/));
							if (1 == vrem) { party[nik].get_interests()[i] = "#3343"; }///
							else if (2 == vrem) { std::cout << "Введите новый интерес "; std::cin >> party[nik].get_interests()[i]; }
							num += 3;
						}
					}
					break;
				}
				case 7: {
					SetColor(15, 4); 	gotoxy(10, 10); std::cout << "- добавить интерес"; SetColor(15, 0);
					string text = ""; std::cout << "Введите новый интерес "; std::cin >> text; party[nik].get_interests().push_back(text);
					break;
				}//конец case 7
				}//конец switch
			}
	} while (true);
	return cursor;////
}
int user_settings_preferences(string nik, map <string, parameters>& party_preferences) {
	size_t key = 0, num = 0; int cursor = 0;
	do {
		SetColor(15, 0); system("cls"); gotoxy(0, 0); std::cout << "Настройки пожеланий";
		if (cursor >= 0 && cursor < 7) { SetColor(0, 10); }	gotoxy(10, 3); std::cout << "Изменить:"; SetColor(15, 0);
		if (cursor == 1) { SetColor(0, 11); }	gotoxy(10, 4); std::cout << "- имя"; SetColor(15, 0);
		if (cursor == 2) { SetColor(0, 11); }	gotoxy(10, 5); std::cout << "- возрост"; SetColor(15, 0);
		if (cursor == 3) { SetColor(0, 11); }	gotoxy(10, 6); std::cout << "- город"; SetColor(15, 0);
		if (cursor == 4) { SetColor(0, 11); }	gotoxy(10, 7); std::cout << "- образование"; SetColor(15, 0);
		if (cursor == 5) { SetColor(0, 11); }	gotoxy(10, 8); std::cout << "- интересы"; SetColor(15, 0);
		if (cursor == 6) { SetColor(0, 11); }	gotoxy(10, 9); std::cout << "- добавить интереС"; SetColor(15, 0);
		if (cursor == 7) { SetColor(0, 10); }	gotoxy(10, 10); std::cout << "Выход"; SetColor(15, 0);
		key = _getch();
		if (key == 224) {
			key = _getch();
			if (key == 72)  cursor = (cursor == 0) ? 7 : cursor - 1;
			else if (key == 80)  cursor = (cursor == 7) ? 0 : cursor + 1;
		}
		else if (key == 13)
			if (cursor == 7) { break; }
			else {
				switch (cursor)
				{
				case 1: {
					SetColor(15, 4);	gotoxy(10, 4); std::cout << "- имя"; SetColor(15, 0);
					gotoxy(10, 13); std::cout << "Введите новое имя: "; std::cin >> party_preferences[nik].get_name();
					break;
				}
				case 2: {
					SetColor(15, 4); 	gotoxy(10, 5); std::cout << "- возрост"; SetColor(15, 0);
					gotoxy(10, 13); std::cout << "Введите возрост: "; std::cin >> party_preferences[nik].get_age();
					break;
				}
				case 3: {
					SetColor(15, 4);	gotoxy(10, 6); std::cout << "- город"; SetColor(15, 0);
					gotoxy(10, 13); std::cout << "Введите город: "; std::cin >> party_preferences[nik].get_city();
					break;
				}
				case 4: {
					SetColor(15, 4);	gotoxy(10, 7); std::cout << "- образование"; SetColor(15, 0);
					gotoxy(10, 13); std::cout << "Введите образование: "; std::cin >> party_preferences[nik].get_education();
					break;
				}
				case 5: {
					SetColor(15, 4); 	gotoxy(10, 8); std::cout << "- интересы"; SetColor(15, 0);
					num = 0;
					for (size_t i = 0; i < party_preferences[nik].get_interests().size(); i++) {
						gotoxy(8, 14 + num); std::cout << "Что с этим интересом сделать - " << party_preferences[nik].get_interests()[i];
						if (party_preferences[nik].get_interests()[i] == "#3343") { i += 1; }
						else {
							int vrem = (choice(8, 15 + num, 5, "удалить"/*1*/, "оставить"/*0*/, "изменить"/*2*/));
							if (1 == vrem) { party_preferences[nik].get_interests()[i] = "#3343"; }///
							else if (2 == vrem) { std::cout << "Введите новый интерес "; std::cin >> party_preferences[nik].get_interests()[i]; }
							num += 3;
						}
					}
					break;
				}
				case 6: {
					SetColor(15, 4); 	gotoxy(10, 9); std::cout << "- добавить интерес"; SetColor(15, 0);
					string text = ""; std::cout << "Введите новый интерес "; std::cin >> text; party_preferences[nik].get_interests().push_back(text);
					break;
				}//конец case 6
				}//конец switch
			}
	} while (true);
	return cursor;////
}
void user_settings(string nik, map <string, parameters>& party, map <string, parameters>& party_preferences) {
	size_t key = 0; int cursor = 0;
	do {
		SetColor(15, 0); system("cls"); gotoxy(0, 0); std::cout << "пользовательские настройки";
		if (cursor == 0 || cursor == 1) { SetColor(0, 10); }	gotoxy(10, 3); std::cout << "Исправить:"; SetColor(15, 0);
		if (cursor == 0) { SetColor(0, 11); }	gotoxy(10, 4); std::cout << "- профиль"; SetColor(15, 0);
		if (cursor == 1) { SetColor(0, 11); }	gotoxy(10, 5); std::cout << "- пожелания"; SetColor(15, 0);
		if (cursor == 2) { SetColor(0, 10); }	gotoxy(10, 6); std::cout << "Выход"; SetColor(15, 0);
		key = _getch();
		if (key == 224) {
			key = _getch();
			if (key == 72)  cursor = (cursor == 0) ? 2 : cursor - 1;
			else if (key == 80)  cursor = (cursor == 2) ? 0 : cursor + 1;
		}
		else if (key == 13)
			if (cursor == 2) { break; }
			else if (cursor == 0) { user_settings_profile(nik, party); }
			else if (cursor == 1) { user_settings_preferences(nik, party_preferences); }
	} while (true);
}

void find_(string nik, map <string, parameters>& party, map <string, parameters>& party_preferences, size_t num) {
	SetColor(15, 0); system("cls"); gotoxy(0, 0); std::cout << "поиск";
	size_t ideal = 0, counter = 0;
	vector <pair<size_t, string>> find_best;
	vector<string>::iterator it_v, it_v1;
	map <string, parameters> ::iterator it_m;
	for (it_m = party.begin(); it_m != party.end(); it_m++) {
		if (it_m->first != nik && it_m->second.get_gender() == party_preferences[nik].get_gender()) {
			switch (num) {
			case 0:
			{
				if (it_m->second.get_age() + 3 > party_preferences[nik].get_age() && it_m->second.get_age() - 3 < party[nik].get_age()) ideal++;
				if (it_m->second.get_name() == party_preferences[nik].get_name()) ideal++;
				if (it_m->second.get_city() == party_preferences[nik].get_city()) ideal++;
				if (it_m->second.get_education() == party_preferences[nik].get_education()) ideal++;
				for (it_v = party_preferences[nik].get_interests().begin(); it_v != party_preferences[nik].get_interests().end(); it_v++) {
					for (it_v1 = it_m->second.get_interests().begin(); it_v1 != it_m->second.get_interests().end(); it_v1++)
						if (*it_v == *it_v1) counter++;
					if (counter) ideal++; counter = 0;
				}
				break;
			}
			case 1:		if (it_m->second.get_name() == party_preferences[nik].get_name()) { ideal++; }		break;
			case 2:		if (it_m->second.get_age() + 3 > party_preferences[nik].get_age() && it_m->second.get_age() - 3 < party[nik].get_age()) { ideal++; }	break;
			case 3:		if (it_m->second.get_city() == party_preferences[nik].get_city()) { ideal++; }		break;
			case 4:		if (it_m->second.get_education() == party_preferences[nik].get_education()) { ideal++; }		break;
			case 5:
			{
				for (it_v = party_preferences[nik].get_interests().begin(); it_v != party_preferences[nik].get_interests().end(); it_v++) {
					for (it_v1 = it_m->second.get_interests().begin(); it_v1 != it_m->second.get_interests().end(); it_v1++)
						if (*it_v == *it_v1) counter++;
					if (counter) ideal++; counter = 0;
				}
				break;
			}
			}
		}
		if (ideal) { find_best.emplace_back(ideal, it_m->first); } ideal = 0;
	}
	if (find_best.size()) {
		num = 0;
		sort(find_best.begin(), find_best.end());
		for (int i = find_best.size() - 1; i >= 0; i--) { gotoxy(10, 4 + num);	num += 4;	print_user(find_best[i].second, party[find_best[i].second]); } //cout << "туту исключение";///////
	}
	else { gotoxy(10, 4);  SetColor(0, 10); std::cout << "нечего не найдено!";  SetColor(15, 0); }
	SetColor(0, 10); gotoxy(10, 2); std::cout << "Чтобы продолжить тыкните куда-нибудь\n"; SetColor(15, 0); _getch(); system("cls");
}
void find_menu(string nik, map <string, parameters>& party, map <string, parameters>& party_preferences) {
	SetColor(15, 0); system("cls"); gotoxy(0, 0); std::cout << "меню поиска";
	size_t key = 0; int cursor = 0;
	do {
		if (cursor == 0) { SetColor(0, 10); }	gotoxy(10, 4); std::cout << "Поиск по всем параметрам"; SetColor(15, 0);
		if (cursor == 1) { SetColor(0, 10); }	gotoxy(10, 5); std::cout << "Поиск по имени"; SetColor(15, 0);
		if (cursor == 2) { SetColor(0, 10); }	gotoxy(10, 6); std::cout << "Поиск по возрасту"; SetColor(15, 0);
		if (cursor == 3) { SetColor(0, 10); }	gotoxy(10, 7); std::cout << "Поиск по городу"; SetColor(15, 0);
		if (cursor == 4) { SetColor(0, 10); }	gotoxy(10, 8); std::cout << "Поиск по образованию"; SetColor(15, 0);
		if (cursor == 5) { SetColor(0, 10); }	gotoxy(10, 9); std::cout << "Поиск по интересам"; SetColor(15, 0);
		if (cursor == 6) { SetColor(0, 10); }	gotoxy(10, 10); std::cout << "Выход"; SetColor(15, 0);
		key = _getch();
		if (key == 224) {
			key = _getch();
			if (key == 72)  cursor = (cursor == 0) ? 6 : cursor - 1;
			else if (key == 80)  cursor = (cursor == 6) ? 0 : cursor + 1;
		}
		else if (key == 13)
			if (cursor == 6) { break; }
			else { find_(nik, party, party_preferences, cursor); }
	} while (true);
}

constexpr int esc = 27, arrows = 224, up = 72, left = 75, right = 77, down = 80, enter = 13;

int main_menu(string nik, map <string, parameters>& party, map <string, parameters>& party_preferences) {
	constexpr int X = 120, Y = 25; int key = 0, x = X / 2, y = Y / 2;
	SetColor(15, 0); system("cls");
	gotoxy(108, 0); std::cout << "|"; gotoxy(109, 0); for (size_t i = 0; i < ((nik.size() > 11) ? 8 : nik.size()); i++) { std::cout << nik[i]; } if (nik.size() > 11) std::cout << "...";
	gotoxy(108, 1); std::cout << "|"; gotoxy(109, 1); std::cout << "настройки";
	gotoxy(108, 2); std::cout << "|"; gotoxy(109, 2); std::cout << "сменить акк";
	gotoxy(0, 24); std::cout << "_____ ______"; gotoxy(0, 25); std::cout << "ПОИСК|ПОМОЩЬ"; std::cout << "|";
	gotoxy(0, 0); std::cout << "ВЫХОД|";
	do {
		SetColor(0, 10); gotoxy(x, y);  SetColor(15, 0);
		key = _getch();
		if (key == 224) {
			key = _getch();
			if (key == 72 && (y != 0))		y -= 1;//up
			else if (key == 75 && (x != 0))	x -= 1;//left
			else if (key == 77 && (x != X))	x += 1;//right
			else if (key == 80 && (y != Y))	y += 1;//down
		}
		else if (key == 13) {
			if ((x >= 0 && y >= 0) && (x <= 2 && y <= 5)) { key = -1; break; }//выход
			else if ((x >= 0 && y >= 25) && (x <= 4 && y <= 25)) { key = 63; find_menu(nik, party, party_preferences); }//->меню поиска
			else if ((x >= 109 && y >= 1) && (x <= 120 && y <= 1)) { key = 63;  user_settings(nik, party, party_preferences); }//->настройки пользователя
			else if ((x >= 109 && y >= 2) && (x <= 120 && y <= 2)) { key = 63; break; }//->на старт(сменить акк)
			else if ((x >= 6 && y >= 25) && (x <= 11 && y <= 25)) { //->помощь (распиновка кнопок)
				gotoxy(5, 10); std::cout << "f5 - перезагрузить экран";
				gotoxy(5, 11); std::cout << "курсор двигается стрелочками";
				gotoxy(5, 12); std::cout << "чтобы перейти в нужное меню наведите на него и нажмите - enter";
			}
		}
		if (key == 63) {
			SetColor(15, 0); system("cls");//перерисовка экранаf5
			gotoxy(108, 0); std::cout << "|"; gotoxy(109, 0); for (size_t i = 0; i < ((nik.size() > 11) ? 8 : nik.size()); i++) { std::cout << nik[i]; } if (nik.size() > 11) std::cout << "...";
			gotoxy(108, 1); std::cout << "|"; gotoxy(109, 1); std::cout << "настройки";
			gotoxy(108, 2); std::cout << "|"; gotoxy(109, 2); std::cout << "сменить акк";
			gotoxy(0, 24); std::cout << "_____ ______"; gotoxy(0, 25); std::cout << "ПОИСК|ПОМОЩЬ"; std::cout << "|";
			gotoxy(0, 0); std::cout << "ВЫХОД|";
		}
	} while (true);
	return key;
}

void write_data(map <string, parameters>& party, bool file = true) {
	if (remove(file ? "data.txt" : "data_preferences.txt") == 0) { gotoxy(0, 26);  std::cout << "679942344"; }
	vector<string>::iterator iter;
	map <string, parameters> ::iterator it;
	std::fstream f;
	f.open((file ? "data.txt" : "data_preferences.txt"), std::ios::out/* | std::ios::app*/);
	for (it = party.begin(); it != party.end(); it++) {
		f << it->first << " " << it->second.get_password() << " "
			<< it->second.get_name() << " " << it->second.get_gender() << " "
			<< it->second.get_age() << " " << it->second.get_city() << " "
			<< it->second.get_education() << " "
			<< it->second.get_interests().size() << " ";
		for (iter = it->second.get_interests().begin(); iter != it->second.get_interests().end(); iter++) {
			f << *iter << " ";
		}f << "\n";
	}
	f.close();
}
void read_data(map <string, parameters>& party, bool file = true) {
	string nik = "", text = "433";  int num = 0; std::fstream f;
	f.open((file ? "data.txt" : "data_preferences.txt"), std::ios::in);
	while (!f.eof()) {
		f >> nik
			>> party[nik].get_password()
			>> party[nik].get_name()
			>> party[nik].get_gender()
			>> party[nik].get_age()
			>> party[nik].get_city()
			>> party[nik].get_education()
			>> num;
		for (size_t i = 0; i < num; i++) {
			f >> text;
			if (text != "#3343")
				party[nik].get_interests().push_back(text);
		}
		num = 0;
	}
	f.close();
}

int main() {
	setlocale(LC_ALL, "RU-ru");
	gotoxy(0, 0); std::cout << "СВАХА.gg";

	map <string, parameters> party; map <string, parameters> party_preferences;

	read_data(party, 1); read_data(party_preferences, 0);
	/*party["kiratechnic"] = { "Kirill", "Moscow", "crednee", true, 777, 17, {"prog", "avio"} };
	party_preferences["kiratechnic"] = { "Ann", "Moscow", "crednee", false, 777, 17, {"prog", "avio"} };
	party["gg"] = { "Ann", "Moscow", "crednee", false, 777, 17, {"prog", "avio"} };
	party_preferences["gg"] = { "Kirill", "Moscow", "crednee", true, 777, 17, {"prog", "avio"} };
	party["gg1"] = { "Kirill", "Moscow", "d", true, 777, 17, {"prog", "#3343"} };
	party_preferences["gg1"] = { "Ann", "Moscow", "crednee", false, 777, 17, {"prog", "avio"} };*/
	string nik_user = "";
	do {
		system("cls");
		switch (start()) {
		case 0:
			nik_user = log_in(party);	system("cls");
			std::cout << nik_user;
			break;
		case 1:
			nik_user = registration(party, party_preferences);	system("cls");
			std::cout << nik_user;
			break;
		case 2: write_data(party, 1); write_data(party_preferences, 0); gotoxy(0, 27); exit(EXIT_SUCCESS);
		}
		if (-1 == main_menu(nik_user, party, party_preferences)) break;
	} while (true);
	write_data(party, 1); write_data(party_preferences, 0);
	gotoxy(0, 27);
	return 0;
}