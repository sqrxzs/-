#include <iostream>
using namespace std;

double metodLagrange(double x[], double y[], int n, double X) {
	double result = 0;
	for (int i = 0; i < n; i++) {
		double term = y[i];
		for (int j = 0; j < n; j++) {
			if (j != i) {
				term = term * (X - x[j]) / (x[i] - x[j]);
			}
		}
		result += term;
	}
	return result;
}

int main() {
	setlocale(LC_ALL, "rus");

	int n;
	cout << "Введите кол-во точек: ";
	cin >> n;

	double x[10], y[10];
	cout << "Введите координаты x и y: ";
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	double X;
	cout << "Введите значение Х для интерполяции: ";
	cin >> X;

	double result = metodLagrange(x,y,n,X);
	cout << "Результат интерполяции: " << result << endl;

	return 0;

}