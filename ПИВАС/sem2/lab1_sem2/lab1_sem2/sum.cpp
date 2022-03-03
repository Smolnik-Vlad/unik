#include <string>;
#include "Header.h";
#include<conio.h>
using namespace std;

void helper(int *arr_int, string *arr_str, string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		arr_str[i] = str.substr(i, str.length() - i);
		arr_int[i] = i;
	}

	for (int i = 0; i < str.length() - 1; i++)
	{
		for (int j = i + 1; j < str.length(); j++)
		{
			if (arr_str[i] > arr_str[j])
			{
				swap(arr_str[i], arr_str[j]);
				swap(arr_int[i], arr_int[j]);
			}
		}
	}
}

int* Library::ArrSuf(string str)
{
	string* arr_str = new string[str.length()];
	int* arr_int = new int[str.length()];
	helper(arr_int, arr_str, str);
	return arr_int;
}

string Library::Pref(string str1, int a, int b)
{
	string pref = "", suf1=str1.substr(a, str1.length()-a), suf2=str1.substr(b, str1.length()-b);
	int  size=min(suf1.length(), suf2.length());
	for (int i = 0; i < size; i++)
	{
		if (suf1[i] == suf2[i]) pref += suf1[i];
		else break;
	}
	
	return pref;
}

string Library::Shift(string str)
{
	string str1;
	string* arr_str = new string[str.length()];
	int* arr_int = new int[str.length()];
	helper(arr_int, arr_str, str);
	str1 = arr_str[0] + str.substr(0, str.length() - arr_str[0].length());
	return str1;
}
