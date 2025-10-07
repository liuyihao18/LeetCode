// 537_¸´Êý³Ë·¨.cpp
#include "stdafx.h"
ustd

class Complex;

ostream& operator<<(ostream& out, const Complex& c);
Complex operator*(const Complex& c1, const Complex& c2);

class Complex {
    friend ostream& operator<<(ostream& out, const Complex& c);
    friend Complex operator*(const Complex& c1, const Complex& c2);
private:
    int real = 0;
    int image = 0;
public:
    Complex(int real, int image) : real(real), image(image) {}
    Complex(const string& s) {
        size_t delimiter_pos = s.find('+');
        real = stoi(s.substr(0, delimiter_pos));
        image = stoi(s.substr(delimiter_pos + 1));
    }
    string __str__() const {
        return to_string(real) + "+" + to_string(image) + "i";
    }
};

Complex operator*(const Complex& c1, const Complex& c2) {
    return Complex(c1.real * c2.real - c1.image * c2.image, c1.real * c2.image + c1.image * c2.real);
}

ostream& operator<<(ostream& out, const Complex& c) {
    out << c.__str__();
    return out;
}

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        Complex c1(num1);
        Complex c2(num2);
        return (c1 * c2).__str__();
    }
};
