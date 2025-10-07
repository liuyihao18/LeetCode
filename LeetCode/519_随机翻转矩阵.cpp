// 519_Ëæ»ú·­×ª¾ØÕó.cpp
#include "stdafx.h"
ustd

class Solution {
    size_t origin_m, origin_n;
    size_t total;
    map<size_t, size_t> map;
public:
    Solution(int m, int n): origin_m(m), origin_n(n), total(m * n) {

    }

    vector<int> flip() {
        size_t k = rand() % total;
        total--;
        vector<int> ans;
        if (map.count(k)) {
            ans = { static_cast<int>(map[k] / origin_n),static_cast<int>(map[k] % origin_n) };
        }
        else {
            ans = { static_cast<int>(k / origin_n),static_cast<int>(k % origin_n) };
        }
        if (map.count(total)) {
            map[k] = map[total];
        }
        else {
            map[k] = total;
        }
        
        return ans;
    }

    void reset() {
        total = origin_m * origin_n;
        map.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
