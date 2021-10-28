// 229_求众数_II.cpp
#include "custom.h"
#define VOTE
ustd

class Solution {
public:
#ifndef VOTE
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        size_t count = 0;
        int temp = INT_MAX;
        for (auto num : nums) {
            if (num == temp) {
                count++;
            }
            else {
                if (count > nums.size() / 3) {
                    result.push_back(temp);
                }
                temp = num;
                count = 1;
            }
        }
        if (count > nums.size() / 3) {
            result.push_back(temp);
        }
        return result;
    }
#else
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        pair<int, size_t> votes[2] = { { INT_MIN, 0 }, {INT_MAX, 0} };
        for (auto num : nums) {
            if (num == votes[0].first) {
                votes[0].second++;
            }
            else if (num == votes[1].first) {
                votes[1].second++;
            }
            else if (votes[0].second == 0) {
                votes[0].first = num;
                votes[0].second++;
            }
            else if (votes[1].second == 0) {
                votes[1].first = num;
                votes[1].second++;
            }
            else {
                votes[0].second--;
                votes[1].second--;
            }
        }
        for (auto vote : votes) {
            // 如果投票数大于0，需要再统计出现次数
            if (vote.second > 0 && static_cast<size_t>(count(nums.begin(), nums.end(), vote.first)) > nums.size() / 3) {
                result.push_back(vote.first);
            }
        }
        return result;
    }
#endif
};