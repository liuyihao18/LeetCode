// 67_二进制求和.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string c;
        char carry{};
        auto pushDigit{
            [&carry, &c](char digit) {
                digit += carry;
                carry = digit / 2;
                digit %= 2;
                c.push_back(digit + '0');
            }
        };
        for (size_t i{}, n{ min(a.size(), b.size()) }; i < n; i++) {
            pushDigit(a[i] - '0' + b[i] - '0');
        }
        for (size_t i{ min(a.size(), b.size()) }, n{ a.size() }; i < n; i++) {
            pushDigit(a[i] - '0');
        }
        for (size_t i{ min(a.size(), b.size()) }, n{ b.size() }; i < n; i++) {
            pushDigit(b[i] - '0');
        }
        while (carry) {
            pushDigit(0);
        }
        reverse(c.begin(), c.end());
        return c;
    }
};
