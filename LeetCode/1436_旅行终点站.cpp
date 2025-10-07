// 1436_旅行终点站.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, string> src_to_dest;
        for (const auto& a_path : paths) {
            src_to_dest[a_path[0]/* src */] = a_path[1] /* dest */;
        }
        for (auto iter = src_to_dest.begin(); iter != src_to_dest.end(); ++iter) {
            if (src_to_dest.find(iter->second) == src_to_dest.end()) {
                return iter->second;
            }
        }
        return ""; // 不会遇到
    }
};