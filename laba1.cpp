#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
//Лабораторная работа 3.2
int main()
{
    setlocale(LC_ALL, "Russian");
    const double n = 1;
    double x_begin, x_end, dx, x, epsilon;
    cout << "\n\tВведите x_начальное: "; cin >> x_begin;
    cout << "\n\tВведите x_конечное: "; cin >> x_end;
    cout << "\n\tВведите dx: "; cin >> dx;
    cout << "\n\tВведите точность: "; cin >> epsilon;
    cout << endl << endl;
    cout << "\n\t————————————————————————————————————";
    int index = 0;
    cout << "\n\t" << "  Индекс    " << "  | X  " << "  | Y";
    for (x = x_begin; x <= x_end; x += dx, ++index)
    {
        double s = 0, y = 0;
        do
        {
            s = pow((x - 1), (2 * index + 1)) / ((2 * index + 1) * pow((x + 1), (2 * index + 1)));
            y += 2.0 * s;
            index++;
        } while (abs(s) < epsilon && index < 200);
        cout << "\n\t" << setw(5) << index
            << " | " << setw(7) << x
            << " | " << setw(5) << y << " |"
            << "\n\t————————————————————————————————————";
    }
    cout << endl << endl;
    return 0;
}