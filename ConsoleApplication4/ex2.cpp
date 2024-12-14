#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

class MyClass1{
private:
    double func_g(double input) {
        return sqrt(4 + input); // �������������� ��������� x^2 - x - 4 = 0 � x = sqrt(4 + input)
    }
public:
    double simple_iterative_method(double initial_value, double precision) {
        assert(precision > 0); // �������� �� ��������������� precision
        double next_value;

        do {
            next_value = func_g(initial_value); // ���������� ������ ��������
            // �������� �� ����������
            if (fabs(next_value - initial_value) < precision) {
                break; // ����� �� �����, ���� ������� ������ precision
            }
            initial_value = next_value; // ���������� ���������� ��������
        } while (true);

        return next_value; // ������� ���������� �����
    }
};



