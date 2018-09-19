// ConsoleApplication18.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include <string>;

using namespace std;

/*struct date
{
	int day, month, year;
	void enter_date()
	{
		char c;
		cin >> day >> c >> month >> c >> year;
	}
	bool cmp_date(date d)
	{
		return (d.day == day && d.month == month && d.year == year);
	}

	bool operator>(date d)
	{
		if (year > d.year) return true;
		else if (year == d.year)
		{
			if (month > d.month) return true;
			else if (month == d.month)
			{
				if (day > d.day) return true;
				else if (day == d.day) return false;
			}
		}

		return false;
	}
	bool operator==(date d)
	{
		return (d.day == day && d.month == month && d.year == year);
	}

	void print()
	{
		cout << day << '.' << month << '.' << year;
	}

};
struct student
{
	string fname;
	int group;

	date entering_date;
	void enter_student()
	{
		cin >> fname >> group;
		entering_date.enter_date();
	}

	void print()
	{
		cout << fname << " " << group << " ";
		entering_date.print();
		cout << endl;
	}
};*/



struct phone {
	string name;
	int numb;


	//функция добавления номера
	void enter() {
		cin >> name >> numb;
	}


	//функция распечатки
	void print() {
		cout << name << " " << numb << endl;
	}
};

//сортировка по имени
void sort_name(phone *a, int n) {

	for (int j = 0; j < n - 1; j++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (a[i].name > a[i + 1].name) swap(a[i], a[i + 1]);
		}
	}

}

//сортировка по номеру
void sort_numb(phone *a, int n) {

	for (int j = 0; j < n - 1; j++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (a[i].numb > a[i + 1].numb) swap(a[i], a[i + 1]);
		}
	}
}
//добавление записи
void add(phone *&a, int &n) {

	phone *tmp;
	tmp = new phone[n + 1];

	for (int i = 0; i < n; i++)
	{
		tmp[i] = a[i];
	}

	tmp[n].enter();

	delete[]a;
	a = tmp;
	n++;
}

//удаление записи
void del(phone *&a, int&n) {

	string name;
	cout << "name = ";
	cin >> name;

	phone *tmp;

	int k = 0;

	for (int i = 0; i < n; i++)
	{
		if (a[i].name == name) {

			cout << "found namb" << endl;

			k = i;
			
			tmp = new phone[n - 1];

			for (int j = 0, z = 0; j < n - 1; j++, z++)
			{
				if (j < k) tmp[j] = a[j]; else {
					z++;
					tmp[j] = a[z];
				}
			}

			delete[]a;

			a = tmp;
			n--;
			

			break;
		}
	}
}




int main()
{
	setlocale(LC_ALL, "Rus");
	int n = 2;

	//cin >> n;

	phone *p;

	p = new phone[n];

	//заполнение
	for (int i = 0; i < n; i++)
	{
		p[i].enter();
	}


	int x = 1;


	while (x != 0)
	{

		cout << "1. добавить номер\n2.сортировка по имени\n3.сортировка по номеру\n4.распечатка\n5.удалить абонента" << endl;

		cin >> x;
		switch (x)
		{
		case 1: add(p, n);
			break;
		case 2:
			sort_name(p, n); //сортировка по имени
			cout << endl;
			break;
		case 3:
			sort_numb(p, n);//сортировка по номеру
			cout << endl;
			break;
		case 4: //распечатка
			for (int i = 0; i < n; i++)
			{
				p[i].print();
			}
			break;
		case 5: //удаление 
			del(p, n);
		}
	}



	delete[] p;


	/*int n;
	date d;
	student* s;
	cin >> n;
	s = new student[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Enter " << i + 1 << " the student " << endl;
		s[i].enter_student();
	}
	cout << "Enter date to compare with: " << endl;
	d.enter_date();

	for (int i = 0; i < n; i++)
	{
		if (s[i].entering_date > d)
			s[i].print();
	}

	delete[] s;*/

	system("pause");
	return 0;
}
