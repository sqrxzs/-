#include <iostream>
#include <cmath>
#include "ex1.cpp"
#include "ex2.cpp"
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    cout << "Задание 1" << endl;
    double a1, b1, e1;

    cout << "Введите число a: ";
    cin >> a1;

    cout << "Введите число b: ";
    cin >> b1;

    cout << "Введите точность e: ";
    cin >> e1;
    MyClass abc;
    double root1 = abc.bisection(a1, b1, e1); // Вызываем метод половинного деления

    if (!isnan(root1)) { // Проверяем, был ли найден корень
        cout << "Найденный корень: " << root1 << endl;
    }
    
    
    cout << "Задание 2" << endl;
    double initial_guess, tolerance;

    // Ввод данных от пользователя
    cout << "Введите начальное значение (x0): ";
    cin >> initial_guess;

    cout << "Введите точность (e): ";
    cin >> tolerance;

    MyClass1 abc2;
    double root = abc2.simple_iterative_method(initial_guess, tolerance);

    // Вывод результата
    cout << "Найденный корень: " << root << endl;
    
}