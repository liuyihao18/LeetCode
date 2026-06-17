// 3612_用特殊操作处理字符串_I.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    string processStr(string_view s) {
        string result;
        for (char c : s) {
            switch (c) {
            case '*':
                if (!result.empty()) {
                    result.pop_back();
                }
                break;
            case '#':
                result = result + result;
                break;
            case '%':
                ranges::reverse(result);
                break;
            default:
                result.push_back(c);
            }
        }
        return result;
    }
};
