// 904_Ë®¹û³ÉÀº.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int, size_t> types;
        size_t left = 0, right = 0;
        int result = 0;
        while (right < fruits.size()) {
            while (types.size() > 2) {
                types[fruits[left]]--;
                if (types[fruits[left]] == 0) {
                    types.erase(fruits[left]);
                }
                left++;
            }
            while (right < fruits.size()) {
                if (types.size() <= 2) {
                    result = max(result, static_cast<int>(right - left));
                    types[fruits[right]]++;
                    right++;
                }
                else {
                    break;
                }
            }
        }
        if (types.size() <= 2) {
            result = max(result, static_cast<int>(right - left));
        }
        return result;
    }
};
