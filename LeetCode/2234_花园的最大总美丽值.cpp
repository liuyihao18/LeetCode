// 2234_花园的最大总美丽值.cpp
#include "custom.h"
ustd

class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, long long target, long long full, long long partial) {
        sort(flowers.begin(), flowers.end());
        long long overflow = 0;
        while (!flowers.empty() && flowers.back() >= target) {
            overflow++;
            flowers.pop_back();
        }
        long long n = static_cast<long long>(flowers.size());
        long long maximumBeauty = overflow * full;
        long long remainFlowers = newFlowers;
        vector<long long> threshold(n, 0), prefixSum(n, 0);
        long long sumFlowers = flowers[0];
        for (long long i = 1; i < n; i++) {
            threshold[i] = flowers[i] * i - sumFlowers;
            prefixSum[i] = sumFlowers;
            sumFlowers += flowers[i];
        }
        for (long long i = 0; i < n; i++) { // i个满花园                
            long long partialSize = min((sumFlowers + remainFlowers) / (n - i), target - 1);
            auto iter = upper_bound(threshold.begin(), threshold.end(), remainFlowers);
            long long j = static_cast<long long>(distance(threshold.begin(), iter));
            if (j + i < n) {
                partialSize = (prefixSum[j] + remainFlowers) / j;
            }
            /*
            long long temp = flowers[0];
            for (long long j = 1; j + i < n; j++) {
                if (temp + remainFlowers < flowers[j] * j) {
                    partialSize = (temp + remainFlowers) / j;
                    break;
                }
                temp += flowers[j];
            }
            */
            maximumBeauty = max(maximumBeauty, partialSize * partial + (i + overflow) * full);
            remainFlowers -= target - flowers[n - i - 1];
            sumFlowers -= flowers[n - i - 1];
            if (remainFlowers <= 0) {
                break;
            }
        }
        if (remainFlowers >= target - flowers[0]) {
            maximumBeauty = max(maximumBeauty, (n + overflow) * full);
        }
        return maximumBeauty;
    }
};
