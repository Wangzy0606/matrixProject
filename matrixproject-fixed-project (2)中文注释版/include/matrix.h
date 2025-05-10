#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

/**
 * 矩阵类，用于表示和操作矩阵
 */
class Matrix {
protected:
    std::vector<std::vector<int>> data;  // 存储矩阵元素的二维向量
    int rows, cols;                      // 矩阵的行数和列数

public:
    Matrix();                           // 默认构造函数
    Matrix(int rows, int cols);         // 带行列参数的构造函数
    Matrix(const Matrix& other);        // 拷贝构造函数

    ~Matrix() = default;                // 默认析构函数

    Matrix operator+(const Matrix& other) const;  // 矩阵加法运算符重载
    Matrix operator-(const Matrix& other) const;  // 矩阵减法运算符重载
    Matrix operator*(int scalar) const;           // 矩阵与常数相乘运算符重载
    Matrix operator*(const Matrix& other) const;  // 矩阵乘法运算符重载
    Matrix &operator=(const Matrix& other);       // 赋值运算符重载
    bool operator==(const Matrix& other) const;   // 矩阵相等比较运算符重载

    Matrix multiply(const Matrix& other) const;   // 矩阵乘法函数

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);  // 输出运算符重载
    friend std::istream& operator>>(std::istream& is, Matrix& matrix);        // 输入运算符重载

    int getMaxValue() const;  // 获取矩阵中的最大值
};

#endif    