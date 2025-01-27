#include "complex_arithmetic.hpp"
#include <iostream>

using namespace std;

void performComplexArithmetic() {
    ComplexNumber num1, num2;
    char operation;

    cout << "Введите первое комплексное число (в формате: a b, где a - реальная часть, b - мнимая часть): ";
    cin >> num1.real >> num1.imag;
    cout << "Введите второе комплексное число (в формате: a b): ";
    cin >> num2.real >> num2.imag;
    cout << "Введите операцию (+, -, *): ";
    cin >> operation;

    ComplexNumber result;

    switch (operation) {
        case '+':
            result = num1 + num2;
        break;
        case '-':
            result = num1 - num2;
        break;
        case '*':
            result = num1 * num2;
        break;
        default:
            cout << "Некорректная операция." << endl;
        return;
    }

    cout << "Результат: ";
    result.print();
}
