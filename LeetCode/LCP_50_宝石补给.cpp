// LCP_50_±¦Ê¯²¹¸ø.cpp
#include "custom.h"
ustd

class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for (const auto& operation : operations) {
            int x = operation.front(), y = operation.back();
            gem[y] += gem[x] / 2;
            gem[x] -= gem[x] / 2;
        }
        int min = *min_element(gem.begin(), gem.end());
        int max = *max_element(gem.begin(), gem.end());
        return max - min;
    }
};
