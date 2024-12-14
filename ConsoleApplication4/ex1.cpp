#include <iostream>
#include <cmath> // Для функции fabs
using namespace std;

class MyClass{
private:
    double res(double x1) {
        return x1 * x1 - 4;  // Например, f(x) = x^2 - 4
    }
public:
    double bisection(double a1, double b1, double e1) {
        double c1;

        if (res(a1) * res(b1) >= 0) {
            cout << "Функция должна иметь разные знаки на концах интервала!" << endl;
            return NAN; // Возвращаем "не число" в случае ошибки
        }

        while ((b1 - a1) >= e1) {
            c1 = (a1 + b1) / 2; // Находим середину интервала

            // Проверяем, является ли c корнем
            if (res(c1) == 0.0) {
                break; // Если мы нашли корень, выходим из цикла
            }

            // Определяем, в каком подинтервале будем продолжать поиск
            if (res(c1) * res(a1) < 0) {
                b1 = c1; // Корень находится между a и c
            }
            else {
                a1 = c1; // Корень находится между c и b
            }
        }

        return (a1 + b1) / 2; // Возвращаем найденный корень
    }
};



