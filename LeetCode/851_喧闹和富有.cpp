// 851_ÐúÄÖºÍ¸»ÓÐ.cpp
#include "stdafx.h"
ustd

class Solution {
    int _dfs(int i, const vector<vector<int>>& g, const vector<int>& w, vector<bool>& v, vector<int>& r) {
        if (v[i]) {
            return r[i];
        }
        v[i] = true;
        int min_i = i;
        for (const auto& e : g) {
            if (e.back() == i) {
                int j = _dfs(e.front(), g, w, v, r);
                if (w[j] < w[min_i]) {
                    min_i = j;
                }
            }
        }
        r[i] = min_i;
        return r[i];
    }
public:
    vector<int> loudAndRich(const vector<vector<int>>& richer, const vector<int>& quiet) {
        vector<bool> v(quiet.size());
        vector<int> r(quiet.size());
        for (size_t i = 0; i < r.size(); i++) {
            r[i] = static_cast<int>(i);
        }
        for (size_t i = 0; i < r.size(); i++) {
            _dfs(static_cast<int>(i), richer, quiet, v, r);
        }
        return r;
    }
};
