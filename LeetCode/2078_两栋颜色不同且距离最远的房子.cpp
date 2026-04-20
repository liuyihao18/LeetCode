// 2078_两栋颜色不同且距离最远的房子.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maxDistance(const vector<int>& colors) {
        const int n = static_cast<int>(colors.size());
        for (int i = 0; i < n; i++)
        {
	        if (colors[i] != colors[n - 1] || colors[0] != colors[n - i - 1])
	        {
                return n - i - 1;
	        }
        }
        return -1;
    }
};

/*
class Solution {
public:
    int maxDistance(const vector<int>& colors) {
        unordered_map<int, pair<int, int>> um;
        for (int i = 0, n = static_cast<int>(colors.size()); i < n; i++)
        {
	        if (!um.contains(colors[i]))
	        {
                um[colors[i]].first = i;
                um[colors[i]].second = i;
	        }
            else
            {
                um[colors[i]].second = i;
            }
        }
        int ans = 0;
        for (auto&& [k1, v1] : um)
        {
	        for (auto&& [k2, v2] : um)
	        {
		        if (k1 == k2)
		        {
                    continue;
		        }
                ans = max({
                    ans,
                    abs(v2.first - v1.first),
                    abs(v2.first - v1.second),
                    abs(v2.second - v1.first),
                    abs(v2.second - v1.second)
                });
	        }
        }
        return ans;
    }
};
*/
