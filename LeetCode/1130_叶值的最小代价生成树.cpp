// 1130_叶值的最小代价生成树.cpp
#include "custom.h"
ustd

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        if (arr.size() < 2) {
            return 0;
        }
        int result = 0;
        stack<int> s;
        for (auto x : arr) {
            while (!s.empty() && s.top() <= x) {
                int y = s.top();
                s.pop();
                if (s.empty() || s.top() >= x) {
                    result += x * y;
                }
                else {
                    result += y * s.top();
                }
            }
            s.push(x);
        }
        while (s.size() > 1) {
            int x = s.top();
            s.pop();
            result += x * s.top();
        }
        return result;
    }
};
