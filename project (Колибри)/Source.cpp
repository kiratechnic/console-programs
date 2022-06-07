#include <iostream>//cin.getline(fff, 16, ';');
#include <string>
#include <map>
#include <Windows.h>
#include <conio.h> 
#include <fstream>
#include <iomanip>
#include <algorithm>
#include<time.h>
using namespace std;



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
enum limit { limit_input = 16 };
enum product_types { pastries = 0, drinks = 1, snacks = 2 };
constexpr int esc = 27, arrows = 224, up = 72, left_ = 75, right_ = 77, down = 80, enter = 13, f5 = 63;



//class user {
//	string password = "", name = "";
//	/*size_t month = 0, day = 0, id_favorite_food = 0;*/
//	map <size_t, size_t> basket;
//public:
//	user() {}
//	string get_password() { return password; }
//	string get_name() { return name; }
//	//size_t get_month() { return month; } 	//size_t get_day() { return day; } 	//size_t get_id_favorite_food() { return id_favorite_food; }
//	map <size_t, size_t> get_basket() { return basket; }
//};
//class product {
//private:
//	string name = "";
//	double cost = 0.0;
//	//size_t type;
//public:
//	product() {}
//	string get_name() { return name; }
//	double get_cost() { return cost; }
//	void set_cost(double cost_) { cost = cost_; }
//	//size_t get_type() { return type; }
//};
//
//
//size_t print_minu(map <string, user>& users, map <size_t, product>& products, string nik = "") {
//	map <size_t, product> ::iterator pr_it;
//	constexpr size_t products_per_page = 10;
//	int cursor = 1; size_t key = 0, sweet = 1; /* расположение курсора, ключь нажатой клавише, открытый лист*/
//	bool basket_empty = false;
//	do {
//		//вывод
//		if (users[nik].get_basket().size()!=0){
//			if (cursor == 0) SetColor(4, 0); 
//			std::cout << "к оформлению\n"; SetColor(15, 0);
//			basket_empty = true;
//		}
//		else { std::cout << "корзина пуста!\n"; basket_empty = false; }
//
//		for (pr_it = products.begin(); pr_it != products.end() || pr_it->first <= sweet * products_per_page; pr_it++) {
//			if (products.end() != find(products.begin(), products.end(), pr_it->first))
//				SetColor(5, 0);
//			std::cout << pr_it->second.get_name() << "цена - " << pr_it->second.get_cost(); SetColor(15, 0);
//		}
//		key = _getch();
//		if (key == 224) {
//			_getch();
//			if (key == up)
//				cursor = (cursor == (basket_empty==true? 0:1)) ? 11 : cursor - 1;
//			else if (key == down)
//				cursor = (cursor == 11) ? 1 : cursor + 1;
//			else if (key == left_) {
//				if (sweet != 1) {
//					sweet--;
//					std::advance(pr_it, -10);
//				}
//			}
//			else if (key == right_) {
//				sweet = ++pr_it-- != products.end() ? sweet : sweet + 1;
//				if (++pr_it-- != products.end()) {
//					sweet++;
//					std::advance(pr_it, products_per_page);
//				}
//			}
//		}
//		else if (key == enter) {//запись id выбраного продукта и его количество либо переход к оформлению
//			if (cursor == 0) {
//				std::cout << "переход к оформлению";
//				cursor = -1;
//			}
//			if (cursor == 11) {	cursor = -2; /*users[nik].get_basket().clear();*/	}
//			else if (cursor != 0) {
//				map <size_t, product> ::iterator pr_it_copy = pr_it;
//				std::advance(pr_it_copy, -1 * cursor);
//				//for (int i = 0; i < cursor; i++) pr_it_copy--;
//				
//				if (users[nik].get_basket().find(pr_it_copy->first) != users[nik].get_basket().end()) {
//					int number = 0;
//					/*gotoxy(cursor, 20);*/ std::cout << "¬ведите кол-во выбраного товара: "; std::cin >> number;
//					if (number != 0)
//					users[nik].get_basket()[pr_it_copy->first] = (number < 0 ? number * -1 : number);
//					basket_empty = true;
//				}
//				else {
//					users[nik].get_basket().erase(pr_it_copy->first);
//				}
//			}
//		}//end enter
//	} while (cursor!=-1  || cursor!=-2); //-1 в корзине чета есть просто выход
//	return cursor;
//}
//
//
//int mainxx() {
//	setlocale(LC_ALL, "RU-ru");
//
//	map <string, user> users;
//	users["gg_log"].get_password() = "123";
//	users["gg_log"].get_name() = "ki";
//	users["antur"].get_password() = "333";
//	users["antur"].get_name() = "an";
//
//	map <size_t, product> products;
//	products[1].get_name() = "маргарита";
//	products[1].set_cost(199.99);
//	products[4].get_name() = "с ветчиной и грибами";
//	products[5].set_cost(249.99);
//	products[3].get_name() = "пепперони";
//	products[3].set_cost(249.99);
//	products[4].get_name() = "4 сыра";
//	products[4].set_cost(239.99);
//	products[5].get_name() = "молочный коктейль";
//	products[5].set_cost(79.99);
//	products[6].get_name() = "кофе";
//	products[6].set_cost(79.99);
//	products[7].get_name() = "чай";
//	products[7].set_cost(79.99);
//	products[8].get_name() = "кока-кола";
//	products[8].set_cost(59.99);
//	string nik = "ki";
//
//	print_minu(users, products, nik);
//
//	return 0;
//}




//#include <string>
//#include <map>
//
//using namespace std;
//class users {
//private:
//	map <string, user> users1;
//	users() {}
//	static users* users_obj;
//public:
//	map <string, user> get_users1() { return users1; }
//	static users* get_user() {
//		if (!users_obj) {
//			users_obj = new users();
//		}
//		return users_obj;
//	}
//};
//users* users::users_obj = NULL;
//
//class products {
//private:
//	map <size_t, product> products1;
//	products() {}
//	static products* products_obj;
//public:
//	static products* get_user() {
//		if (!products_obj) {
//			products_obj = new products();
//		}
//		return products_obj;
//	}
//};
//products* products::products_obj = NULL;
//
//
//class user {
//	string password = "";
//	string name = "";
//	size_t month = 0;
//	size_t day = 0;
//	size_t id_favorite_food = 0;
//public:
//	user() {}
//	user(string login_, string password_, string name_, size_t month_, size_t day_) {
//		name = name_;
//		password = password_;
//		month = month_;
//		day = day_;
//	}
//	string get_password() { return password; }
//	string get_name() { return name; }
//	size_t get_month() { return month; }
//	size_t get_day() { return day; }
//	size_t get_id_favorite_food() { return id_favorite_food; }
//};
//
//
//
//class product {
//private:
//	string name;
//	double cost;
//	size_t type;
//public:
//	product() {}
//	product(string name_, double cost_, size_t type_) {
//		name = name_;
//		cost = cost_;
//		type = type_;
//	}
//	string get_name() { return name; }
//	double get_cost() { return cost; }
//	size_t get_type() { return type; }
//};
//
////print
//
////map <size_t, product> ::iterator pr_it;
////for (pr_it = products.begin(); pr_it != products.end(); pr_it++) {
////	std::cout << pr_it->second.get_name() << "цена - " << pr_it->second.get_cost();
////}
//
//
//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<fstream>
//#include<time.h>
//using namespace std;
//class Basket
//{
//private:
//	Basket() {}
//	static Basket* pObj;
//public:
//
//	static Basket* GetInstance() {
//		if (!pObj) {
//			pObj = new Basket();
//		}
//		return pObj;
//	}
//
//	void Combos();
//
//
//	void AddToBasket(string combo[]) {
//		const time_t timer = time(NULL);
//		ofstream fObj("basket.txt", ios::in);
//		if (!fObj)
//		{
//			cout << "\nFile error\n";
//			exit(EXIT_FAILURE);
//		}
//		for (int i = 0; i < 4; i++)
//		{
//			fObj << combo[i].c_str() << "\t" << ctime(&timer) << endl;
//		}
//	}
//	void AddToBasket(string combo) {
//		const time_t timer = time(NULL);
//		ofstream fObj("basket.txt", ios::in);
//		if (!fObj)
//		{
//			cout << "\nFile error\n";
//			exit(EXIT_FAILURE);
//		}
//
//		fObj << combo.c_str() << "\t" << ctime(&timer) << endl;
//	}
//};
//
//
//
//Basket* Basket::pObj = NULL;