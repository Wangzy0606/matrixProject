#include "squareMatrix.h"
#include <stdexcept>

/**
 * 带方阵大小参数的构造函数
 * @param size 方阵的大小（行数和列数）
 */
SquareMatrix::SquareMatrix(int size) : Matrix(size, size) {}

/**
 * 拷贝构造函数
 * @param other 要拷贝的方阵
 */
SquareMatrix::SquareMatrix(const SquareMatrix& other) : Matrix(other) {}

/**
 * 从普通矩阵转换为方阵的构造函数
 * @param m 普通矩阵
 */
SquareMatrix::SquareMatrix(const Matrix& m) : Matrix(m) {
    if (rows != cols) {
        throw std::invalid_argument("Matrix must be square to convert to SquareMatrix.");
    }
}

/**
 * 计算方阵的行列式（仅支持 2x2 方阵）
 * @return 方阵的行列式值
 */
int SquareMatrix::determinant() const {
    if (rows != 2) {
        throw std::runtime_error("Determinant calculation is only implemented for 2x2 matrices currently.");
    }
    return data[0][0] * data[1][1] - data[0][1] * data[1][0];
}

/**
 * 判断方阵是否对称
 * @return 如果方阵对称返回 true，否则返回 false
 */
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

/**
 * 计算方阵的幂
 * @param exponent 幂次
 * @return 幂次方后的方阵
 */
SquareMatrix SquareMatrix::power(int exponent) const {
    if (exponent < 0) {
        throw std::runtime_error("Negative exponents are not supported currently.");
    }
    if (exponent == 0) {
        SquareMatrix result(rows);
        for (int i = 0; i < rows; ++i) {
            result.data[i][i] = 1;  // 创建单位矩阵
        }
        return result;
    }
    SquareMatrix result = *this;
    for (int i = 1; i < exponent; ++i) {
        result = SquareMatrix(result * (*this));  // 多次相乘得到幂次方结果
    }
    return result;
}    