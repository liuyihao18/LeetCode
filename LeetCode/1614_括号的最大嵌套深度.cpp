// 1614_���ŵ����Ƕ�����.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxDepth(string s) {
        int max_depth = 0;
        int depth = 0;
        for (auto c : s)
            if (c == '(') max_depth = max(max_depth, ++depth);
            else if (c == ')') --depth;
        return max_depth;
    }
};
