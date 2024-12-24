#include <iostream>

using namespace std;

void calculateCoefficients(double x[], double y[], double a[], double b[], double c[], double d[], int n) {
	double h[10], alpha[10], l[10], mu[10], z[10];
	for (int i = 0; i < n - 1; i++) {
		h[i] = x[i + 1] - x[i];
	}
	for (int i = 1; i < n - 1; i++) {
		alpha[i] = (3.0 / h[i]) * (y[i + 1] - y[i]) - (3.0 / h[i - 1]) * (y[i] - y[i - 1]);

	}
	l[0] = 1;
	mu[0] = 0;
	z[0] = 0;
	for (int i = 1; i < n - 1; i++) {
		l[i] = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
		mu[i] = h[i] / l[i];
		z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
	}
	l[n - 1] = 1;
	z[n - 1] = 0;
	c[n - 1] = 0;
	for (int j = n - 2; j >= 0; j--) {
		c[j] = z[j] - mu[j] * c[j + 1];
		b[j] = (y[j + 1] - y[j]) / h[j] - h[j] * (c[j + 1] + 2 * c[j]) / 3;
		d[j] = (c[j + 1] - c[j]) / (3 * h[j]);
		a[j] = y[j];
	}
}

double spline(double x[], double y[], double a[], double b[], double c[], double d[], int n, double val) {
	int i;
	for (i = 0; i < n - 1; i++) {
		if (val >= x[i] && val <= x[i + 1]) {
			break;
		}
	}
	double diff = val - x[i];
	return a[i] + b[i] * diff + c[i] * diff * diff + d[i] * diff * diff * diff;
}

int main() {
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите кол-во точек: ";
	cin >> n;

	double x[10], y[10], a[10], b[10], c[10], d[10];
	cout << "Введите координаты х и у: ";
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	calculateCoefficients(x, y, a, b, c, d, n);

	double val;
	cout << "Введите значение для инторполяции: ";
	cin >> val;

	double result = spline(x, y, a, b, c, d, n, val);
	cout << "Результат интерполяции: " << result << endl;

	return 0;
}