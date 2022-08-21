// 1455_检查单词是否为句中其他单词的前缀.cpp
#include "custom.h"
ustd

class Solution {
    bool check(const string& word, const string& searchWord) {
        if (word.size() < searchWord.size()) {
            return false;
        }
        string_view wordView(word);
        if (wordView.substr(0, searchWord.size()) == searchWord) {
            return true;
        }
        return false;
    }
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string word;
        sentence.push_back(' ');
        int i = 1;
        for (auto c : sentence) {
            if (c == ' ') {
                if (check(word,searchWord)) {
                    return i;
                }
                word.clear();
                i++;
            }
            else {
                word += c;
            }
        }
        return -1;
    }
};
