// 1927_«Û∫Õ”Œœ∑.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool sumGame(const string& num) {
        int leftCount = 0, leftSum = 0, rightCount = 0, rightSum = 0;
        for (size_t i = 0, n = num.size(); i < n / 2; i++)
        {
            if (num[i] == '?')
            {
                leftCount++;
            }
            else
            {
                leftSum += num[i] - '0';
            }
            if (num[i + n / 2] == '?')
            {
                rightCount++;
            }
            else
            {
                rightSum += num[i + n / 2] - '0';
            }
        }

        if ((leftCount - rightCount) % 2 == 1)
        {
            return true;
        }

        return (rightSum - leftSum) * 2 != (leftCount - rightCount) * 9;
    }
};
