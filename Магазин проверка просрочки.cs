using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace zxcvbnm
{
    class product
    {
        public uint id { get; set; } = 0;
        public string name { get; set; }
        public DateTime date_making { get; set; }
        public DateTime data_shelf { get; set; } = DateTime.Now;
        public int price { get; set; } = 0;
        public string print()
        {
            return $"Имя: \nФамилия: \nДата рождения: \nГруппа: \n";
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Dictionary<uint, List<product>> products_on_salem = new Dictionary<uint, List<product>>();
            Dictionary<uint, List<product>> scrapped_products = new Dictionary<uint, List<product>>();

            products_on_salem.Add(0, new List<product> { new product { id = 0, name = "молоко село зеленое", date_making = DateTime.Parse("30.01.2022"), data_shelf = DateTime.Now, price = 68 } });
            products_on_salem[0].Add( new product { id = 0, name = "молоко домик в деревне", date_making = DateTime.Parse("25.02.2022"), data_shelf = DateTime.Now, price = 78 } );

            products_on_salem.Add(1, new List<product> { new product { id = 1, name = "кефир", date_making = DateTime.Parse("13.03.2022"), data_shelf = DateTime.Now, price = 62 } });
            products_on_salem[1].Add(new product { id = 1, name = "кефир домик в деревне", date_making = DateTime.Parse("26.01.2022"), data_shelf = DateTime.Now, price = 68 });

            products_on_salem.Add(2, new List<product> { new product { id = 2, name = "кило яблок", date_making = DateTime.Parse("21.01.2022"), data_shelf = DateTime.Now, price = 89 } });
            products_on_salem[2].Add(new product { id = 2, name = "кило яблок голден", date_making = DateTime.Parse("13.02.2022"), data_shelf = DateTime.Now, price = 93 });

            products_on_salem.Add(3, new List<product> { new product { id = 3, name = "пачка конфет", date_making = DateTime.Parse("26.01.2022"), data_shelf = DateTime.Now, price = 45 } });

            scrapped_products.Add(0, new List<product> { new product { id = 0, name = "молоко", date_making = DateTime.Parse("30.01.2020"), data_shelf = DateTime.Now, price = 68 } });
            scrapped_products[0].Add(new product { id = 0, name = "молоко домик в деревне", date_making = DateTime.Parse("21.02.2020"), data_shelf = DateTime.Now, price = 78 });

            scrapped_products.Add(1, new List<product> { new product { id = 1, name = "кефир", date_making = DateTime.Parse("13.03.2020"), data_shelf = DateTime.Now, price = 68 } });
            scrapped_products.Add(2, new List<product> { new product { id = 2, name = "кило яблок", date_making = DateTime.Parse("21.01.2020"), data_shelf = DateTime.Now, price = 68 } });
            scrapped_products.Add(3, new List<product> { new product { id = 3, name = "конфета", date_making = DateTime.Parse("26.01.2020"), data_shelf = DateTime.Now, price = 68 } });


            do
            {
                Console.Clear();
                Write("1 - Вывод списков продуктов\n2 - Edit mod\nEscape - закрыть программу\n>");
                switch (ReadKey().Key)
                {
                    case ConsoleKey.D1:
                        Console.Clear();
                        print(ref products_on_salem, ref scrapped_products);
                        break;
                    case ConsoleKey.D2:
                        Console.Clear();
                        edit_mode(ref products_on_salem, ref scrapped_products);
                        break;
                    case ConsoleKey.Escape:
                        return;
                }
                ReadKey();
            } while (true);
        }

        static void print(ref Dictionary<uint, List<product>> products_on_salem, ref Dictionary<uint, List<product>> scrapped_products, bool edit_mode = false) {
            Dictionary<uint, List<product>>.Enumerator iter_dict; //итератор на словарь с продуктами
            List<product>.Enumerator iter_list; //итератор на list в котором лежит продук определеного id
            int i = 1, sum = 0;
            do
            {
                Console.Clear();
                Write("\tВывод:\n1 - Продуктов на продаже\n2 - Испорченых продуктов\nEscape - выход в главное меню\n>");
                switch (edit_mode ? ConsoleKey.D1 : ReadKey().Key)
                {
                    case ConsoleKey.D1:
                        Console.Clear();
                        if (products_on_salem.Count == 0) { Write("Список продуктов на продаже пуст!"); break; }
                        i = sum = 0;
                        WriteLine("Продукты на продаже:");
                        iter_dict = products_on_salem.GetEnumerator();// приписываем итератору адрес словаря
                        while (iter_dict.MoveNext()) 
                        {
                            iter_list = iter_dict.Current.Value.GetEnumerator();
                            while (iter_list.MoveNext()) 
                            {
                                SetCursorPosition(0, i + 1); Write($" *  {iter_list.Current.name}:\n\tизготовлено: {iter_list.Current.date_making}\n\tгоден до: {iter_list.Current.data_shelf}\n\tстоимость - {iter_list.Current.price}\n");
                                sum += iter_list.Current.price;
                                i += 4;
                            }
                        }
                        WriteLine($"  ИТОГ - {sum}");
                        if (edit_mode) return;
                        break;
                    case ConsoleKey.D2:
                        Console.Clear();
                        if (scrapped_products.Count == 0) { Write("Список списанных продуктов пуст!"); break; }
                        i = sum = 0;
                        WriteLine("Испорченые продукты:");
                        iter_dict = scrapped_products.GetEnumerator();// приписываем итератору адрес словаря с просрочкой
                        while (iter_dict.MoveNext())
                        {
                            iter_list = iter_dict.Current.Value.GetEnumerator(); 
                            while (iter_list.MoveNext())
                            {
                                SetCursorPosition(0, i + 1); Write($" *  {iter_list.Current.name}:\n\tизготовлено: {iter_list.Current.date_making}\n\tгоден до: {iter_list.Current.data_shelf}\n\tстоимость - {iter_list.Current.price}\n");
                                sum += iter_list.Current.price;
                                i += 4;
                            }
                        }
                        WriteLine($"  ИТОГ - {sum}");
                        break;
                    case ConsoleKey.Escape:
                        return;
                }
                ReadKey();
            } while (true);
        }
        static void edit_mode(ref Dictionary<uint, List<product>> products_on_salem, ref Dictionary<uint, List<product>> scrapped_products)
        {
            if (products_on_salem.Count == 0) { Write("Список продуктов на продаже пуст!"); return; }
            int cursor = 1; //lkz jnhbcjdrb dthyjq nbgf lkz rf;ljuj cdjq vtcnj
            Dictionary<uint, List<product>>.Enumerator iter_dict;
            List<product>.Enumerator iter_list;

            do
            {
                iter_dict = products_on_salem.GetEnumerator(); iter_dict.MoveNext();
                iter_list = iter_dict.Current.Value.GetEnumerator(); iter_list.MoveNext();
                cursor = 1;

                print(ref products_on_salem, ref scrapped_products, true);
                WriteLine("Escape - выход в главное меню");
                do
                {
                    ForegroundColor = ConsoleColor.Magenta;
                    SetCursorPosition(0, cursor); Write($" *  {iter_list.Current.name}:\n\tизготовлено: {iter_list.Current.date_making}\n\tгоден до: {iter_list.Current.data_shelf}\n\tстоимость - {iter_list.Current.price}\n");
                    ResetColor();
                    switch (ReadKey().Key)
                    {
                        //case ConsoleKey.UpArrow:
                        //    cursor = (cursor == 0) ? 11 : cursor - 1;
                        //    break;
                        case ConsoleKey.DownArrow:
                            SetCursorPosition(0, cursor); Write($" *  {iter_list.Current.name}:\n\tизготовлено: {iter_list.Current.date_making}\n\tгоден до: {iter_list.Current.data_shelf}\n\tстоимость - {iter_list.Current.price}\n");
                            if (iter_list.MoveNext())
                            {
                                cursor += 4;
                            }
                            else
                            {
                                if (iter_dict.MoveNext()) {
                                    iter_list = iter_dict.Current.Value.GetEnumerator();
                                    iter_list.MoveNext();
                                    cursor += 4;
                                }
                                else {
                                    iter_dict = products_on_salem.GetEnumerator();
                                    iter_dict.MoveNext();
                                    iter_list = iter_dict.Current.Value.GetEnumerator();
                                    iter_list.MoveNext();
                                    cursor = 1;
                                }
                            }
                            //cursor = (iter_list) ? 0 : cursor + 1;
                            break;
                        case ConsoleKey.Enter:
                            scrapped_products[iter_list.Current.id].Add(iter_list.Current);
                            products_on_salem[iter_list.Current.id].Remove(iter_list.Current);
                            if (products_on_salem[iter_list.Current.id].Count == 0)
                            {
                                products_on_salem.Remove(iter_list.Current.id);
                            }
                            cursor = -1;
                            break;
                        case ConsoleKey.Escape:
                            return;
                    }
                } while (cursor != -1);
            } while (products_on_salem.Count != 0);
        }
    }
}


/*
foreach(var v in dictionary["Phisics"])
{
   Console.WriteLine(v.Name);
}
*/

                    //case ConsoleKey.LeftArrow:
                    //    break;
                    //case ConsoleKey.RightArrow:
                    //    break;


//функция вывода, выбора, удаления че хош купить на с++ не робит причины хз вроде какоето исключение

