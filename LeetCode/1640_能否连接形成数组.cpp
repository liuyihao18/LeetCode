// 1640_能否连接形成数组.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        for (size_t i = 0; i < arr.size();) {
            bool found = false;
            for (auto& piece : pieces) {
                if (arr[i] == piece[0]) {
                    found = true;
                    i++;
                    for (size_t j = 1; j < piece.size(); j++) {
                        if (arr[i] != piece[j]) {
                            found = false;
                        }
                        i++;
                    }
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }
};
