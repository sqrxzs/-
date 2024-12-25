#include <iostream>

using namespace std;

double function(double t, double y) {
	return y - t * t + 1;
}

void Euler(double t0, double y0, double h, double tend) {
	double t = t0;
	double y = y0;

	cout << "t: " << t << ", y: " << y << endl;

	while (t < tend) {
		double k1 = function(t, y);
		double k2 = function(t + h, y + h * k1);
		y += h * (k1 + k2) / 2;
		t += h;

		cout << "t: " << t << ", y: " << y << endl;
	}
}

int main() {
	double t0, y0, h, tend;
	cout << "Enter the initial value t0: ";
	cin >> t0;

	cout << "Enter the initial value y0: ";
	cin >> y0;

	cout << "Enter the step h: ";
	cin >> h;

	cout << "Enter the initial value tend: ";
	cin >> tend;

	Euler(t0, y0, h, tend);

	return 0;
}