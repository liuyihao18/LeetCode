// 66_º”“ª.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto result = digits;
        int carry = 1;
        for (auto iter = result.rbegin(); iter != result.rend(); ++iter) {
            *iter += carry;
            if (*iter >= 10) {
                *iter -= 10;
            }
            else {
                carry = 0;
                break;
            }
        }
        if (carry) {
            result.insert(result.begin(), 1);
        }
        return result;
    }
};