#ifndef QUADRATIC_SOLVER_H
#define QUADRATIC_SOLVER_H
#include <iostream>
#include <string>

struct ComplexNumber {
    double real, imag;

    ComplexNumber(double r = 0, double i = 0) : real(r), imag(i) {}

    void print() const {
        if (imag >= 0)
            std::cout << real << " + " << imag << "i" << std::endl;
        else
            std::cout << real << " - " << -imag << "i" << std::endl;
    }

    // Арифметические операции
    ComplexNumber operator+(const ComplexNumber &other) const {
        return {real + other.real, imag + other.imag};
    }

    ComplexNumber operator-(const ComplexNumber &other) const {
        return {real - other.real, imag - other.imag};
    }

    ComplexNumber operator*(const ComplexNumber &other) const {
        return {real * other.real - imag * other.imag, real * other.imag + imag * other.real};
    }
};

struct Solution {
    double x1, x2;
    ComplexNumber complexRoot1, complexRoot2;
    enum class SolutionType { NoSolution, OneSolution, TwoSolutions, ComplexSolutions } type;
};

using SolutionType = Solution::SolutionType;

class QuadraticSolver {
private:
    double a, b, c;

public:
    QuadraticSolver(double a, double b, double c);
    Solution solve() const;
};

void solveQuadraticEquation();

#endif
