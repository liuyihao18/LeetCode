// 1773_统计匹配检索规则的物品数量.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        size_t i = -1;
        if (ruleKey == "type") i = 0;
        else if (ruleKey == "color") i = 1;
        else i = 2;
        int result = 0;
        for (const auto& item : items) {
            if (item[i] == ruleValue) {
                result++;
            }
        }
        return result;
    }
};
