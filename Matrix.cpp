#include "Matrix.h"

#include <iostream>
#include <cstdlib>

Matrix::Matrix() : data_(nullptr), rows_(0), cols_(0) {}

Matrix::Matrix(int size) : data_(nullptr), rows_(0), cols_(0) {
    if (size < 0) {
        throw std::invalid_argument("Размерность не может быть отрицательной");
    }
    if (size == 0) return;

    allocate(size, size);
    for (int i = 0; i < rows_; ++i)
        for (int j = 0; j < cols_; ++j)
            data_[i][j] = 0;
    for (int i = 0; i < rows_; ++i)
        data_[i][i] = 1;
}

Matrix::Matrix(int rows, int cols) : data_(nullptr), rows_(0), cols_(0) {
    if (rows < 0 || cols < 0) {
        throw std::invalid_argument("Размерность не может быть отрицательной");
    }
    if (rows == 0 || cols == 0) return;

    allocate(rows, cols);
    for (int i = 0; i < rows_; ++i)
        for (int j = 0; j < cols_; ++j)
            data_[i][j] = 0;
}

Matrix::Matrix(const Matrix& other) : data_(nullptr), rows_(0), cols_(0) {
    copyFrom(other);
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;
    freeMemory();
    copyFrom(other);
    return *this;
}

Matrix::~Matrix() {
    freeMemory();
}

int Matrix::get(int i, int j) const {
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_)
        throw std::out_of_range("Индекс вне диапазона");
    return data_[i][j];
}

void Matrix::set(int i, int j, int value) {
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_)
        throw std::out_of_range("Индекс вне диапазона");
    data_[i][j] = value;
}

void Matrix::inputFromKeyboard() {
    for (int i = 0; i < rows_; ++i)
        for (int j = 0; j < cols_; ++j)
            std::cin >> data_[i][j];
}

void Matrix::fillRandom() {
    for (int i = 0; i < rows_; ++i)
        for (int j = 0; j < cols_; ++j)
            data_[i][j] = std::rand() % 100;
}

void Matrix::print() const {
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j)
            std::cout << data_[i][j] << ' ';
        std::cout << '\n';
    }
}

int Matrix::sum() const {
    int s = 0;
    for (int i = 0; i < rows_; ++i)
        for (int j = 0; j < cols_; ++j)
            s += data_[i][j];
    return s;
}

int Matrix::getRows() const { return rows_; }
int Matrix::getCols() const { return cols_; }

void Matrix::allocate(int rows, int cols) {
    data_ = new int*[rows];
    for (int i = 0; i < rows; ++i)
        data_[i] = new int[cols];
    rows_ = rows;
    cols_ = cols;
}

void Matrix::copyFrom(const Matrix& other) {
    if (other.rows_ == 0 || other.cols_ == 0 || other.data_ == nullptr)
        return;
    allocate(other.rows_, other.cols_);
    for (int i = 0; i < rows_; ++i)
        for (int j = 0; j < cols_; ++j)
            data_[i][j] = other.data_[i][j];
}

void Matrix::freeMemory() {
    if (data_ != nullptr) {
        for (int i = 0; i < rows_; ++i)
            delete[] data_[i];
        delete[] data_;
    }
    data_ = nullptr;
    rows_ = 0;
    cols_ = 0;
}