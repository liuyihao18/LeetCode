#pragma once
#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <ostream>

template <typename T>
class Matrix {
private:
    size_t m, n;
    T* data;
public:
    Matrix() : m(0), n(0), data(nullptr) {}
    Matrix(size_t m, size_t n) : m(m), n(n) {
        data = new T[m * n]();
    }
    Matrix(const Matrix& other) : m(other.m), n(other.n) {
        data = new T[m * n]();
        for (size_t i = 0; i < m * n; i++) {
            data[i] = other.data[i];
        }
    }
    Matrix(Matrix&& other) noexcept : m(other.m), n(other.n), data(other.data) {
        other.data = nullptr;
        other.m = 0;
        other.n = 0;
    }
    Matrix& operator=(const Matrix& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data;
        m = other.m;
        n = other.n;
        data = new T[m * n]();
        for (size_t i = 0; i < m * n; i++) {
            data[i] = other.data[i];
        }
        return *this;
    }
    Matrix& operator=(Matrix&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        m = other.m;
        n = other.n;
        data = other.data;
        other.data = nullptr;
        other.m = 0;
        other.n = 0;
        return *this;
    }
    ~Matrix() {
        delete[] data;
    }
    size_t getM() const { return m; }
    size_t getN() const { return n; }
    T& operator()(size_t i, size_t j) {
        if (i >= m || j >= n) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[i * m + j];
    }
    T operator()(size_t i, size_t j) const {
        if (i >= m || j >= n) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[i * m + j];
    }
public:
    static Matrix<T> zero(size_t m, size_t n) {
        Matrix<T> matrix(m, n);
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                matrix(i, j) = 0;
            }
        }
        return matrix;
    }
    static Matrix<T> zero(size_t m) {
        return zero(m, m);
    }
    static Matrix<T> eye(size_t m) {
        Matrix<T> matrix(m, m);
        for (size_t i = 0; i < m; i++) {
            matrix(i, i) = 1;
        }
        return matrix;
    }

    template <typename T>
    friend std::ostream& operator<<(std::ostream& out, const Matrix<T>& A);

    template <typename T>
    friend Matrix<T> operator*(const Matrix<T>& A, const Matrix<T>& B);

    template <typename T>
    friend Matrix<T> quickPow(const Matrix<T>& A, int n);
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& A) {
    for (size_t i = 0; i < A.m; i++) {
        for (size_t j = 0; j < A.n; j++) {
            out << A(i, j) << " ";
        }
        out << std::endl;
    }
    return out;
}

template <typename T>
Matrix<T> operator*(const Matrix<T>& A, const Matrix<T>& B) {
    if (A.n != B.m) {
        throw std::exception("multiply: A.n != B.m");
    }
    Matrix<T> result(A.m, B.n);
    for (size_t i = 0; i < A.m; i++) {
        for (size_t j = 0; j < B.n; j++) {
            result(i, j) = 0;
            for (size_t k = 0; k < A.n; k++) {
                result(i, j) += A(i, k) * B(k, j);
            }
        }
    }
    return result;
}

template <typename T>
Matrix<T> quickPow(const Matrix<T>& A, int n) {
    if (A.m != A.n) {
        throw std::exception("quickPow: A.m != B.n");
    }
    if (n == 0) {
        return Matrix<T>::eye(A.m);
    }
    if (n == 1) {
        return A;
    }
    const Matrix<T> half = quickPow(A, n / 2);
    const Matrix<T> result = half * half;
    return n & 1 ? result * A : result;
}

#endif // !__MATRIX_H__