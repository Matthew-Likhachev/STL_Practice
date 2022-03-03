/*
Задание 1.
С помощью функций библиотеки STL (без классов) реализовать работу очереди без приоритетов по принципу FIFO (использовать вектор, массивы, последовательности).
Последовательность действий:
1.	Начало ввода.
2.	Ввод значений
3.	Окончание ввода.
4.	Вывод значений очереди на консоль.
Задание 2.
С помощью функций библиотеки STL (без классов) реализовать работу стека по принципу LIFO (использовать вектор, массивы, последовательности).
1.	Начало ввода.
2.	Ввод значений
3.	Окончание ввода.
4.	Вывод значений очереди на консоль.
5.	Вывод значение по запросу (номер).

Задание 3.
С помощью функций библиотеки STL (без классов) реализовать работу очереди с приоритетами использовать map, set, multimap, multiset.

1.	Начало ввода.
2.	Ввод значений и приоритетов.
3.	Окончание ввода.
4.	Сортировка по приоритетам
5.	Вывод значений очереди (после сортировки) на консоль.
*/
#include <fstream>        // для файлового ввода/вывода
#include <Windows.h>
#include <string>
#include <string.h>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <conio.h>   // для getche()
#include <locale>
#include <map>

using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "russian");
	
	cout << "Задание 1\n"<<"Введите значения очереди по принципу FIFO (Введите -1 для окончания ввода)\n";
	vector <int> arr1;
	int input=0;

	while (true) {
		cin >> input;
		if (input == -1) break;
		arr1.push_back(input);//add
	}
	cout << endl;
	//Output
	while (true) {
		if (arr1.empty())break;
		cout << arr1[0] << ' ';
		arr1.erase(arr1.begin());//delete
	}
	cout << endl;
	//-----------------------------------------------------------------------------------------------------------------------

	cout << "Задание 2\n" << "Введите значения стека по принципу LIFO (Введите -1 для окончания ввода)\n";
	vector <int> arr2;
	arr1.clear();//helper stack
	input = 0;
	while (true) {
		cin >> input;
		if (input == -1) break;
		arr2.push_back(input);//add
	}
	//Output
	while (true) {
		if (arr2.empty())break;
		cout << arr2[size(arr2)-1] << ' ';
		arr1.push_back(arr2[size(arr2)-1]);//add in new stack for 5 part of TZ
		arr2.erase(arr2.end()-1);//delete from old stack
	}
	// set arr2 stack
	while(true)
	{
		if (arr1.empty()) break;
		arr2.push_back(arr1[size(arr1) - 1]);//add in new stack for 5 part of TZ
		arr1.erase(arr1.end() - 1);//delete from old stack
	}
	//all values now in stack arr2. Continue with it
	input = 0;
	while (true) {
		cout << "\nКакой номер хотите вывести на экран (-1 для отмены)?\n";
		cin >> input;
		if (input == -1) break;
		//except lower and higher value
		if (input > size(arr2)) {
			cout << "Error Wrong Number. Try again\n";
			continue;
		}
		if(input<1) {
			cout << "Error Wrong Number. Try again\n";
			continue;
		}
		int kol_del = size(arr2) - input; //number values t odelete from stack
		//finding target value in arr1, adding wrong values in arr2
		for (int i = 0; i < kol_del; i++)
		{
			arr1.push_back(arr2[size(arr2)-1]);
			arr2.erase(arr2.end()-1);
		}
		cout << arr2[size(arr2)-1];
		//return back values
		for (int i = 0; i < kol_del; i++)
		{
			arr2.push_back(arr1[size(arr1)-1]);
			arr1.erase(arr1.end()-1);
		}
	}
	cout << endl;
	//-----------------------------------------------------------------------------------------------------------------------


	cout << "Задание 3\n" << "Введите значения очереди с приоритетами в формате значение приоритет (Введите -1 для окончания ввода)\n";
	map <int, int> arr3;
	map <int, int> ::iterator i_arr3;
	int value = 0;
	int priority = 0;
	while (true) {
		cin >> value;
		if (value == -1) break;
		cin >> priority;
		arr3.emplace(priority, value);//add key - proirity
	}

	for (i_arr3 = arr3.begin(); i_arr3 != arr3.end(); i_arr3++)
	{
		cout << (*i_arr3).second << ' ';
	}
	return 0;
}