// laba1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
//Лаборатораня работа 5
int main()
{
    const int rows = 3, columns = 5;
    int numbers[rows][columns]
    {
        {-4,1, 2,-4,0},     
        { 4,2, 6,-4,5},    
        { 7,27,-4,14, 8}      
    };
    cout << "e";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << numbers[i][j] << "\t";
        }
        std::cout << std::endl;
    }


}

