#include <algorithm>
#include <iostream>
#include <vector>
struct Point {
	int x, y;
};
// Вспомогательная функция для вычисления площади треугольника
double area(const Point& a, const Point& b, const Point& c) {
	return abs(a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0;
}
// Вспомогательная функция для проверки, лежит ли точка внутри треугольника
bool isInside(const Point& p, const Point& a, const Point& b, const Point& c) {
	double A = area(a, b, c);
	double A1 = area(p, b, c);
	double A2 = area(a, p, c);
	double A3 = area(a, b, p);
	return (A == A1 + A2 + A3);
}
// Основная функция для поиска трех треугольников
bool findNestedTriangles(const std::vector<Point>& points, std::vector<Point>& triangle1, std::vector<Point>& triangle2, std::vector<Point>& triangle3) {
	int n = points.size();
	if (n < 9) return false; // Недостаточно точек для трех треугольников
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				for (int l = 0; l < n; ++l) {
					if (l == i || l == j || l == k) continue;
					for (int m = l + 1; m < n; ++m) {
						if (m == i || m == j || m == k) continue;
						for (int o = m + 1; o < n; ++o) {
							if (o == i || o == j || o == k) continue;
							if (isInside(points[l], points[i], points[j], points[k]) &&
								isInside(points[m], points[i], points[j], points[k]) &&
								isInside(points[o], points[i], points[j], points[k])) {
								for (int p = 0; p < n; ++p) {
									if (p == i || p == j || p == k || p == l || p == m || p == o) continue;
									for (int q = p + 1; q < n; ++q) {
										if (q == i || q == j || q == k || q == l || q == m || q == o) continue;
										for (int r = q + 1; r < n; ++r) {
											if (r == i || r == j || r == k || r == l || r == m || r == o) continue;
											if (isInside(points[p], points[l], points[m], points[o]) &&
												isInside(points[q], points[l], points[m], points[o]) &&
												isInside(points[r], points[l], points[m], points[o])) {
												triangle1 = { points[i], points[j], points[k] };
												triangle2 = { points[l], points[m], points[o] };
												triangle3 = { points[p], points[q], points[r] };
												return true;
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
	return false;
}
int main() {
	setlocale(LC_ALL, "Russian");
	std::vector<Point> points = { {0,0}, {1,1}, {2,2}, {3,3}, {4,4}, {5,5}, {6,6}, {7,7}, {8,8}, {9,9} };
	std::vector<Point> triangle1, triangle2, triangle3;

	if (findNestedTriangles(points, triangle1, triangle2, triangle3)) {
		std::cout << "Первый треугольник: ";
		for (const auto& p : triangle1) std::cout << "(" << p.x << "," << p.y << ") ";
		std::cout << "\nВторой треугольник: ";
		for (const auto& p : triangle2) std::cout << "(" << p.x << "," << p.y << ") ";
		std::cout << "\nТретий треугольник: ";
		for (const auto& p : triangle3) std::cout << "(" << p.x << "," << p.y << ") ";
		std::cout << "\n";
	}
	else {
		std::cout << "Не найдены треугольники.\n";
	}
	return 0;
}


