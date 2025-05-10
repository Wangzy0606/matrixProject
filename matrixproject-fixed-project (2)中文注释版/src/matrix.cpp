#include "matrix.h"

#include <cstdlib>

/**
 * 默认构造函数，创建一个 2x2 的零矩阵
 */
Matrix::Matrix() : rows(2), cols(2) {
    data.assign(rows, std::vector<int>(cols, 0));
}

/**
 * 带行列参数的构造函数，创建一个指定大小的矩阵并初始化为随机值
 * @param rows 矩阵的行数
 * @param cols 矩阵的列数
 */
Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    data.assign(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = rand() % 100;  // 初始化为 0-99 之间的随机数
        }
    }
}

/**
 * 拷贝构造函数
 * @param other 要拷贝的矩阵
 */
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(other.data) {}

/**
 * 矩阵加法运算符重载
 * @param other 另一个矩阵
 * @return 相加后的结果矩阵
 */
Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrices must have the same dimensions for addition");
    }
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

/**
 * 矩阵减法运算符重载
 * @param other 另一个矩阵
 * @return 相减后的结果矩阵
 */
Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrices must have the same dimensions for subtraction");
    }
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

/**
 * 矩阵与常数相乘运算符重载
 * @param scalar 常数
 * @return 相乘后的结果矩阵
 */
Matrix Matrix::operator*(int scalar) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

/**
 * 矩阵乘法运算符重载
 * @param other 另一个矩阵
 * @return 相乘后的结果矩阵
 */
Matrix Matrix::operator*(const Matrix& other) const {
    return multiply(other);
}

/**
 * 矩阵乘法函数
 * @param other 另一个矩阵
 * @return 相乘后的结果矩阵
 */
Matrix Matrix::multiply(const Matrix& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Number of columns in the first matrix must be equal to the number of rows in the second matrix for multiplication");
    }
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

/**
 * 赋值运算符重载
 * @param other 另一个矩阵
 * @return 赋值后的矩阵引用
 */
Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) {
        return *this;
    }
    rows = other.rows;
    cols = other.cols;
    data = other.data;
    return *this;
}

/**
 * 矩阵相等比较运算符重载
 * @param other 另一个矩阵
 * @return 如果矩阵相等返回 true，否则返回 false
 */
bool Matrix::operator==(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        return false;
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (data[i][j] != other.data[i][j]) {
                return false;
            }
        }
    }
    return true;
}

/**
 * 输出运算符重载，用于打印矩阵
 * @param os 输出流
 * @param matrix 矩阵
 * @return 输出流引用
 */
std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.cols; ++j) {
            os << matrix.data[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

/**
 * 输入运算符重载，用于读取矩阵
 * @param is 输入流
 * @param matrix 矩阵
 * @return 输入流引用
 */
std::istream& operator>>(std::istream& is, Matrix& matrix) {
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.cols; ++j) {
            is >> matrix.data[i][j];
        }
    }
    return is;
}

/**
 * 获取矩阵中的最大值
 * @return 矩阵中的最大值
 */
int Matrix::getMaxValue() const {
    int maxVal = data[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (data[i][j] > maxVal) {
                maxVal = data[i][j];
            }
        }
    }
    return maxVal;
}    