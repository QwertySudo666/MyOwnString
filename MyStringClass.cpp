﻿// MyStringClass.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstring> //для strcpy(), и т.д.
using namespace std;
///////////////////////////////////////////////////////////

class String
{
private:
	char* str; // указатель на строку
	int length;
public:
	String()
	{

	}
	String(const char* pstr) // конструктор с одним параметром
	{
		length = strlen(pstr); // вычисляем длину строки
		str = new char[length + 1]; // выделяем необходимую память
		for (int i = 0; i < length; i++)
		{
			str[i] = pstr[i];
		}
		str[length] = '\0';
	}
	~String() // деструктор
	{
		//cout << "Delete line\n";
		delete[] str; // освобождаем память
	}

	String& operator =(const String &other)
	{
		if (str!=nullptr)
		{
			delete[] str;
		}

		length = strlen(other.str); // вычисляем длину строки
		str = new char[length + 1]; // выделяем необходимую память
		for (int i = 0; i < length; i++)
		{
			str[i] = other.str[i];
		}
		str[length] = '\0';

		return *this;
	}

	void display() // покажем строку на экране
	{
		int i = 0;
		for (;i<length; i++)
		{
			cout<<str[i];
		}
		cout << endl;
	}
	
	void Print()
	{
		cout << str;
		cout << endl;
	}
};
///////////////////////////////////////////////////////////
int main()
{
	String str="Hello world";
	str = "new line";
	str.display();
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
