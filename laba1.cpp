#include <iostream>
#include <math.h>
using namespace std;
//Лабораторная работа 3.1
int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b, c, x, xn, xk, F{}, dx;
	int ac, bc, cc, i = 0, k{};
	cout << "Введите a ";
	cin >> a;
	cout << "Введите c ";
	cin >> c;
	cout << "Введите b ";
	cin >> b;
	cout << "Введите xn ";
	cin >> xn;
	cout << "Введите xk ";
	cin >> xk;
	cout << "Введите dx ";
	cin >> dx;
	ac = a;
	bc = b;
	cc = c;
	if ((ac & bc) == cc)
	{
		k = 0;
	}
	else
	{
		k = 1;
	}
	cout << "Шаг" << "\t X" << "\t F" << endl << endl;
	for (x = xn; x <= xk; x += dx)
	{
		if ((x == 0) && (b != 0))
		{
			F = a * pow((x + c), 2) - b;
		}
		if ((x == 0) && (b == 0))
		{
			F = (x - a) / (-c);
		}
		else
		{
			F = a + (x / c);
		}

		if (k != 0)
		{
			cout << ++i << "\t| " << x << "\t| " << F << endl;
		}
		else
		{
			cout << ++i << "\t| " << x << "\t| " << int(F) << endl;
		}
	}
	return 0;
}
