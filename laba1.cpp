#include <iostream>
using namespace std;
//Лаборатораня работа 5
int main()
{
	setlocale(LC_ALL, "Russian");
	const int rows = 3, columns = 5;
	int numbers[rows][columns]
	{
		{7,1, 7,7,0},
		{ -4,-4, -6,-4,-5},
		{ 5,2,3,14, 8}
	};
	cout << "Исходный массив :" << endl;
	for (int i = 0; i < rows; i++)
	{

		for (int j = 0; j < columns; j++)
		{
			cout << numbers[i][j] << "\t";
		}
		cout << std::endl;
	}
	// Упорядочиваем строки по возрастанию количества одинаковых элементов
	for (int i = 0; i < rows - 1; ++i) {
		for (int j = 0; j < rows - i - 1; ++j) 
		{
			int freq1[columns] = { 0 };
			int freq2[columns] = { 0 };
			int maxCount1 = 0, maxCount2 = 0;

			for (int k = 0; k < columns; ++k) {
				int count1 = 0, count2 = 0;
				for (int l = 0; l < columns; ++l) {
					if (numbers[j][k] == numbers[j][l]) count1++;
					if (numbers[j + 1][k] == numbers[j + 1][l]) count2++;
				}
				if (count1 > maxCount1) maxCount1 = count1;
				if (count2 > maxCount2) maxCount2 = count2;
			}
			if (maxCount1 > maxCount2) {
				for (int k = 0; k < columns; ++k) {
					int temp = numbers[j][k];
					numbers[j][k] = numbers[j + 1][k];
					numbers[j + 1][k] = temp;
				}
			}
		}
	}
	// Вывод отсортированной матрицы
	cout << "Отсортированный двумерный массив по повторяющимся элементам в строках(по возрастанию):  " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << numbers[i][j] << "\t";
		}
		cout << endl;
	}
//	cout << "Первый столбец,без отрицательных элементов:  " << endl;
	int indexcolum = -1;
	for (int j = 0; j < columns; j++) {
		bool allNonNegative = false;
		for (int i = 0; i < rows; i++) {
			if (numbers[i][j] < 0) {
				allNonNegative = true;
				break;
			}
		}
		if (!allNonNegative) {
			indexcolum = j;
			break;
		}
	}
	// Вывод результата
	if (indexcolum != -1) {
		cout << "Номер первого столбца, не содержащего ни одного отрицательного элемента: " << indexcolum << endl;
	}
	else {
		cout << "Нет столбцов, не содержащих отрицательных элементов." << endl;
	}
}

