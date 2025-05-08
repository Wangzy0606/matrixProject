#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "matrix.h"

class SquareMatrix : public Matrix {
public:
    SquareMatrix(int size);
    SquareMatrix(const SquareMatrix& other);
    int determinant() const;
    bool isSymmetric() const;
    SquareMatrix power(int exponent) const;
    SquareMatrix(const Matrix& m);
};

#endif    