// 811_子域名访问计数.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> m;
        for (const auto& cpdomain : cpdomains) {
            istringstream is(cpdomain);
            int cnt{ 0 };
            is >> cnt;
            string domain;
            is >> domain;
            string temp;
            for (auto iter = domain.rbegin(); iter != domain.rend(); ++iter) {
                if (*iter == '.') {
                    m[temp] += cnt;
                }
                temp += *iter;
            }
            m[temp] += cnt;
        }
        vector<string> result;
        for (const auto& p : m) {
            string name = p.first;
            reverse(name.begin(), name.end());
            result.push_back(to_string(p.second) + ' ' + name);
        }
        return result;
    }
};
