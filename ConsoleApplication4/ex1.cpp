#include <iostream>
#include <cmath> // ��� ������� fabs
using namespace std;

class MyClass{
private:
    double res(double x1) {
        return x1 * x1 - 4;  // ��������, f(x) = x^2 - 4
    }
public:
    double bisection(double a1, double b1, double e1) {
        double c1;

        if (res(a1) * res(b1) >= 0) {
            cout << "������� ������ ����� ������ ����� �� ������ ���������!" << endl;
            return NAN; // ���������� "�� �����" � ������ ������
        }

        while ((b1 - a1) >= e1) {
            c1 = (a1 + b1) / 2; // ������� �������� ���������

            // ���������, �������� �� c ������
            if (res(c1) == 0.0) {
                break; // ���� �� ����� ������, ������� �� �����
            }

            // ����������, � ����� ������������ ����� ���������� �����
            if (res(c1) * res(a1) < 0) {
                b1 = c1; // ������ ��������� ����� a � c
            }
            else {
                a1 = c1; // ������ ��������� ����� c � b
            }
        }

        return (a1 + b1) / 2; // ���������� ��������� ������
    }
};



