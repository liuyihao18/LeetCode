// 166_分数到小数.cpp
#include "custom.h"
ustd

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        bool positive = (numerator < 0 && denominator < 0) || (numerator > 0 && denominator > 0);
        long long numerator_long = abs(numerator);
        long long denominator_long = abs(denominator);
        string result;
        while (numerator_long > denominator_long) {
            result += to_string(numerator_long / denominator_long);
            numerator_long = numerator_long % denominator_long;
        }
        if (result.empty()) {
            result += '0';
        }
        if (numerator_long != 0) {
            result += '.';
            map<int, size_t> first_appear;
            first_appear[numerator_long] = result.size();
            while (numerator_long != 0) {
                numerator_long *= 10;
                result += '0' + numerator_long / denominator_long;
                numerator_long = numerator_long % denominator_long;
                if (first_appear.find(numerator_long) != first_appear.end()) {
                    result.insert(first_appear[numerator_long], 1, '(');
                    result += ')';
                    break;
                }
                else {
                    first_appear[numerator_long] = result.size();
                }
            }
        }
        if (!positive) {
            result.insert(result.begin(), '-');
        }
        return result;
    }
};