// 2109_Ïò×Ö·û´®Ìí¼Ó¿Õ¸ñ.cpp
#include "custom.h"
ustd

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        auto iter = spaces.begin();
        for (size_t i = 0; i < s.size(); i++) {
            if (iter != spaces.end() && *iter == i) {
                result += ' ';
                ++iter;
            }
            result += s[i];
        }
        return result;
    }
};
