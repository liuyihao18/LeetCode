// 1441_用栈操作构建数组.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int curr = 1;
        vector<string> result;
        for (auto num : target) {
            while (curr < num) {
                result.push_back("Push");
                result.push_back("Pop");
                curr++;
            }
            result.push_back("Push");
            curr++;
        }
        return result;
    }
};
