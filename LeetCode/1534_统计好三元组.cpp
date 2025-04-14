// 1534_统计好三元组.cpp
#include "custom.h"
ustd

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        size_t n = arr.size();
        int result = 0;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = i + 1; j < n; j++) {
                for (size_t k = j + 1; k < n; k++) {
                    if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                        result++;
                    }
                }
            }
        }
        return result;
    }
};
