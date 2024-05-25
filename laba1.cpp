// laba1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
//Лаборатораня работа 5
int main()
{
    setlocale(LC_ALL, "Russian");
    const int rows = 3, columns = 5;
    int numbers[rows][columns]
    {
        {-4,1, 2,-4,0},     
        { 4,2, 6,-4,5},    
        { 8,14,-4,14, 8}      
    };
    cout << "Исходный массив :"<<endl;
    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < columns; j++)
        {
            cout << numbers[i][j] << "\t";
        }
        cout << std::endl;
    }
    cout << "Упорядоченный по возрастанию строк массив :" << endl;
    int rv = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (numbers[i][j] == numbers[i][j++])
            {
                rv++;

            }
        }
    }
    cout << "Кол-во повторений в строках массива:" << rv;

}

