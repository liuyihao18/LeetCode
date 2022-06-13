// 1051_¸ß¶È¼ì²éÆ÷.cpp
#include "custom.h"
ustd

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected(heights);
        sort(expected.begin(), expected.end());
        int result = 0;
        for (size_t i = 0; i < heights.size(); i++) {
            if (heights[i] != expected[i]) result++;
        }
        return result;
    }
};
