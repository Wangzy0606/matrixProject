#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

class Matrix {
protected:
    std::vector<std::vector<int>> data;
    int rows, cols;

public:
    Matrix();
    Matrix(int rows, int cols);
    Matrix(const Matrix& other);

    ~Matrix() = default;

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(int scalar) const;
    Matrix operator*(const Matrix& other) const;
    Matrix &operator=(const Matrix& other);
    bool operator==(const Matrix& other) const;

    Matrix multiply(const Matrix& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
    friend std::istream& operator>>(std::istream& is, Matrix& matrix);

    int getMaxValue() const;
};

#endif    