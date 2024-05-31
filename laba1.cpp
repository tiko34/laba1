#include <iostream>
#include <vector>
#include <algorithm>

int main()
{


    using namespace std;

    // Структура для представления точки на плоскости
    struct Point {
        int x, y;
    };

    // Функция для проверки, лежит ли точка c слева от прямой, проходящей через точки a и b
    bool isLeft(const Point & a, const Point & b, const Point & c) {
        return ((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x)) > 0;
    }

    // Функция для проверки, лежит ли точка p внутри треугольника abc
    bool isPointInsideTriangle(const Point & p, const Point & a, const Point & b, const Point & c) {
        // Точка должна лежать с одной стороны от каждой стороны треугольника
        return (isLeft(a, b, p) == isLeft(a, b, c)) &&
            (isLeft(b, c, p) == isLeft(b, c, a)) &&
            (isLeft(c, a, p) == isLeft(c, a, b));
    }

    int main() {
        // Ввод количества точек
        int n;
        cout << "Введите количество точек: ";
        cin >> n;

        // Ввод координат точек
        vector<Point> points(n);
        cout << "Введите координаты точек:\n";
        for (int i = 0; i < n; ++i) {
            cin >> points[i].x >> points[i].y;
        }

        // Поиск трех треугольников
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    // Первый треугольник
                    Point a = points[i], b = points[j], c = points[k];

                    // Поиск второго треугольника внутри первого
                    for (int l = 0; l < n; ++l) {
                        if (l != i && l != j && l != k) {
                            Point d = points[l];
                            if (isPointInsideTriangle(d, a, b, c)) {
                                for (int m = l + 1; m < n; ++m) {
                                    if (m != i && m != j && m != k) {
                                        Point e = points[m];
                                        if (isPointInsideTriangle(e, a, b, c) &&
                                            isPointInsideTriangle(e, d, b, c)) {
                                            for (int p = m + 1; p < n; ++p) {
                                                if (p != i && p != j && p != k) {
                                                    Point f = points[p];
                                                    if (isPointInsideTriangle(f, a, b, c) &&
                                                        isPointInsideTriangle(f, d, b, c) &&
                                                        isPointInsideTriangle(f, d, e, c)) {
                                                        // Найдены три треугольника
                                                        cout << "Треугольник 1: (" << a.x << ", " << a.y << "), (" << b.x << ", " << b.y << "), (" << c.x << ", " << c.y << ")\n";
                                                        cout << "Треугольник 2: (" << d.x << ", " << d.y << "), (" << b.x << ", " << b.y << "), (" << c.x << ", " << c.y << ")\n";
                                                        cout << "Треугольник 3: (" << d.x << ", " << d.y << "), (" << e.x << ", " << e.y << "), (" << f.x << ", " << f.y << ")\n";
                                                        return 0;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        // Треугольники не найдены
        cout << "Не найдено трех треугольников, удовлетворяющих условию.\n";

        return 0;
    }
}

