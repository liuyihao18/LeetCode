// 2943_最大化网格图中正方形空洞的面积.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        ranges::sort(hBars);
        ranges::sort(vBars);
    	auto maxLine = [](const vector<int>& bars)
            {
                int line = 0;
                int x1 = bars[0] - 1;
                int x2 = bars[0] + 1;
                for (size_t i = 1; i < bars.size(); i++)
                {
                    if (bars[i] == bars[i - 1] + 1)
                    {
                        x2 = bars[i] + 1;
                    }
                    else
                    {
                        line = max(line, x2 - x1);
                        x1 = bars[i] - 1;
                        x2 = bars[i] + 1;
                    }
                }
                line = max(line, x2 - x1);
                return line;
            };
        const auto hLine = maxLine(hBars);
        const auto vLine = maxLine(vBars);
        const int line = min(hLine, vLine);
        return line * line;
    }
};

#ifndef LEETCODE
int main()
{
    constexpr int n = 14;
    constexpr int m = 4;
    vector hBars = { 13 };
    vector vBars = { 3,4,2,5 };
    Solution solution;
    cout << solution.maximizeSquareHoleArea(n, m, hBars, vBars) << '\n';
    return 0;
}
#endif
