// 1604_警告一小时内使用相同员工卡大于等于三次的人.cpp
#include "stdafx.h"
ustd

class Solution {
    int timeToInt(const string& time) {
        return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
    }
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string, vector<int>> m;
        for (size_t i = 0; i < keyName.size(); i++) {
            m[keyName[i]].push_back(timeToInt(keyTime[i]));
        }
        vector<string> result;
        for (auto& p : m) {
            auto& v = p.second;
            sort(v.begin(), v.end());
            size_t i = 0, j = 1;
            while (j < v.size() && j - i < 3) {
                if (v[j] - v[i] <= 60) {
                    j++;
                }
                else {
                    i++;
                }
                if (j == i) {
                    j++;
                }
            }
            if (j - i >= 3) {
                result.push_back(p.first);
            }
        }
        return result;
    }
};
