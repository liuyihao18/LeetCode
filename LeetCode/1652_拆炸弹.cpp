// 1652_²ðÕ¨µ¯.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> result(code.size(), 0);
        if (k == 0) {
            return result;
        }
        if (k > 0) {
            for (size_t i = 0; i < result.size(); i++) {
                int sum = 0;
                for (size_t j = 1; j <= k; j++) {
                    sum += code[(i + j) % result.size()];
                }
                result[i] = sum;
            }
        }
        else {
            k = -k;
            for (size_t i = 0; i < result.size(); i++) {
                int sum = 0;
                for (size_t j = 1; j <= k; j++) {
                    sum += code[(i - j + result.size()) % result.size()];
                }
                result[i] = sum;
            }
        }
        return result;
    }
};
