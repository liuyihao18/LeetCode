// 38_外观数列.cpp
#include "custom.h"
ustd

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string num_string = countAndSay(n - 1);
        string result;
        char number = num_string.front();
        int count = 1;
        for (size_t i = 1; i < num_string.size(); i++) {
            if (num_string[i] == number) {
                count++;
            }
            else {
                result += to_string(count);
                result += number;
                number = num_string[i];
                count = 1;
            }
        }
        result += to_string(count);
        result += number;
        return result;
    }
};