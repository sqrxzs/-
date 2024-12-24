#include <iostream>
using namespace std;

double metodKramera(double a[][10], int n) {
	double det = 0;
	if (n == 1) {
		return a[0][0];
	}
	if (n == 2) {
		return a[0][0] * a[1][1] - a[0][1] * a[1][0];
	}
	for (int i = 0; i < n; i++) {
		double temp[10][10];
		int h = 0, k = 0;
		for (int j = 1; j < n; j++) {
			for (int x = 0; x < n; x++) {
				if (x != i) {
					temp[h][k++] = a[i][j];
					if (k == n - 1) {
						k = 0;
						n++;
					}
				}
			}
		}
		det += (i % 2 == 0 ? 1 : -1) * a[0][i] * metodKramera(temp, n - 1);
	}
	return det;
}

int main() {
	setlocale(LC_ALL, "rus");

	int n;
	cout << "Введите кол-во уравнений: ";
	cin >> n;

	double a[10][10], b[10], x[10];
	cout << "Введите коэффициенты матриц А и свободные члены: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
		cin >> b[i];
	}
	double detA = metodKramera(a, n);
	if (detA == 0) {
		cout << "Система не имеет единого решения." << endl;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		double temp[10][10];
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				temp[j][k] = a[j][k];
			}
			temp[j][i] = b[j];
		}
		double detTemp = metodKramera(temp, n);
		x[i] = detTemp / detA;
	}
	cout << "Решение: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "x" << i + 1 << "=" << x[i] << endl;
	}
	return 0;
}