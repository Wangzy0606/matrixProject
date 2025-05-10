#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

/**
 * Класс матрицы, представляющий и обрабатывающий матрицы
 */
class Matrix {
protected:
    std::vector<std::vector<int>> data;  // Двумерный вектор для хранения элементов матрицы
    int rows, cols;                      // Количество строк и столбцов матрицы

public:
    Matrix();                           // Конструктор по умолчанию
    Matrix(int rows, int cols);         // Конструктор с параметрами строк и столбцов
    Matrix(const Matrix& other);        // Конструктор копирования

    ~Matrix() = default;                // Деструктор по умолчанию

    Matrix operator+(const Matrix& other) const;  // Перегрузка оператора сложения матриц
    Matrix operator-(const Matrix& other) const;  // Перегрузка оператора вычитания матриц
    Matrix operator*(int scalar) const;           // Перегрузка оператора умножения матрицы на скаляр
    Matrix operator*(const Matrix& other) const;  // Перегрузка оператора умножения матриц
    Matrix &operator=(const Matrix& other);       // Перегрузка оператора присваивания
    bool operator==(const Matrix& other) const;   // Перегрузка оператора сравнения матриц

    Matrix multiply(const Matrix& other) const;   // Функция умножения матриц

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);  // Перегрузка оператора вывода
    friend std::istream& operator>>(std::istream& is, Matrix& matrix);        // Перегрузка оператора ввода

    int getMaxValue() const;  // Получение максимального значения в матрице
};

#endif    