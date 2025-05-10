#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "Matrix.h"
#include "SquareMatrix.h"

/**
 * Вывод меню операций
 */
void printMenu() {
    std::cout << "\nMatrix Operations Menu:" << std::endl;
    std::cout << "1. Matrix A + Matrix B" << std::endl;
    std::cout << "2. Matrix A - Matrix B" << std::endl;
    std::cout << "3. Matrix A * Scalar" << std::endl;
    std::cout << "4. Matrix A * Matrix B" << std::endl;
    std::cout << "5. Check if Matrix A and Matrix C are equal" << std::endl;
    std::cout << "6. Find max value in Matrix A" << std::endl;
    std::cout << "7. Find max value in Matrix B" << std::endl;
    std::cout << "8. Print Square Matrix A" << std::endl;
    std::cout << "9. Square Matrix A + Square Matrix B" << std::endl;
    std::cout << "10. Square Matrix A - Square Matrix B" << std::endl;
    std::cout << "11. Square Matrix A * Scalar" << std::endl;
    std::cout << "12. Square Matrix A * Square Matrix B" << std::endl;
    std::cout << "13. Check if Square Matrix A and Square Matrix D are equal" << std::endl;
    std::cout << "14. Find max value in Square Matrix A" << std::endl;
    std::cout << "15. Calculate determinant of Square Matrix A" << std::endl;
    std::cout << "16. Check if Square Matrix A is symmetric" << std::endl;
    std::cout << "17. Calculate Square Matrix A to the power of 2" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

/**
 * Вывод матриц A и B
 * @param matrixA матрица A
 * @param matrixB матрица B
 */
void printMatrices(const Matrix& matrixA, const Matrix& matrixB) {
    std::cout << "Matrix A:" << std::endl;
    std::cout << matrixA;
    std::cout << "Matrix B:" << std::endl;
    std::cout << matrixB;
}

/**
 * Главная функция программы
 * @return код возврата программы
 */
int main() {
    // Инициализация генератора случайных чисел для создания разных последовательностей при каждом запуске
    srand(static_cast<unsigned int>(time(nullptr)));

    int rowsA, colsA, rowsB, colsB;
    std::cout << "Enter the number of rows and columns for Matrix A (separated by space): ";
    std::cin >> rowsA >> colsA;
    std::cout << "Enter the number of rows and columns for Matrix B (separated by space): ";
    std::cin >> rowsB >> colsB;

    // Создание матрицы A
    Matrix matrixA(rowsA, colsA);

    // Пауза на 3 секунды, чтобы пользователь мог ознакомиться с созданной матрицей
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // Создание матрицы B
    Matrix matrixB(rowsB, colsB);

    // Создание копии матрицы A для сравнения
    Matrix matrixC = matrixA;

    int choice;
    do {
        printMenu();  // Вывод меню операций
        std::cin >> choice;

        // Вывод матриц A и B для всех операций, кроме выхода
        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
            case 17:
                printMatrices(matrixA, matrixB);
                break;
            default:
                break;
        }

        // Выполнение выбранной операции
        switch (choice) {
            case 1:
                try {
                    Matrix addResult = matrixA + matrixB;
                    std::cout << "Matrix A + Matrix B:" << std::endl;
                    std::cout << addResult;
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Matrix addition error: " << e.what() << std::endl;
                }
                break;
            case 2:
                try {
                    Matrix subtractResult = matrixA - matrixB;
                    std::cout << "Matrix A - Matrix B:" << std::endl;
                    std::cout << subtractResult;
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Matrix subtraction error: " << e.what() << std::endl;
                }
                break;
            case 3: {
                int scalar;
                std::cout << "Enter a scalar value: ";
                std::cin >> scalar;
                Matrix scalarMultiplyResult = matrixA * scalar;
                std::cout << "Matrix A * " << scalar << ":" << std::endl;
                std::cout << scalarMultiplyResult;
                break;
            }
            case 4:
                try {
                    Matrix multiplyResult = matrixA * matrixB;
                    std::cout << "Matrix A * Matrix B:" << std::endl;
                    std::cout << multiplyResult;
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Matrix multiplication error: " << e.what() << std::endl;
                }
                break;
            case 5: {
                std::cout << "Matrix C:" << std::endl;
                std::cout << matrixC;
                bool areEqual = matrixA == matrixC;
                std::cout << "Are Matrix A and Matrix C equal? " << (areEqual ? "Yes" : "No") << std::endl;
                break;
            }
            case 6:
                std::cout << "Max value in Matrix A: " << matrixA.getMaxValue() << std::endl;
                break;
            case 7:
                std::cout << "Max value in Matrix B: " << matrixB.getMaxValue() << std::endl;
                break;
            case 8:
                if (rowsA == colsA) {
                    SquareMatrix squareMatrixA(matrixA);
                    std::cout << "Square Matrix A:" << std::endl;
                    std::cout << squareMatrixA;
                } else {
                    std::cerr << "Matrix A is not a square matrix." << std::endl;
                }
                break;
            case 9:
                if (rowsA == colsA && rowsB == colsB) {
                    try {
                        SquareMatrix squareMatrixA(matrixA);
                        SquareMatrix squareMatrixB(matrixB);
                        SquareMatrix squareAddResult = squareMatrixA + squareMatrixB;
                        std::cout << "Square Matrix A + Square Matrix B:" << std::endl;
                        std::cout << squareAddResult;
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Square matrix addition error: " << e.what() << std::endl;
                    }
                } else {
                    std::cerr << "Both matrices must be square." << std::endl;
                }
                break;
            case 10:
                if (rowsA == colsA && rowsB == colsB) {
                    try {
                        SquareMatrix squareMatrixA(matrixA);
                        SquareMatrix squareMatrixB(matrixB);
                        SquareMatrix squareSubtractResult = squareMatrixA - squareMatrixB;
                        std::cout << "Square Matrix A - Square Matrix B:" << std::endl;
                        std::cout << squareSubtractResult;
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Square matrix subtraction error: " << e.what() << std::endl;
                    }
                } else {
                    std::cerr << "Both matrices must be square." << std::endl;
                }
                break;
            case 11: {
                if (rowsA == colsA) {
                    SquareMatrix squareMatrixA(matrixA);
                    int scalar;
                    std::cout << "Enter a scalar value: ";
                    std::cin >> scalar;
                    SquareMatrix squareScalarMultiplyResult = squareMatrixA * scalar;
                    std::cout << "Square Matrix A * " << scalar << ":" << std::endl;
                    std::cout << squareScalarMultiplyResult;
                } else {
                    std::cerr << "Matrix A is not a square matrix." << std::endl;
                }
                break;
            }
            case 12:
                if (rowsA == colsA && rowsB == colsB) {
                    try {
                        SquareMatrix squareMatrixA(matrixA);
                        SquareMatrix squareMatrixB(matrixB);
                        SquareMatrix squareMultiplyResult = squareMatrixA * squareMatrixB;
                        std::cout << "Square Matrix A * Square Matrix B:" << std::endl;
                        std::cout << squareMultiplyResult;
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Square matrix multiplication error: " << e.what() << std::endl;
                    }
                } else {
                    std::cerr << "Both matrices must be square." << std::endl;
                }
                break;
            case 13:
                if (rowsA == colsA) {
                    SquareMatrix squareMatrixA(matrixA);
                    SquareMatrix squareMatrixD = squareMatrixA;
                    std::cout << "Square Matrix D:" << std::endl;
                    std::cout << squareMatrixD;
                    bool areSquareEqual = squareMatrixA == squareMatrixD;
                    std::cout << "Are Square Matrix A and Square Matrix D equal? " << (areSquareEqual ? "Yes" : "No") << std::endl;
                } else {
                    std::cerr << "Matrix A is not a square matrix." << std::endl;
                }
                break;
            case 14:
                if (rowsA == colsA) {
                    SquareMatrix squareMatrixA(matrixA);
                    std::cout << "Max value in Square Matrix A: " << squareMatrixA.getMaxValue() << std::endl;
                } else {
                    std::cerr << "Matrix A is not a square matrix." << std::endl;
                }
                break;
            case 15:
                if (rowsA == colsA) {
                    try {
                        SquareMatrix squareMatrixA(matrixA);
                        int determinant = squareMatrixA.determinant();
                        std::cout << "Determinant of Square Matrix A: " << determinant << std::endl;
                    } catch (const std::runtime_error& e) {
                        std::cerr << "Determinant calculation error: " << e.what() << std::endl;
                    }
                } else {
                    std::cerr << "Matrix A is not a square matrix." << std::endl;
                }
                break;
            case 16:
                if (rowsA == colsA) {
                    SquareMatrix squareMatrixA(matrixA);
                    bool isSymmetric = squareMatrixA.isSymmetric();
                    std::cout << "Is Square Matrix A symmetric? " << (isSymmetric ? "Yes" : "No") << std::endl;
                } else {
                    std::cerr << "Matrix A is not a square matrix." << std::endl;
                }
                break;
            case 17:
                if (rowsA == colsA) {
                    try {
                        SquareMatrix squareMatrixA(matrixA);
                        SquareMatrix powerResult = squareMatrixA.power(2);
                        std::cout << "Square Matrix A to the power of 2:" << std::endl;
                        std::cout << powerResult;
                    } catch (const std::runtime_error& e) {
                        std::cerr << "Power calculation error: " << e.what() << std::endl;
                    }
                } else {
                    std::cerr << "Matrix A is not a square matrix." << std::endl;
                }
                break;
            case 0:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cerr << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 0);  // Продолжать работу до тех пор, пока пользователь не выберет выход

    return 0;
}    