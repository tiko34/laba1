

#include <iostream>

using namespace std;
//Лабораторная работа 4
int main()
{
	setlocale(LC_ALL, "Russian");
	int summod = 0;
	int minus = 0;
	int numbers[5]{ -5,2,0,-2,10 };
	//Вывод массива
	cout << "Массив:";
	for (int i = 0; i < size(numbers); i++)
	{
		cout << numbers[i] << " ";
	}
	//Вычисление количества отрицательных чисел
	for (int i = 0; i < size(numbers); i++)
	{
		if (0 < numbers[i])
		{
			minus++;
		}
	}
	cout << endl << "Количество отрицательных значений в массиве:" << minus;
	//Найти сумму модулей элементов массива, расположенных после минимального по модулю элемента.
	cout << endl << "Элементы массива по модулю: ";
	for (int i = 0; i < size(numbers); i++)
	{
		cout << " " << abs(numbers[i]);
	}
	//переменная с которой сравниваем все числа в массиве
	int minelement = abs(numbers[0]);
	//ищем минимальное число по модулю в массиве
	for (int i = 0; i < size(numbers); i++)
	{
		//если число из массива по модулю меньше чем mielement
		//тогда minelement будет равен индексу этого числа в массиве
		if (abs(numbers[i]) < minelement)
		{
			minelement = i;

		}
	}
	//Рассчет суммы модулей элементов после минимального числа в модуле
	for (int i = minelement + 1; i < size(numbers); i++)
	{
		summod += abs(numbers[i]);
	}
	cout << endl << "Сумма модулей элементов: " << summod << endl;

	//Заменить все отрицательные элементы массива их квадратами 
//и упорядочить элементы массива по возрастанию.
//сортировка пузырьком
	for (int i = 0; i < size(numbers); i++) {
		if (numbers[i] < 0)
		{
			numbers[i] = numbers[i] * numbers[i];
		}
		//	cout << numbers[i] << " "; // выводим элементы массива
	}

	for (int i = 0; i < size(numbers); i++) {
		for (int j = 0; j < size(numbers) - 1; j++) {
			if (numbers[j] > numbers[j + 1]) {
				int b = numbers[j]; 
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = b; 
			}
		}
	}
	//Вывод готовокго массива
	cout << "Массив в отсортированном виде и возведением в степень отрицательных чисел: ";
	for (int i = 0; i < size(numbers); i++)
	{
		cout << numbers[i] << " ";
	}
}

