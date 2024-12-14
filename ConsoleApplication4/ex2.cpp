#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

class MyClass1{
private:
    double func_g(double input) {
        return sqrt(4 + input); // Преобразование уравнения x^2 - x - 4 = 0 в x = sqrt(4 + input)
    }
public:
    double simple_iterative_method(double initial_value, double precision) {
        assert(precision > 0); // Проверка на положительность precision
        double next_value;

        do {
            next_value = func_g(initial_value); // Вычисление нового значения
            // Проверка на сходимость
            if (fabs(next_value - initial_value) < precision) {
                break; // Выход из цикла, если разница меньше precision
            }
            initial_value = next_value; // Обновление начального значения
        } while (true);

        return next_value; // Возврат найденного корня
    }
};



