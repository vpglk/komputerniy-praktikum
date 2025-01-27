#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <vector>
#include <memory>
using namespace std;

// ========== 1. Порождающий паттерн: Фабричный метод ==========
class MatrixFactory {
public:
    static vector<vector<int>> createMatrix(int rows, int cols);
};

// ========== 2. Структурный паттерн: Адаптер ==========
class MatrixAdapter {
private:
    vector<vector<int>> matrix;

public:
    MatrixAdapter(const vector<vector<int>> &m);
    int getElement(int row, int col) const;
    void setElement(int row, int col, int value);
    void print() const;
    const vector<vector<int>> &getMatrix() const;
};

// ========== 3. Поведенческий паттерн: Стратегия ==========
class MatrixAdditionStrategy {
public:
    virtual void add(const vector<vector<int>> &matrixA, const vector<vector<int>> &matrixB, vector<vector<int>> &result) const = 0;
    virtual ~MatrixAdditionStrategy() = default;
};

class SimpleAdditionStrategy : public MatrixAdditionStrategy {
public:
    void add(const vector<vector<int>> &matrixA, const vector<vector<int>> &matrixB, vector<vector<int>> &result) const override;
};

class MatrixContext {
private:
    unique_ptr<MatrixAdditionStrategy> strategy;

public:
    void setStrategy(unique_ptr<MatrixAdditionStrategy> newStrategy);
    void executeStrategy(const vector<vector<int>> &matrixA, const vector<vector<int>> &matrixB, vector<vector<int>> &result) const;
};

#endif // MATRIX_OPERATIONS_H
