#include <iostream>
#include <math.h>
//Лабораторная работа 1
int main()
{
    setlocale(LC_ALL, "Russian");

    float x;

    std::cout << "Введите значение X:\n";

    std::cin >> x;

    float z1 = (pow(x, 2) + 2 * x - 3 + (x + 1) * sqrt(pow(x, 2) - 9)) / (pow(x, 2) - 2 * x - 3 + (x - 1) * sqrt(pow(x, 2) - 9));

    float z2 = sqrt((x + 3) / (x - 3));

    std::cout << "z1 = " << z1 << "\nz2 = " << z2;

    return 0;
}