#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

class SuperString
{

private:
	string line;
	static int count; //количество экземпляров класса

public:
	//конструктор без параметров

	SuperString()
	{
		count++;
		line = "";
	}
	//конструктор с заданными значениями

	SuperString(string str)
	{
		count++;
		line = str;
	}

	//функция, позволяющая определить количество объектов типа SuperString
	int getCount()
	{
		return count;
	}

	//функция, возвращающая длину строки
	int length()
	{
		return line.length();
	}

	//функция для вывода строки на экран
	void show(string name)
	{
		out << name << " = " << line << endl;
	}

	//функция для подсчёта количества цифр в строке
	int digitsAmount()
	{
		int amount = 0;
		for (int i = 0; i < line.length(); i++)
		{
			if (isdigit(line[i]))
			{
				amount++;
			}
		}

		return amount;
	}

	//функция, подсчитывающая, сколько раз символ встречается в строке
	int symbolAmount(char c)
	{
		int amount = 0;
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] == c)
			{
				amount++;
			}
		}

		return amount;
	}

	//функция, выводящая на экран символы, встречающиеся в строке только 1 раз
	void showSymbols()
	{
		for (int i = 0; i < line.length(); i++)
		{
			if (symbolAmount(line[i]) == 1)
			{
				out << line[i];
			}
		}

		out << endl;
	}

	//функция, выводящая на экран самую длинную последовательность повторяющихся символов
	void showLongest()
	{
		string max;
		for (int i = 0; i < line.length(); i++)
		{
			string temp;
			for (int j = i; j < line.length() && line[i] == line[j]; j++)
			{
				temp += line[j];
				i = j;
			}

			if (temp.length() > max.length())
			{
				max = temp;
			}
		}

		out << max << endl;
	}

	//сравнение двух строк на равенство
	bool isEqual(SuperString str)
	{
		return line == str.line;
	}

	//перегрузка оператора ! (true - если строка не пустая, иначе false)
	bool operator!()
	{
		return line != "";
	}

	//перегрузка оператора + (сложение строк)
	SuperString operator+(SuperString x)
	{
		return SuperString(line + x.line);
	}
};

int SuperString::count = 0; //инициализация счётчика

// будем хранить суперстроки в односвязном списке
//односвязный список
class ListException
{
private:
	string message;

public:
	ListException(string message) : message(message) {}
	string what()
	{
		return message;
	}
};

template <class Item>

class List
{
private:
	struct Element
	{
		Item inf;
		Element* next;
		Element(Item x) : inf(x), next(0) {}
	};

	Element* head;
	int size;
	Element* Find(int index)
	{
		if ((index < 1) || (index > size))
		{
			return 0;
		}
		else
		{
			Element* cur = head;
			for (int i = 1; i < index; i++)
			{
				cur = cur->next;
			}

			return cur;
		}
	}

public:
	List() : head(0), size(0) {}

	bool Empty()
	{
		return head == 0;
	}

	int GetLength()
	{
		return size;
	}

	Item Get(int index)
	{
		if ((index < 1) || (index > size))
		{
			throw ListException("ListException: Get - wrong index");
		}
		else
		{
			Element* r = Find(index);
			Item i = r->inf;
			return i;
		}
	}

	void Insert(int index, Item data)
	{
		if ((index < 1) || (index > size + 1))
		{
			throw ListException("ListException: insert - wrong index");
		}
		else
		{
			Element* newPtr = new Element(data);
			size = GetLength() + 1;
			if (index == 1)
			{
				newPtr->next = head;
				head = newPtr;
			}
			else
			{
				Element* prev = Find(index - 1);
				newPtr->next = prev->next;
				prev->next = newPtr;
			}
		}
	}
};

int main()
{
	//создадим список супер строк
	List<SuperString> mas;
	string temp;

	while (getline(in, temp)) //считываем все строки из файла
	{
		mas.Insert(mas.GetLength() + 1, temp);//записываем их в конец списка
	}

	//выведем на экран все строки, считанные из файла
	out << "Lines read from file:" << endl;

	for (int i = 1; i <= mas.GetLength(); ++i)
	{
		mas.Get(i).show("mas.Get(i)");
	}

	out << endl;

	//что бы проще было обращаться со строками (и не переписывать остальной код)

	//обозначим первые 2 элемента в списке как A и B
	SuperString A(mas.Get(1));
	SuperString B(mas.Get(2));

	if (!A)
	{
		out << "A isn't empty" << endl;
	}
	else
	{
		out << "A is empty" << endl;
	}

	out << "A.length() = " << A.length() << endl;
	out << "A.digitsAmount() = " << A.digitsAmount() << endl;
	out << "A.showSymbols(): "; A.showSymbols();
	out << "A.showLongest(): "; A.showLongest();
	out << endl;

	if (!B)
	{
		out << "B isn't empty" << endl;
	}
	else
	{
		out << "B is empty" << endl;
	}

	out << "B.length() = " << B.length() << endl;
	out << "B.digitsAmount() = " << B.digitsAmount() << endl;
	out << "B.showSymbols(): "; B.showSymbols();
	out << "B.showLongest(): "; B.showLongest();
	out << endl;

	if (A.isEqual(B))
	{
		out << "A == B" << endl;
	}
	else
	{
		out << "A != B" << endl;
	}

	SuperString C = A + B;
	C.show("C");

	//покажет 4, так как 3 строки в файле и ещё мы создали C
	out << "getCount() = " << A.getCount() << endl;

	return 0;
}
