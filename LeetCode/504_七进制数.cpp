// 504_Æß½øÖÆÊý.cpp
#include "custom.h"
ustd

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }
        bool positive = true;
        if (num < 0) {
            positive = false;
            num = -num;
        }
        string result;
        while (num > 0) {
            result += to_string(num % 7);
            num /= 7;
        }
        if (!positive) {
            result += '-';
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
