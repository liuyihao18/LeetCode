// 352_将数据流变为多个不相交区间.cpp
#include "custom.h"
ustd

class SummaryRanges {
public:
    SummaryRanges() {
        
    }

    void addNum(int val) {
        nums.insert(val);
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> result;
        if (nums.empty()) {
            return result;
        }
        vector<int> interval;
        auto iter = nums.begin();
        interval.push_back(*iter);
        auto last_iter = iter;
        ++iter;
        while (iter != nums.end()) {
            if (*iter - *last_iter > 1) {
                interval.push_back(*last_iter);
                result.push_back(interval);
                interval.clear();
                interval.push_back(*iter);
            }
            last_iter = iter;
            ++iter;
        }
        interval.push_back(*last_iter);
        result.push_back(interval);
        return result;
    }
private:
    set<int>nums;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */