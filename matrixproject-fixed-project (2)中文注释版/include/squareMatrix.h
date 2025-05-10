#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "matrix.h"

/**
 * 方阵类，继承自 Matrix 类，用于表示和操作方阵
 */
class SquareMatrix : public Matrix {
public:
    SquareMatrix(int size);                // 带方阵大小参数的构造函数
    SquareMatrix(const SquareMatrix& other);  // 拷贝构造函数
    int determinant() const;               // 计算方阵的行列式
    bool isSymmetric() const;              // 判断方阵是否对称
    SquareMatrix power(int exponent) const;  // 计算方阵的幂
    SquareMatrix(const Matrix& m);         // 从普通矩阵转换为方阵的构造函数
};

#endif    