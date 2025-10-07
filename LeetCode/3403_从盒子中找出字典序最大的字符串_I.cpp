// 3403_从盒子中找出字典序最大的字符串_I.cpp
#include "stdafx.h"
ustd

class Solution {
    size_t find(const string_view& word) {
        size_t index = max_element(word.begin(), word.end()) - word.begin();
        map<string_view, size_t> subStrings;
        for (size_t i = 0; i < word.size(); i++) {
            if (word[i] == word[index]) {
                subStrings[word.substr(i)] = i;
            }
        }
        return subStrings.rbegin()->second;
    }
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        size_t i = find(word);
        size_t j = word.size() - (numFriends - i);
        return word.substr(i, j - i + 1);
    }
};
