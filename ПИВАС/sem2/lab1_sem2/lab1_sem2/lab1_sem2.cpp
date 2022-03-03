#include <iostream>
#include "Header.h";
#include <string>;
using namespace std;

void shift()
{
	cout << "Введите строку для нахожденя минимального сдвига: ";
	string str;
	cin >> str;
	Library a;
	cout << a.Shift(str);
}

void pref()
{
	cout << "Введите строку и две позиции для нахождения префикса: ";
	string str1, str;
	int c, b;
	cin >> str1 >> c >> b;
	Library a;
	str = a.Pref(str1, c, b);
	if (str != "") cout << "Наибольший общий префикс: " << str;
	else cout << "Общих префиксов нет!";
}

void suf_arr()
{
	cout << "Введите строку для нахождения суффиксного массива: ";
	string str;
	cin >> str;
	int* arr = new int[str.length()];
	Library a;
	arr = a.ArrSuf(str);
	for (int i = 0; i < str.length(); i++)
	{
		cout << arr[i] << ' ';
	}
	delete[] arr;
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Выберете действия: 1.Суффиксный массив; 2.Нахождение наименьшего циклического сдвига строки 3.Наибольший общий префикс: ";
	int switch_on;
	cin >> switch_on;
	 
	switch (switch_on)
	{
	case 1:
		suf_arr();
		break;

	case 2:

		shift();
		break;

	case 3:
		pref();
	}
	
	
}