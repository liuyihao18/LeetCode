// 969_¼å±ıÅÅĞò.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = static_cast<int>(arr.size());
        vector<int> result;
        for (int i = 1; i <= n; i++) {
            auto iter = find(arr.begin(), arr.end(), i);
            result.emplace_back(static_cast<int>(distance(arr.begin(), iter) + 1));
            reverse(arr.begin(), iter + 1);
            result.emplace_back(static_cast<int>(distance(arr.begin(), arr.end() - i) + 1));
            reverse(arr.begin(), arr.end() - i + 1);
        }
        result.emplace_back(n);
        return result;
    }
};
