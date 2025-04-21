// 2145_统计隐藏数组数目.cpp
#include "custom.h"
ustd

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        size_t n = differences.size();
        long long minimum = 0, maximum = 0;
        long long sum = 0;
        for (auto difference : differences) {
            sum += difference;
            minimum = min(minimum, sum);
            maximum = max(maximum, sum);
        }
        long long result = static_cast<long long>(upper - lower) - (maximum - minimum) + 1;
        return result > 0 ? static_cast<int>(result) : 0;
    }
};
