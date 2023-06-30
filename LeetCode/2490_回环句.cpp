// 2490_»Ø»·¾ä.cpp
#include "custom.h"
ustd

class Solution {
    vector<string> split(const string& sentence) {
        vector<string> words;
        string word;
        for (auto c : sentence) {
            if (c == ' ' && !word.empty()) {
                words.push_back(word);
                word = "";
            }
            else {
                word += c;
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }
        return words;
    }
public:
    bool isCircularSentence(string sentence) {
        vector<string> words = split(sentence);
        for (size_t i = 0; i < words.size(); i++) {
            if (words[i].back() != words[(i + 1) % words.size()].front()) {
                return false;
            }
        }
        return true;
    }
};
