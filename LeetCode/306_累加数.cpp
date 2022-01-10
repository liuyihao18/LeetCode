// 306_ÀÛ¼ÓÊý.cpp
#include "custom.h"
ustd

class Solution {
    long long string2int(const string& s) {
        if (s.size() > 1 && s.front() == '0') {
            return -1;
        }
        else {
            return stoll(s);
        }
    }
    size_t num_width(long long num) {
        if (num == 0) {
            return 1;
        }
        size_t width = 0;
        while (num > 0) {
            width++;
            num /= 10;
        }
        return width;
    }
    bool _isAdditiveNumber(const string& num, size_t i, long long first, long long second) {
        if (i == num.size()) {
            return true;
        }
        long long sum = first + second;
        size_t width = num_width(sum);
        if (i + width > num.size()) {
            return false;
        }
        string temp = num.substr(i, width);
        long long temp_num = string2int(temp);
        if (temp_num == -1 || temp_num != sum) {
            return false;
        }
        return _isAdditiveNumber(num, i + width, second, sum);
    }
public:
    bool isAdditiveNumber(string num) {
        if (num.size() < 3) {
            return false;
        }
        for (size_t i = 1; i <= num.length() / 2; i++) {
            for (size_t j = 1; j <= (num.size() - i) / 2; j++) {
                long long first = string2int(num.substr(0, i));
                long long second = string2int(num.substr(i, j));
                if (first == -1 || second == -1) {
                    continue;
                }
                if (_isAdditiveNumber(num, i + j, first, second)) {
                    return true;
                }
            }
        }
        return false;
    }
};
