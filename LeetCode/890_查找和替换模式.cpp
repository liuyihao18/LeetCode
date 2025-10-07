// 890_查找和替换模式.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        for (const string& word : words) {
            map<char, char> m;
            bool match = true;
            for (size_t i = 0; i < pattern.size(); i++) {
                if (m.count(pattern[i])) {
                    if (m[pattern[i]] != word[i]) {
                        match = false;
                        break;
                    }
                }
                else {
                    m[pattern[i]] = word[i];
                }
            }
            m.clear();
            for (size_t i = 0; i < word.size(); i++) {
                if (m.count(word[i])) {
                    if (m[word[i]] != pattern[i]) {
                        match = false;
                        break;
                    }
                }
                else {
                    m[word[i]] = pattern[i];
                }
            }
            if (match) {
                result.push_back(word);
            }
        }
        return result;
    }
};
