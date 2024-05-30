#include <iostream>
using namespace std;
//Лаборатораня работа 5
int main()
{
    setlocale(LC_ALL, "Russian");
    const int rows = 3, columns = 5;
    int numbers[rows][columns]
    {
        {7,1, 2,7,0},     
        { 4,4, 6,4,5},    
        { 5,2,-4,14, 8}      
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
    //cout << "Упорядоченный по возрастанию строк массив :" << endl;
     //Находим суммы элементов в каждой строке
    double sum[rows];
    for (int i = 0; i < rows; i++)
    {
        sum[i] = 0;
        for (int j = 0; j < columns; j++)
        {
            sum[i] += fabs(numbers[i][j]);
        }
    }
    //Находим первый столбец с отрицательным элементом
    int first_neg = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (numbers[i][j] < 0)
            {
                first_neg = j;
                goto otmetka;
            }
        }
    }
otmetka:
   
    //Сортируем матрицу 
    double k;
    int a[rows];
    for (int i = 0; i < rows; ++i)
    {
        /*if (sum[i] < sum[i + 1])
        {*/
            for (int j = 0; j < columns; ++j)
            {
                a[i] = numbers[i][j];
                numbers[i][j] = numbers[i + 1][j];
                numbers[i + 1][j] = a[i];
                k = sum[i];
                sum[i] = sum[i + 1];
                sum[i + 1] = k;
                
            }
       // }
    }
    //cout << std::endl;
    //for (int i = 0; i < rows; i++)
    //{
    //    for (int j = 0; j < columns; j++)
    //    {
    //        cout << numbers[i][j] << "\t";
    //    }
    //    cout << std::endl;
    //}



}

