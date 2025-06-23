// 135_·Ö·¢ÌÇ¹û.cpp
#include "custom.h"
ustd

class Solution {
public:
    int candy(vector<int>& ratings) {
        size_t n = ratings.size();
        int candySum = 0;
        vector<int> candyLeft(ratings.size(), 1);
        for (size_t i = 1; i != n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candyLeft[i] = candyLeft[i - 1] + 1;
            }
        }
        vector<int> candyRight(ratings.size(), 1);
        for (size_t i = n - 2; i != -1; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candyRight[i] = candyRight[i + 1] + 1;
            }
        }
        for (size_t i = 0; i < n; i++) {
            candySum += max(candyLeft[i], candyRight[i]);
        }
        return candySum;
    }
};
