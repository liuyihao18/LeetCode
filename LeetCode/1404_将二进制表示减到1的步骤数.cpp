// 1404_将二进制表示减到1的步骤数.cpp
#include "stdafx.h"
ustd

class Solution {
    string add(string&& a, string&& b) {
        ranges::reverse(a);
        ranges::reverse(b);
        string c;
        int carry = 0;
        size_t i{ 0 };
        for (size_t n{ min(a.size(), b.size()) }; i < n; i++) {
            int digit = a[i] - '0' + b[i] - '0' + carry;
            carry = digit / 2;
            digit %= 2;
            c.push_back(static_cast<char>(digit + '0'));
        }
        for (size_t n{ a.size() }; i < n; i++) {
            int digit = a[i] - '0' + carry;
            carry = digit / 2;
            digit %= 2;
            c.push_back(static_cast<char>(digit + '0'));
        }
        for (size_t n{ b.size() }; i < n; i++) {
            int digit = b[i] - '0' + carry;
            carry = digit / 2;
            digit %= 2;
            c.push_back(static_cast<char>(digit + '0'));
        }
        while (carry) {
            int digit = carry;
            carry = digit / 2;
            digit %= 2;
            c.push_back(static_cast<char>(digit + '0'));
        }
        ranges::reverse(c);
        return c;
    }

    string shift(string&& a) {
        a.pop_back();
        return a;
    }

public:
    int numSteps(string s) {
        int steps{ 0 };
        while (s != "1") {
            if (s.back() == '0') {
                s = shift(std::move(s));
            }
            else {
                s = add(std::move(s), "1");
            }
            steps++;
        }
        return steps;
    }
};
