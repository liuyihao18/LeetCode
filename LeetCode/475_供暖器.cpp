// 475_¹©Å¯Æ÷.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    /*
    int findRadius(vector<int>& houses, vector<int>& heaters) {        
        sort(heaters.begin(), heaters.end());
        int min_r = INT_MIN;
        for (auto house : houses) {
            auto left = lower_bound(heaters.begin(), heaters.end(), house);
            auto right = upper_bound(heaters.begin(), heaters.end(), house);
            if (left == heaters.end()) {
                min_r = max(min_r, house - heaters.back());
            }
            else {
                if (left != heaters.begin() && *left != house) {
                    --left;
                }
                if (right != heaters.end()) {
                    min_r = max(min_r, min(abs(house - *left), abs(house - *right)));
                }
                else {
                    min_r = max(min_r, house - *left);
                }
            }
        }
        return min_r;
    }
    */
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        size_t i = 0;
        size_t j = 0;
        int min_r = INT_MIN;
        while (i < houses.size() && j < heaters.size()) {
            while (j < heaters.size() - 1 && abs(heaters[j + 1] - houses[i]) <= abs(heaters[j] - houses[i])) {
                j++;
            }
            min_r = max(min_r, abs(heaters[j] - houses[i]));
            int right = heaters[j] + min_r;
            while (i < houses.size() && houses[i] <= right) {
                i++;
            }
        }
        return min_r;
    }
};
