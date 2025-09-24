// 166_分数到小数.cpp
#include "custom.h"
ustd

class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        if (numerator == 0) {
            return "0";
        }
        int positve = numerator > 0 && denominator > 0 || numerator < 0 && denominator < 0;
        numerator = abs(numerator);
        denominator = abs(denominator);
        string integer = positve ? to_string(numerator / denominator) : "-" + to_string(numerator / denominator);
        numerator %= denominator;
        if (numerator == 0) {
            return integer;
        }
        string decimals;
        map<int, size_t> visited;
        size_t pos = 0;
        while (!visited.count(numerator) && numerator != 0) {
            visited[numerator] = pos++;
            decimals += numerator * 10 / denominator + '0';
            numerator = numerator * 10 % denominator;
        }
        if (numerator == 0) {
            return integer + "." + decimals;
        }
        else {
            return integer + "." + decimals.substr(0, visited[numerator]) +
                "(" + decimals.substr(visited[numerator]) + ")";
        }
    }
};

/* 有错！
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
            map<long long, size_t> first_appear;
            first_appear[numerator_long] = result.size();
            while (numerator_long != 0) {
                numerator_long *= 10;
                result += to_string(numerator_long / denominator_long);
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
*/
