// 1390_ËÄÒòÊý.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        ranges::sort(nums);
        int result = 0;
        for (int num : nums)
        {
            vector<int> temp;
            temp.push_back(1);
            if (num != 1) temp.push_back(num);
            for (int i = 2; i * i <= num; i++)
            {
                if (num % i != 0)
                {
                    continue;
                }
                temp.push_back(i);
                if (i != num / i) temp.push_back(num / i);
                if (temp.size() > 4)
                {
                    break;
                }
            }
            if (temp.size() != 4)
            {
                continue;
            }
            for (const int factor : temp)
            {
                result += factor;
            }
        }
        return result;
    }
};
