// 788_Ðý×ªÊý×Ö.cpp
#include "custom.h"
ustd

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
