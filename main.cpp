#include "Matrix.h"

#include <iostream>
#include <ctime>
#include <stdexcept>
#include <clocale>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Matrix m1;
    Matrix m2(3);
    Matrix m3(3, 4);
    Matrix m4(2, 3);

    std::cout << "=== m2 (единичная 3x3) ===\n";
    m2.print();

    std::cout << "\n=== m3 (3x4 нули) ===\n";
    m3.print();

    std::cout << "\n=== m4 (2x3 нули) ===\n";
    m4.print();

    for (int i = 0; i < m2.getRows(); ++i) {
        for (int j = 0; j < m2.getCols(); ++j) {
            m2.set(i, j, i * j);
        }
    }
    std::cout << "\n=== m2 после i*j ===\n";
    m2.print();

    m3.fillRandom();
    std::cout << "\n=== m3 после fillRandom ===\n";
    m3.print();

    std::cout << "\n=== Введите 6 чисел для m4 (2x3) ===\n";
    m4.inputFromKeyboard();
    std::cout << "=== m4 после ввода ===\n";
    m4.print();

    std::cout << "\n=== Сумма элементов m3 = " << m3.sum() << " ===\n";

    std::cout << "\n=== Демонстрация исключений ===\n";
    try {
        Matrix bad(-1, 5);
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught: " << e.what() << '\n';
    }

    try {
        m3.get(100, 100);
    } catch (const std::out_of_range& e) {
        std::cout << "Caught: " << e.what() << '\n';
    }

    return 0;
}