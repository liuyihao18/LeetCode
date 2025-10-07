// 1963_使字符串平衡的最小交换次数.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int minSwaps(string s) {
        if (s.empty()) {
            return -1;
        }
        int leftCount = 0;
        int rightCount = 0;
        int result = 0;
        size_t i = 0, j = s.size() - 1;
        while (i < j) {
            while (i < j) {
                if (s[i] == '[') {
                    leftCount++;
                }
                else {
                    leftCount--;
                }
                if (leftCount >= 0) {
                    i++;
                }
                else {
                    break;
                }
            }
            while (i < j) {
                if (s[j] == '[') {
                    rightCount--;
                }
                else {
                    rightCount++;
                }
                if (rightCount >= 0) {
                    j--;
                }
                else {
                    break;
                }
            }
            if (i < j) {
                result++;
                i++;
                j--;
                leftCount = 1;
                rightCount = 1;
            }
        }
        return result;
    }
};
