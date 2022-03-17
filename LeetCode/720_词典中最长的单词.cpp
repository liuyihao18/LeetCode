// 720_词典中最长的单词.cpp
#include "custom.h"
ustd

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        string result;
        set<string> s;
        for (auto&& word : words) {
            if (word.size() == 1) {
                s.insert(word);
                if (word.size() > result.size()) {
                    result = word;
                }
            }
            else {
                if (s.count(word.substr(0, word.size() - 1))) {
                    s.insert(word);
                    if (word.size() > result.size()) {
                        result = word;
                    }
                }
            }
        }
        return result;
    }
};
