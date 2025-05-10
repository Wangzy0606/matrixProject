#include "matrix.h"

#include <cstdlib>

/**
 * Конструктор по умолчанию, создающий матрицу 2x2, заполненную нулями
 */
Matrix::Matrix() : rows(2), cols(2) {
    data.assign(rows, std::vector<int>(cols, 0));
}

/**
 * Конструктор с параметрами, создающий матрицу заданного размера и заполняющий ее случайными значениями
 * @param rows количество строк матрицы
 * @param cols количество столбцов матрицы
 */
Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    data.assign(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = rand() % 100;  // Инициализация случайными числами от 0 до 99
        }
    }
}

/**
 * Конструктор копирования
 * @param other матрица для копирования
 */
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(other.data) {}

/**
 * Перегрузка оператора сложения матриц
 * @param other другая матрица
 * @return результат сложения матриц
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
 * Перегрузка оператора вычитания матриц
 * @param other другая матрица
 * @return результат вычитания матриц
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
 * Перегрузка оператора умножения матрицы на скаляр
 * @param scalar скалярное значение
 * @return результат умножения матрицы на скаляр
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
 * Перегрузка оператора умножения матриц
 * @param other другая матрица
 * @return результат умножения матриц
 */
Matrix Matrix::operator*(const Matrix& other) const {
    return multiply(other);
}

/**
 * Функция умножения матриц
 * @param other другая матрица
 * @return результат умножения матриц
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
 * Перегрузка оператора присваивания
 * @param other другая матрица
 * @return ссылка на текущую матрицу после присваивания
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
 * Перегрузка оператора сравнения матриц
 * @param other другая матрица
 * @return true, если матрицы равны, иначе false
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
 * Перегрузка оператора вывода матрицы
 * @param os выходной поток
 * @param matrix матрица для вывода
 * @return ссылка на выходной поток
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
 * Перегрузка оператора ввода матрицы
 * @param is входной поток
 * @param matrix матрица для ввода
 * @return ссылка на входной поток
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
 * Получение максимального значения в матрице
 * @return максимальное значение в матрице
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