// 1218_最长定差子序列.cpp
#include "custom.h"
ustd

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        vector<int> hashTable(40002, 0);
        int result = 0;
        for (auto num : arr) {
            hashTable[num + 20001] = hashTable[num + 20001 - difference] + 1;
            result = max(hashTable[num + 20001], result);
        }
        return result;
    }
};