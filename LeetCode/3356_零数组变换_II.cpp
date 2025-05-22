// 3356_ÁãÊý×é±ä»»_II.cpp
#include "custom.h"
ustd

class Solution {
    bool isZeroArray(vector<int>& nums, const vector<vector<int>>& queries, size_t length) {
        const size_t n = nums.size();
        vector<int> diff(n);
        for (size_t i = 0; i < length; i++) {
            const vector<int>& query = queries[i];
            const int l = query[0];
            const int r = query[1];
            diff[r] += query[2];
            if (l - 1 >= 0) {
                diff[static_cast<size_t>(l - 1)] -= query[2];
            }
        }
        bool flag = true;
        int sum = 0;
        for (size_t i = n - 1; i != -1; i--) {
            sum += diff[i];
            if (sum < nums[i]) {
                flag = false;
                break;
            }
        }
        return flag;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        if (all_of(nums.begin(), nums.end(), [](int num) { return num == 0; })) {
            return 0;
        }
        if (!isZeroArray(nums, queries, queries.size())) {
            return -1;
        }
        int l = 0, r = static_cast<int>(queries.size());
        while (l <= r) { // [l, r]
            const int m = (l + r) / 2;
            if (isZeroArray(nums, queries, m)) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return l > queries.size() ? -1 : l;
    }
};
