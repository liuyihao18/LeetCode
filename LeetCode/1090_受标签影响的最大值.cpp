// 1090_受标签影响的最大值.cpp
#include "custom.h"
ustd

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<int> index(values.size(), 0);
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&](int i, int j) {
            return values[i] > values[j];
            }
        );
        map<int, int> counts;
        int result = 0;
        int num = 0;
        for (auto i : index) {
            if (num >= numWanted) {
                break;
            }
            if (!counts.count(labels[i])) {
                result += values[i];
                counts[labels[i]]++;
                num++;
            }
            else {
                if (counts[labels[i]] < useLimit) {
                    result += values[i];
                    counts[labels[i]]++;
                    num++;
                }
            }
        }
        return result;
    }
};
