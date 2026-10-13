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

    Matrix a(3, 4);
    a.fillRandom();
    std::cout << "Matrix a:\n";
    a.print();

    Matrix b = a;
    b.set(0, 0, 999);
    std::cout << "\nAfter b.set(0, 0, 999):\n";
    std::cout << "Matrix a:\n";
    a.print();
    std::cout << "Matrix b:\n";
    b.print();

    Matrix c(2, 2);
    c.fillRandom();
    c = a;
    std::cout << "\nMatrix c after c = a:\n";
    c.print();

    Matrix d, e;
    d = e = a;
    std::cout << "\nMatrix d:\n";
    d.print();
    std::cout << "Matrix e:\n";
    e.print();

    a = a;
    std::cout << "\nMatrix a after a = a:\n";
    a.print();
    std::cout << "(should be unchanged)\n";

    return 0;
}