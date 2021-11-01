// 575_·ÖÌÇ¹û.cpp
#include "custom.h"
ustd

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> candy(candyType.begin(), candyType.end());
        return min(candy.size(), candyType.size() / 2);
    }
};