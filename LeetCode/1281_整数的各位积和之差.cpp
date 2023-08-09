// 1281_整数的各位积和之差.cpp
#include "custom.h"
ustd

class Solution {
public:
    int subtractProductAndSum(int n) {
        vector<int> digits;
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        int sum = 0, product = 1;
        for (auto digit : digits) {
            sum += digit;
            product *= digit;
        }
        return product - sum;
    }
};
