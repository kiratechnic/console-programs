#include "колибри.h"




int main(){
	setlocale(LC_ALL, "RU-ru");

 	map <string, user> users; 	read_data(users);
	map <size_t, product> products;	read_data(products);

	string nik = "ki";

	do	{
		switch (start())
		{
		case 0:
			nik = log_in(users);
			break;
		case 1:
			nik = registration(users, products);
			break;
		case 2:
			write_data(users);
			write_data(products);
			SetColor(15, 0);
			exit(EXIT_SUCCESS);
		}
		minu(users, products, nik);
		//print_minu(/*users, */products/*, nik*/);
	} while (true);
	return 0;
}



//	users["gg_log"].set_password("123");
//	users["gg_log"].set_name("ki");
//	users["antur"].set_password("333");
//	users["antur"].set_name("an");

//products[1].set_name("маргарита");
//products[1].set_cost(199.99);
//products[4].set_name("с ветчиной и грибами");
//products[5].set_cost(249.99);
//products[3].set_name("пепперони");
//products[3].set_cost(249.99);
//products[4].set_name("4 сыра");
//products[4].set_cost(239.99);
//products[5].set_name("молочный коктейль");
//products[5].set_cost(79.99);
//products[6].set_name("кофе");
//products[6].set_cost(79.99);
//products[7].set_name("чай");
//products[7].set_cost(79.99);
//products[8].set_name("кока-кола");
//products[8].set_cost(59.99);