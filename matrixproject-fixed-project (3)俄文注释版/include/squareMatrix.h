#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "matrix.h"

/**
 * Класс квадратной матрицы, наследующийся от класса Matrix
 */
class SquareMatrix : public Matrix {
public:
    SquareMatrix(int size);                // Конструктор с параметром размера квадратной матрицы
    SquareMatrix(const SquareMatrix& other);  // Конструктор копирования
    int determinant() const;               // Вычисление определителя квадратной матрицы
    bool isSymmetric() const;              // Проверка, является ли матрица симметричной
    SquareMatrix power(int exponent) const;  // Возведение квадратной матрицы в степень
    SquareMatrix(const Matrix& m);         // Конструктор преобразования из обычной матрицы в квадратную
};

#endif    