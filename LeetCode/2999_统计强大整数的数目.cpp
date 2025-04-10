// 2999_统计强大整数的数目.cpp
#include "custom.h"
ustd

class Solution {
    long long getResult(const string& nums, size_t i, int limit) {
        if (i == nums.size()) {
            return 1;
        }
        long long result = 1;
        if (nums[i] - '0' > limit) {
            result = static_cast<long long>(pow(limit + 1, nums.size() - i));
        }
        else {
            result = static_cast<long long>(nums[i] - '0') * static_cast<long long>(pow(limit + 1, nums.size() - i - 1));
            result += getResult(nums, i + 1, limit);
        }
        return result;
    }

    long long calculate(long long finish, int limit, string s) {
        if (finish < stoll(s)) {
            return 0;
        }
        long long base = static_cast<long long>(pow(10, s.size()));
        long long prefix = finish / base ;
        long long suffix = finish % base;
        if (suffix < stoll(s)) {
            prefix--;
        }
        return getResult(to_string(prefix), 0, limit);
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return calculate(finish, limit, s) - calculate(start - 1, limit, s);
    }
};
