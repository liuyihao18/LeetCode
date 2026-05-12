// 788_Ðý×ªÊý×Ö.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int rotatedDigits(const int n) {
        auto isGoodNum = [](int num)
            {
                bool isExactTheSame = true;
                while (num > 0) {
                    constexpr int rotate[10] = {
                        0, 1, 5, -1, -1, 2, 9, -1, 8, 6
                    };
                    const int r = num % 10;
                    if (rotate[r] == -1)
                    {
                        return false;
                    }
                    if (rotate[r] != r)
                    {
                        isExactTheSame = false;
                    }
                    num /= 10;
                }
                return !isExactTheSame;
            };
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
	        if (isGoodNum(i))
	        {
                count++;
	        }
        }
        return count;
    }
};

/*
class Solution {
    bool isGoodNum(int num) {
        vector<int> digits;
        int temp = num;
        while (temp > 0) {
            digits.push_back(temp % 10);
            temp /= 10;
        }
        for (auto& digit : digits) {
            switch (digit)
            {
            case 0:
            case 1:
            case 8:
                break;
            case 2:
                digit = 5;
                break;
            case 5:
                digit = 2;
                break;
            case 6:
                digit = 9;
                break;
            case 9:
                digit = 6;
                break;
            default:
                return false;
            }
        }
        temp = 0;
        for (auto iter = digits.rbegin(); iter != digits.rend(); ++iter) {
            temp = temp * 10 + *iter;
        }
        return num != temp;
    }
public:
    int rotatedDigits(int n) {
        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (isGoodNum(i)) {
                result++;
            }
        }
        return result;
    }
};
*/
