// 1253_重构2行二进制矩阵.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> result(2, vector<int>(colsum.size(), 0));
        for (size_t i = 0; i < colsum.size(); i++) {
            switch (colsum[i]) {
            case 0:
                break;
            case 1:
                if (upper >= lower && upper > 0) {
                    result[0][i] = 1;
                    upper--;
                }
                else if (lower >= upper && lower > 0) {
                    result[1][i] = 1;
                    lower--;
                }
                else {
                    return {};
                }
                break;
            case 2:
                if (upper > 0 && lower > 0) {
                    result[0][i] = 1;
                    result[1][i] = 1;
                    upper--;
                    lower--;
                }
                else {
                    return {};
                }
                break;
            default:
                return {};
           }
        }
        if (lower + upper == 0) {
            return result;
        }
        else {
            return {};
        }
    }
};
