// 56_合并区间.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        vector<int> temp = intervals[0];
        for (const auto& interval : intervals) {
            if (interval[0] <= temp[1]) {
                temp[1] = max(temp[1], interval[1]);
            }
            else {
                result.push_back(temp);
                temp = interval;
            }
        }
        result.push_back(temp);
        return result;
    }
};

/*
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
*/
