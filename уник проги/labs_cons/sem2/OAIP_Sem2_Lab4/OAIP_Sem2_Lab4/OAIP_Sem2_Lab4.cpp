#include "iostream";
#include "string";
#include "vector";
#include "windows.h"; 
using namespace std;

void linear_search(vector<string> name_of_product)
{
	string prod;
	cout << "Введите товар, номер которого нужно найти в списке товаров: ";
	cin >> prod;
	for (int i = 0; i < name_of_product.size(); i++)
	{
		if (prod == name_of_product[i]) cout << "Номер товара в списке: "<<i + 1<<endl;
	}
}

void direct_choice(vector<string> name_of_product)
{

	int size = name_of_product.size(), min;

	for (int i = 0; i < size - 1; i++)
	{
		min = i;

		for (int l = i+1; l < size; l++)
		{
			if (name_of_product[min] > name_of_product[l]) min=l;
		}
		swap(name_of_product[i], name_of_product[min]);

	}

	for (int i = 0; i < name_of_product.size(); i++)
	{
		cout << name_of_product[i] << " "<<endl;;
	}
}

void QuickSort_2(vector<string>& name_of_product, int right, int left)
{
	int r = right, l = left;
	string bar = name_of_product[(l + r) / 2];
	while (l <= r)
	{
		while (name_of_product[l] < bar) l++;
		while (name_of_product[r] > bar) r--;

		if (l <= r)
		{
			swap(name_of_product[l], name_of_product[r]);
			l++;
			r--;
		}

	};
	if (r > left)
	{
		QuickSort_2(name_of_product, r, left);
	}

	if (l < right)
	{
		QuickSort_2(name_of_product, right, l);
	}

}

vector<string> QuickSort_1(vector<string> name_of_product)
{
	vector<string> name_of_prod = name_of_product;
	QuickSort_2(name_of_prod, name_of_prod.size() - 1, 0);

	for (int i = 0; i < name_of_prod.size(); i++) cout << name_of_prod[i] << ' ';
	return name_of_prod;
}

int binary_search_2(vector<string> name_of_prod, string key, int left,int right)
{
	int midd = 0;

	while (true)
	{
		midd = (left + right) / 2;
		if (key == name_of_prod[midd]) return midd;
		else if (key > name_of_prod[midd]) left = midd + 1;
		else if (key < name_of_prod[midd]) right = midd - 1;

		if (left > right) return -1;
	}
	
}

void binary_search_1(vector<string> name_of_product)
{
	vector < string> name_of_prod = QuickSort_1(name_of_product);
	string prod;
	cout << "Введите имя товара: ";
	cin >> prod;
	int numb_of_prod = binary_search_2(name_of_prod, prod, 0, name_of_prod.size() - 1);
	if (numb_of_prod != -1)
		cout << "Номер товара в списке: " << numb_of_prod+1 << endl;
	else cout << "Такого товара нету в списке." << endl;
}


void search_and_sort(vector<string> name_of_product)
{
	int choose;
	vector<string> product_quick_sort (name_of_product.size());
	cout << "1. Линейный поиск 2. Сортировка массива методом прямого выбора 3. Сортировка массива методом QuickSort 4. Двоичный поиск в отсортированном массиве: " ;
	cin >> choose;
	switch (choose)
	{
	 case 1:
		 linear_search(name_of_product);
		 break;
	 case 2:
		 direct_choice(name_of_product);
		 break;
	 case 3:
		 QuickSort_1(name_of_product);
		 break;
	 case 4:
		 binary_search_1(name_of_product);
		 break;
	}
}

class Product
{
private:
	string name_of_product;
	int number, date, price;
public:
	void product(string name)
	{
		name_of_product = name;
		cout << "\nКоличество единиц товара "<<name_of_product<<": ";
		cin >> number;
		cout << "\nДата поступления товара (сколько ммесяцев назад): ";
		cin >> date;
		cout << "\nЦена товара: ";
		cin >> price;
	}


	void new_product(string& name_of_product_str)
	{
		cout << "\nНаименование товара: ";
		cin >> name_of_product;
		name_of_product_str = name_of_product;
		cout << "\nКоличество единиц товара: ";
		cin >> number;
		cout << "\nДата поступления товара (сколько ммесяцев назад): ";
		cin >> date;
		cout << "\nЦена товара: ";
		cin >> price;
	}

	void info()
	{
		cout << "Наименование товара: "<<name_of_product<<endl;
		cout << "Количество единиц товара: "<<number<<endl;
		cout << "Дата поступления товара (сколько ммесяцев назад): " << date << endl;
		cout << "Цена товара: "<<price<<endl<<endl;
	}

	string definite_product_name_get()
	{
		if (date > 1 && price > 100000) return name_of_product;
	}
};

void set_product(vector<Product>& products, vector<string>& name_of_product)
{
	cout << "Вводите товары в сторку: ";
	string str_prod, str_p;
	getline(cin, str_prod);
	str_prod+=' ';
	for (int i = 0; i < str_prod.length(); i++)
	{
		if (str_prod[i] != ' ')
		{
			str_p += str_prod[i];
		}
		else if (str_prod[i] == ' ' && str_p!="")
		{
			name_of_product.push_back(str_p);
			str_p = "";
		}
	}
	products.resize(name_of_product.size());
	for (int i = 0; i < name_of_product.size(); i++)
	{
		products[i].product(name_of_product[i]);
	}
	
}

void definite_product(vector<Product> products)
{
	vector<string> names_of_def_prod;
	for (int i = 0; i < products.size(); i++)
	{
		string name = products[i].definite_product_name_get();
		if (name != "") names_of_def_prod.push_back(name);
		names_of_def_prod = QuickSort_1(names_of_def_prod);
		
	}
	for (int i = 0; i < names_of_def_prod.size(); i++) cout << names_of_def_prod[i] << " ";
	cout << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choose;
	bool indic = true;
	vector<Product> products = {};
	vector<string> name_of_product;

	set_product(products, name_of_product);

	while (indic)
	{
		cout << "1. Добавить товар 2. Просмотреть товар 3. Поиски и сортировки 4. Вывести в алфавитном порядке список товаров, хранящихся больше месяца, цена которых более 100 000р 5. Выйти из программы: ";

		cin >> choose;
		switch (choose)
		{
		 case 1:
			products.resize(products.size() + 1);
			name_of_product.resize(name_of_product.size() + 1);
			products[products.size() - 1].new_product(name_of_product[name_of_product.size() - 1]);
			break;

		 case 2:
			if (products.size() != 0)
			{
				cout << "Вывести инфу по товару: ";
				for (int i = 0; i < name_of_product.size(); i++)
				{
					cout << i + 1 << ". " << name_of_product[i] << ' ';
				}
				cin >> choose;
				products[choose - 1].info();
				break;
			}
			else cout << "Нет ни одного товара" << endl;
			break;

		 case 3:
			 search_and_sort(name_of_product);
			 break;

		 case 4:
			 definite_product(products);
			 break;

		 case 5:
			 indic = !indic;
		}
	}
	
}