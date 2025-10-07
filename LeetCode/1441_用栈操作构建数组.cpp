// 1441_��ջ������������.cpp
#include "stdafx.h"
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
