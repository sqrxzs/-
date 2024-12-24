#include <iostream>
using namespace std;

double function(double x) {
    return x * x;
}

double trapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (function(a) + function(b)) / 2.0;
    for (int i = 1; i < n; i++) {
        sum += function(a + i * b);
    }
    return sum * h;
}

int main()
{
    setlocale(LC_ALL, "rus");
    double a, b;
    int n;
    cout << "Введите границы интегрирования a и b: ";
    cin >> a >> b;
    cout << "Введите кол-во подынтервалов n: ";
    cin >> n;

    double result = trapezoidalRule(a, b, n);
    cout << "Результат интегрирования: " << result << endl;

    return 0;
}
