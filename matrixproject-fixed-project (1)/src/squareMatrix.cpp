#include "squareMatrix.h"
#include <stdexcept>

SquareMatrix::SquareMatrix(int size) : Matrix(size, size) {}

SquareMatrix::SquareMatrix(const SquareMatrix& other) : Matrix(other) {}

SquareMatrix::SquareMatrix(const Matrix& m) : Matrix(m) {
    if (rows != cols) {
        throw std::invalid_argument("Matrix must be square to convert to SquareMatrix.");
    }
}

int SquareMatrix::determinant() const {
    if (rows != 2) {
        throw std::runtime_error("Determinant calculation is only implemented for 2x2 matrices currently.");
    }
    return data[0][0] * data[1][1] - data[0][1] * data[1][0];
}

bool SquareMatrix::isSymmetric() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (data[i][j] != data[j][i]) {
                return false;
            }
        }
    }
    return true;
}

SquareMatrix SquareMatrix::power(int exponent) const {
    if (exponent < 0) {
        throw std::runtime_error("Negative exponents are not supported currently.");
    }
    if (exponent == 0) {
        SquareMatrix result(rows);
        for (int i = 0; i < rows; ++i) {
            result.data[i][i] = 1;
        }
        return result;
    }
    SquareMatrix result = *this;
    for (int i = 1; i < exponent; ++i) {
        result = SquareMatrix(result * (*this));
    }
    return result;
}    