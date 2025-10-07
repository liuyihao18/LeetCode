// 1774_最接近目标价格的甜点成本.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    void dfs(const vector<int>& toppingCosts, int p, int curCost, int& res, const int& target) {
        if (abs(res - target) < curCost - target) {
            return;
        }
        else if (abs(res - target) >= abs(curCost - target)) {
            if (abs(res - target) > abs(curCost - target)) {
                res = curCost;
            }
            else {
                res = min(res, curCost);
            }
        }
        if (p == toppingCosts.size()) {
            return;
        }
        dfs(toppingCosts, p + 1, curCost + toppingCosts[p] * 2, res, target);
        dfs(toppingCosts, p + 1, curCost + toppingCosts[p], res, target);
        dfs(toppingCosts, p + 1, curCost, res, target);
    }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int res = *min_element(baseCosts.begin(), baseCosts.end());
        for (auto& b : baseCosts) {
            dfs(toppingCosts, 0, b, res, target);
        }
        return res;
    }
};
/*
作者：力扣官方题解
链接：https ://leetcode.cn/problems/closest-dessert-cost/solutions/2004210/zui-jie-jin-mu-biao-jie-ge-de-tian-dian-2ck06/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
