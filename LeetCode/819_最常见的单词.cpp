// 819_最常见的单词.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, size_t> counts;
        string word;
        paragraph += ' ';
        for (auto c : paragraph) {
            if (isalpha(c)) {
                word += tolower(c);
            }
            else {
                if (!word.empty()) {
                    counts[word]++;
                }
                word.clear();
            }
        }
        for (const auto& word : banned) {
            counts.erase(word);
        }
        return max_element(counts.begin(), counts.end(), [](const pair<string, size_t>& p1, const pair<string, size_t>& p2) {
            return p1.second < p2.second;
            })->first;
    }
};
