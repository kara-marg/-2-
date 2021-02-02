#include <iostream>
#include <cstring>
#include <fstream>
#include "Лабораторная работа 1.h"
using namespace std;

/* 8. Приймальна комісія.Абітурієнт реєструється на один з факультетів з фіксованим планом
набору, уводить бали по відповідним предметам і атестаті.Система підраховує суму балів і
визначає абітурієнтів, зарахованих у навчальний заклад.*/


struct Student
{
	char login[20];
	char password[20];
};

int main()
{
	char filename[86] = "D:\\Прога\\Лабораторные работы\\Второй семестр\\Лабораторная работа 1\\Login; password.txt";
	char filename2[86] = "D:\\Прога\\Лабораторные работы\\Второй семестр\\Лабораторная работа 1\\Registration.txt";
	cout << "____Authorization____" << endl;

	MenuCrud();
	int choice;
	cout << "Enter choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1: log_in(); break;
	case 2: registration(filename2); break;
	}
}

void MenuCrud()
{
	cout << endl;
	cout << "1 - Log in" << endl;
	cout << "2 - Registration" << endl;
}

void log_in()
{
	cout << "____Log in____" << endl;
	login();
	password();
}

void registration(char  filename2[86])
{
	cout << "____Registration____" << endl;
	ofstream fout("Registration.txt"); // создаём объект класса ofstream для записи и связываем его с файлом Registration.txt
	cout << "Login: ";
	cin >> filename2;
	fout << "Login:" << endl << filename2 << endl; // запись строки в файл
	cout << "Password: ";
	cin >> filename2;
	fout << "Password:" << endl << filename2; // запись строки в файл
	fout.close(); // закрываем файл
}

void login()
{
	ifstream fin("Login; password.txt"); //создаём объект класса ifstream  для чтения файла
	if (fin.is_open()) //если файл успешно открыт, читаем строки
	{
		cout << "Enter login: " << endl;
		char login[20];
		cin >> login; //вводим логин
		const int maxStringLengh = 100; //максимальная длинна строки для поиска символа переноса строки
		int numStringsToSkip = 1; //кол-во пропускамых строк перед чтением
		for (int i = 0; i < numStringsToSkip; i++) // пропускаем не нужные нам строки
		{
			char* tmp = new char[maxStringLengh];
			fin.getline(tmp, maxStringLengh);
			delete[] tmp;
		}

		char* filename = new char[maxStringLengh];
		fin.getline(filename, maxStringLengh); //читаем желаемую строку

		int k = strcmp(login, filename);//проверка логина и строки
		if (k == 1)// если 1 - логин не правильный
		{
			cout << "wrong login" << endl;
		}
	}
}

void password()
{
	ifstream fin("Login; password.txt"); //создаём объект класса ifstream  для чтения файла
	if (fin.is_open()) //если файл успешно открыт, читаем строки
	{
		cout << "Enter password: " << endl;
		char password[20];
		cin >> password; //вводим пароль
		const int maxStringLengh = 1000; //максимальная длинна строки для поиска символа переноса строки
		int numStringsToSkip = 3; //кол-во пропускамых строк перед чтением
		for (int i = 0; i < numStringsToSkip; i++) // пропускаем не нужные нам строки
		{
			char* tmp = new char[maxStringLengh];
			fin.getline(tmp, maxStringLengh);
			delete[] tmp;
		}

		char* filename = new char[maxStringLengh];
		fin.getline(filename, maxStringLengh); //читаем желаемую строку

		int k = strcmp(password, filename);//проверка пароля и строки
		if (k == 1)// если 1 - пароль не правильный
		{
			cout << "wrong password" << endl;
		}
	}
}