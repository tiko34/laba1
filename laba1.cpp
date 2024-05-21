

#include <iostream>
using namespace std;
//Лабораторная работа 4
int main()
{
	setlocale(LC_ALL, "Russian");
	int minus=0;
	int numbers[5]{ -5,-2,0,7,10 };
	//Вывод массива
	cout << "Массив:";
	for (int i = 0; i<size(numbers); i++)
	{
		cout << numbers[i]<<",";
	}
	//Вычисление количества отрицательных чисел
	for (int i = 0; i < size(numbers); i++)
	{
		if ( 0<numbers[i])
		{
		 minus++;
		}
	} 
	cout << endl << "Количество отрицательных значений в массиве:" << minus;
	//Найти сумму модулей элементов массива, расположенных после минимального по модулю элемента.
	cout <<endl<< "Элементы массива по модулю: ";
	for (int i = 0; i < size(numbers); i++)
	{
		cout << abs(numbers[i])<<",";
	}
}

