#include <iostream>
#include "quadratic_solver.hpp"
#include "complex_arithmetic.hpp"
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int choice;
    cout << "Выберите операцию: " << endl;
    cout << "1. Решение квадратного уравнения" << endl;
    cout << "2. Арифметика с комплексными числами" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            solveQuadraticEquation();
        break;
        case 2:
            performComplexArithmetic();
        break;
        default:
            cout << "Некорректный выбор." << endl;
        break;
    }

    return 0;
}
