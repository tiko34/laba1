#include <iostream>
#include <math.h>
using namespace std;
//Лабораторная работа 2
int main()
{
	setlocale(LC_ALL, "Russian");
	double x1, y1;
	cout << "Введите x1 ";
	cin >> x1;
	cout << "Введите y1 ";
	cin >> y1;
	if ((y1 >= x1 && y1 <= 0 && y1 <= -pow(x1, 2) + 2) || (y1 <= x1 && y1 >= 0 && y1 <= -pow(x1, 2) + 2))
	{
		cout << "Вы попали";
	}
	else
	{
		cout << "Вы не попали";
	}
}
