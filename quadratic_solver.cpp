#include "quadratic_solver.hpp"
#include <cmath>
#include <iostream>

using namespace std;

QuadraticSolver::QuadraticSolver(double a, double b, double c) : a(a), b(b), c(c) {}

Solution QuadraticSolver::solve() const {
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double sqrtDiscriminant = std::sqrt(discriminant);
        double x1 = (-b + sqrtDiscriminant) / (2 * a);
        double x2 = (-b - sqrtDiscriminant) / (2 * a);
        return {x1, x2, {}, {}, SolutionType::TwoSolutions};
    } else if (discriminant == 0) {
        double x = -b / (2 * a);
        return {x, x, {}, {}, SolutionType::OneSolution};
    } else {
        double realPart = -b / (2 * a);
        double imaginaryPart = std::sqrt(-discriminant) / (2 * a);
        ComplexNumber root1(realPart, imaginaryPart);
        ComplexNumber root2(realPart, -imaginaryPart);
        return {0, 0, root1, root2, SolutionType::ComplexSolutions};
    }
}

void solveQuadraticEquation() {
    double a, b, c;

    cout << "Введите коэффициенты квадратного уравнения (a, b, c): ";
    cin >> a >> b >> c;

    QuadraticSolver solver(a, b, c);
    auto result = solver.solve();

    switch (result.type) {
        case SolutionType::NoSolution:
            cout << "Уравнение не имеет действительных корней." << endl;
        break;
        case SolutionType::OneSolution:
            cout << "Уравнение имеет один корень: x = " << result.x1 << endl;
        break;
        case SolutionType::TwoSolutions:
            cout << "Уравнение имеет два корня: x1 = " << result.x1 << ", x2 = " << result.x2 << endl;
        break;
        case SolutionType::ComplexSolutions:
            cout << "Уравнение имеет два комплексных корня: " << endl;
        cout << "x1 = "; result.complexRoot1.print();
        cout << "x2 = "; result.complexRoot2.print();
        break;
    }
}
