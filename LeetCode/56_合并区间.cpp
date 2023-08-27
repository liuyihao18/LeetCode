// 56_合并区间.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue < vector<int>, vector<vector<int>>, greater<vector<int>>> pq(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        while (!pq.empty()) {
            vector<int> fst = pq.top();
            pq.pop();
            while (!pq.empty()) {
                vector<int> snd = pq.top();
                pq.pop();
                if (snd[0] <= fst[1]) {
                    fst[1] = max(fst[1], snd[1]);
                }
                else {
                    pq.push(snd);
                    break;
                }
            }
            result.push_back(fst);
        }
        return result;
    }
};
