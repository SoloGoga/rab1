#include "pch.h"
#include <iostream>
#include "string.h" //библиотека для функций над строками
#include <cstdlib> //библиотека для системы
using namespace std;


int main()
{
	struct Name
	{
		char surname[15];
		char name[15];
		char second[15];
	}; //создаем структуру для введения полного имени студента
	 //surname-фамилия, name-имя, second-отчество
	struct Date
	{
		int year;
		int month;
		int day;
	};
	struct student
	{
		Name fullname;
		Date date;
		char group[7];
		char fac[8];//название факультета в аббревиатуре
	};
	int n;
	cout << "Input the quantity of elements in massiv: ";
	cin >> n;

	//const int n = 3;
	int i;
	student *vuz = new student[n];

	for (i = 0; i < n; i++)
	{
		cout << "input the surname of the " << i + 1 << " student:";
		cin >> vuz[i].fullname.surname;
		cout << "input the name of the " << i + 1 << " student:";
		cin >> vuz[i].fullname.name;
		cout << "input the second name of the " << i + 1 << " student:";
		cin >> vuz[i].fullname.second;
		cout << "input the year of enter to university of the " << i + 1 << " student:";
		cin >> vuz[i].date.year;
		cout << "input the month of enter to university of the " << i + 1 << " student:";
		cin >> vuz[i].date.month;
		cout << "input the day of enter to university of the " << i + 1 << " student:";
		cin >> vuz[i].date.day;
		while (((vuz[i].date.year > 2018) || (vuz[i].date.year < 1950)) && ((vuz[i].date.month > 12) || (vuz[i].date.month < 1)) && ((vuz[i].date.day > 31) || (vuz[i].date.day < 1)))
		{
			if ((vuz[i].date.year > 2018) || (vuz[i].date.year < 1950))
			{
				cout << "Not right significance of the year. Please try again." << endl;
				cin >> vuz[i].date.year;
			}
			if ((vuz[i].date.month > 12) || (vuz[i].date.month < 1))
			{
				cout << "Not right significance of the month. Please try again." << endl;
				cin >> vuz[i].date.month;
			}
			if ((vuz[i].date.day > 31) || (vuz[i].date.day < 1))
			{
				cout << "Not right significance of the day. Please try again." << endl;
				cin >> vuz[i].date.day;
			}
		}
		cout << "input the group of the " << i + 1 << " student:";
		cin >> vuz[i].group;
		cout << "input the name of the faculty of the " << i + 1 << " student:";
		cin >> vuz[i].fac;
	}
	system("cls");
	student tmp;
	char fac1[8];
	cout << "Input the name of the faculty information about you want to see: " << endl;
	cin >> fac1;
	char group1[7];
	int j;
	for (i = 0; i < n; i++)
	{
		if (strcmp(vuz[i].fac, fac1) == 0)
		{
			cout << "Input the name of the group information about its students you want to see: " << endl;
			cin >> group1;
			if (strcmp(vuz[i].group, group1) == 0)
			{
				for (i = 0; i < n - 1; i++)
				{
					for (j = i + 1; j < n; j++)
					{
						if (strcmp(vuz[i].fullname.surname, vuz[j].fullname.surname) > 0)
						{
							tmp = vuz[i];
							vuz[i] = vuz[j];
							vuz[j] = tmp;
						}
					}
				}
				system("cls");
				cout << "Information about " << group1 << ": " << vuz[i].fullname.surname << " " << vuz[i].fullname.name << " " << vuz[i].fullname.second << " " << vuz[i].date.day << "." << vuz[i].date.month << "." << vuz[i].date.year << endl;

			}
		}
	}
	delete[] vuz;
	system("pause");


}
return 0;
