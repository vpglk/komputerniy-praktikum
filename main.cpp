#include <iostream>
#include "matrix_operations.hpp"

using namespace std;

int main() {
    // ФАБРИКА
    auto matrixA = MatrixFactory::createMatrix(3, 3);
    auto matrixB = MatrixFactory::createMatrix(3, 3);
    auto result = MatrixFactory::createMatrix(3, 3);

    matrixA[0][0] = 1; matrixA[0][1] = 2;
    matrixA[1][0] = 3; matrixA[1][1] = 4;

    matrixB[0][0] = 5; matrixB[0][1] = 6;
    matrixB[1][0] = 7; matrixB[1][1] = 8;

    // СТРАТЕГИЯ
    MatrixContext context;
    context.setStrategy(make_unique<SimpleAdditionStrategy>());
    context.executeStrategy(matrixA, matrixB, result);

    for (const auto &row : result) {
        for (const auto &element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}
