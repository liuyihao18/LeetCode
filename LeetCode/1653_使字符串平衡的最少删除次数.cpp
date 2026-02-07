// 1653_使字符串平衡的最少删除次数.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int minimumDeletions(const string& s) {
        size_t leftB{};
        size_t rightA{ static_cast<size_t>(count(begin(s),end(s), 'a')) };
        size_t result{ leftB + rightA };
        for (size_t i{}, n{ s.size() }; i < n; i++)
        {
            if (s[i] == 'b') leftB++;
            if (s[i] == 'a') rightA--;
            result = min(result, leftB + rightA);
        }
        return static_cast<int>(result);
    }
};
