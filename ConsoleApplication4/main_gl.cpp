#include <iostream>
#include <cmath>
#include "ex1.cpp"
#include "ex2.cpp"
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    cout << "������� 1" << endl;
    double a1, b1, e1;

    cout << "������� ����� a: ";
    cin >> a1;

    cout << "������� ����� b: ";
    cin >> b1;

    cout << "������� �������� e: ";
    cin >> e1;
    MyClass abc;
    double root1 = abc.bisection(a1, b1, e1); // �������� ����� ����������� �������

    if (!isnan(root1)) { // ���������, ��� �� ������ ������
        cout << "��������� ������: " << root1 << endl;
    }
    
    
    cout << "������� 2" << endl;
    double initial_guess, tolerance;

    // ���� ������ �� ������������
    cout << "������� ��������� �������� (x0): ";
    cin >> initial_guess;

    cout << "������� �������� (e): ";
    cin >> tolerance;

    MyClass1 abc2;
    double root = abc2.simple_iterative_method(initial_guess, tolerance);

    // ����� ����������
    cout << "��������� ������: " << root << endl;
    
}