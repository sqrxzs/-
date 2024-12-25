#include <iostream>
using namespace std;

double function(double t, double y) {
    return y - t * t + 1; 
}

void rungeKutta(double t0, double y0, double h, double tEnd) {
    double t = t0;
    double y = y0;

    cout << "t: " << t << ", y: " << y << endl;

    while (t < tEnd) {
        double k1 = h * function(t, y);
        double k2 = h * function(t + h / 2, y + k1 / 2);
        double k3 = h * function(t + h / 2, y + k2 / 2);
        double k4 = h * function(t + h, y + k3);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        t += h;

        cout << "t: " << t << ", y: " << y << endl;
    }
}

int main() {
    double t0, y0, h, tEnd;
    cout << "Введите начальное значение t0: ";
    cin >> t0;
    cout << "Введите начальное значение y0: ";
    cin >> y0;
    cout << "Введите шаг h: ";
    cin >> h;
    cout << "Введите конечное значение tEnd: ";
    cin >> tEnd;

    rungeKutta(t0, y0, h, tEnd);

    return 0;
}
