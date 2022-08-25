// 658_找到K个最接近的元素.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto j = lower_bound(arr.begin(), arr.end(), x);
        auto i = prev(j);
        while (k > 0) {
            if (i >= arr.begin() && j < arr.end()) {
                if (abs(*i - x) <= abs(*j - x)) {
                    --i;
                }
                else {
                    ++j;
                }
            }
            else if (i >= arr.begin()) {
                --i;
            }
            else if (j < arr.end()) {
                ++j;
            }
            --k;
        }
        return vector<int>(i + 1, j);
    }
};
