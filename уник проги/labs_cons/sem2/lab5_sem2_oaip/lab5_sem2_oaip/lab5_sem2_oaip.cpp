#include <iostream>
using namespace std;

template<typename T>
class List
{
private:

	template <typename T>
	struct Node		//структура, храняшая данные и указатель на следующий узедл
	{
	public:
		Node *pNext;
		T data;

		Node(T data = NULL, Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	}; 

	int Size;
	Node<T> *head;
	Node<T>* last;


public:
	List()
	{
		Size = 0;
		head = nullptr; //Так как нету ни одного элемента, head тоже нету, но мы его объявляем при создании самой структуры
	};

	void push_back(T data)			//Функция добавления нового узла
	{
		if (head == nullptr)		//Если это самый первый узел
		{
			head = new Node<T>(data); //Создаем самый первый узел, head - указатель на него
			/*last = head; //кусок второго варианта*/ 
		}
		else
		{
			Node<T>* current = this->head;  //временный указатель, который будет меняться, пока не будет укзывать на последний узел, изначально указывает на самый первый элемент
			while(current->pNext!=nullptr) //поскольку последний узел не имеет указатель на слежующий узел, то current будет брать pNext со следующего узла, пока тот не станет последним 
			{
				current = current->pNext; //current принимает указатель на следующий узел
			}
			current->pNext = new Node<T>(data); //создаем новый узел и запихиваем его адрес в указатель pNext предыдущего узла


			/*last = (last->pNext = new Node<T>(data)); //Вторрой вариант добавления нового узла, заключается в том, что он сразу хранит указатель на последний узел*/
		
		}
		Size++;
		
		
	};

	void size() { return Size; }; //функция вывода размера списка

	

	T& operator[](const int index) //функция для вывода любого элемента 
	{
		Node<T>* current = this->head;  //создаем временный указатель, указывающий на самый первый узел
		for (int i = 0; i < index; i++)
		{
			current = current->pNext; //временный указатель принимает адрес следующего узла
		}
		return current->data;
	}
	
};



int main()
{
	setlocale(LC_ALL, "rus");
	List<int> lst;
	lst.push_back(5);
	lst.push_back(10);
	cout<<endl<<lst[0];
}


