// 1331_Êý×éÐòºÅ×ª»».cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted(arr);
        sort(sorted.begin(), sorted.end());
        auto iter = unique(sorted.begin(), sorted.end());
        sorted.resize(distance(sorted.begin(), iter));
        vector<int> result;
        for (auto num : arr) {
            result.push_back((int)distance(sorted.begin(), lower_bound(sorted.begin(), sorted.end(), num)) + 1);
        }
        return result;
    }
};
