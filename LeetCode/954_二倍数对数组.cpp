// 954_二倍数对数组.cpp
#include "custom.h"
ustd

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, size_t> counts_p;
        map<int, size_t> counts_n;
        for (auto num : arr) {
            if (num >= 0) {
                counts_p[num]++;
            }
            else {
                counts_n[num]++;
            }
            
        }
        if (counts_p.count(0)) {
            if (counts_p[0] & 1) {
                return false;
            }
            else {
                counts_p.erase(0);
            }
        }
        while (!counts_p.empty()) {
            auto even = counts_p.begin();
            if (counts_p.count(2 * even->first)) {
                auto odd = counts_p.find(2 * even->first);
                if (odd->second < even->second) {
                    return false;
                }
                odd->second -= even->second;
                if (odd->second == 0) {
                    counts_p.erase(odd);
                }
                counts_p.erase(counts_p.begin());
            }
            else {
                return false;
            }            
        }
        while (!counts_n.empty()) {
            auto even = counts_n.rbegin();
            if (counts_n.count(2 * even->first)) {
                auto odd = counts_n.find(2 * even->first);
                if (odd->second < even->second) {
                    return false;
                }
                odd->second -= even->second;
                if (odd->second == 0) {
                    counts_n.erase(odd);
                }
                counts_n.erase(--counts_n.end());
            }
            else {
                return false;
            }
        }
        return true;
    }
};
