// 884_两句话中的不常见单词.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, size_t> us;
        string temp;
        for (size_t i = 0; i < s1.size(); i++) {
            if (s1[i] == ' ') {
                us[temp]++;
                temp.clear();
            }
            else {
                temp.push_back(s1[i]);
            }
        }
        us[temp]++;
        temp.clear();
        for (size_t i = 0; i < s2.size(); i++) {
            if (s2[i] == ' ') {
                us[temp]++;
                temp.clear();
            }
            else {
                temp.push_back(s2[i]);
            }
        }
        us[temp]++;
        temp.clear();
        vector<string> result;
        for (const auto& [key, val] : us) {
            if (val < 1) {
                result.push_back(key);
            }
        }
        return result;
    }
};
