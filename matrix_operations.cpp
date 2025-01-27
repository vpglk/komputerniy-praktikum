#include "matrix_operations.hpp"
#include <iostream>

using namespace std;

// ФАБРИКА
vector<vector<int>> MatrixFactory::createMatrix(int rows, int cols) {
    return vector<vector<int>>(rows, vector<int>(cols, 0));
}

// АДАПТЕР
MatrixAdapter::MatrixAdapter(const vector<vector<int>> &m) : matrix(m) {}

int MatrixAdapter::getElement(int row, int col) const {
    return matrix[row][col];
}

void MatrixAdapter::setElement(int row, int col, int value) {
    matrix[row][col] = value;
}

void MatrixAdapter::print() const {
    for (const auto &row : matrix) {
        for (const auto &element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

const vector<vector<int>> &MatrixAdapter::getMatrix() const {
    return matrix;
}

// СТРАТЕГИЯ
void SimpleAdditionStrategy::add(const vector<vector<int>> &matrixA, const vector<vector<int>> &matrixB, vector<vector<int>> &result) const {
    int rows = matrixA.size();
    int cols = matrixA[0].size();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// кетчуп
void MatrixContext::setStrategy(unique_ptr<MatrixAdditionStrategy> newStrategy) {
    strategy = move(newStrategy);
}

void MatrixContext::executeStrategy(const vector<vector<int>> &matrixA, const vector<vector<int>> &matrixB, vector<vector<int>> &result) const {
    if (strategy) {
        strategy->add(matrixA, matrixB, result);
    }
}
