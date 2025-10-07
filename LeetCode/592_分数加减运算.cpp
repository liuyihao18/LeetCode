// 592_分数加减运算.cpp
#include "stdafx.h"
ustd

int lcm(int m, int n) {
    return m * n / gcd(m, n);
}

class Fraction {
    friend ostream& operator<<(ostream& out, const Fraction& fraction);
    friend Fraction operator+(const Fraction& fraction1, const Fraction& fraction2);
private:
    int _numerator, _denominator;
    void _simplify() {
        if (_numerator == 0) {
            _denominator = 1;
            return;
        }
        int _gcd = gcd(_numerator, _denominator);
        _numerator = _numerator / _gcd;
        _denominator = _denominator / _gcd;
    }
    int gcd(int m, int n) {
        m = abs(m);
        n = abs(n);
        while (n > 0) {
            int r = m % n;
            m = n;
            n = r;
        }
        return m;
    }
public:
    Fraction(int numerator, int denominator) 
        : _numerator(numerator), _denominator(denominator) {
        if (denominator == 0) {
            throw runtime_error("Division by zero!");
        }
        _simplify();
    }
    string toString() {
        return to_string(_numerator) + "/" + to_string(_denominator);
    }
};

ostream& operator<<(ostream& out, const Fraction& fraction) {
    out << fraction._numerator << "/" << fraction._denominator << endl;
    return out;
}

Fraction operator+(const Fraction& fraction1, const Fraction& fraction2) {
    int denominator = lcm(fraction1._denominator, fraction2._denominator);
    int numerator = fraction1._numerator * (denominator / fraction1._denominator) + fraction2._numerator * (denominator / fraction2._denominator);
    return Fraction(numerator, denominator);
}

class Solution {
public:
    string fractionAddition(string expression) {
        int positive = 1;
        int numerator = 0;
        int denominator = 0;
        vector<Fraction> v;
        int state = 0;
        expression += '#';
        for (auto c : expression) {
            switch (state) {
            case 0:
                if (c == '-') {
                    positive = -1;
                }
                else if (isdigit(c)) {
                    numerator = c - '0';
                }
                state = 1;
                break;
            case 1:
                if (c == '/') {
                    denominator = 0;
                    state = 2;
                }
                else if (isdigit(c)) {
                    numerator = numerator * 10 + c - '0';
                }
                break;
            case 2:
                if (c == '#') {
                    v.emplace_back(numerator * positive, denominator);
                }
                else if (c == '+' || c == '-') {
                    v.emplace_back(numerator * positive, denominator);
                    positive = c == '+' ? 1 : -1;
                    numerator = 0;
                    state = 1;
                }
                else if (isdigit(c)) {
                    denominator = denominator * 10 + c - '0';
                }
                break;
            }
        }
        return accumulate(v.begin(), v.end(), Fraction(0, 1)).toString();
    }
};
