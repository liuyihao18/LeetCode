// 1813_æ‰◊”œ‡À∆–‘_III.cpp
#include "custom.h"
ustd

class Solution {
    vector<string> split(const string& str) {
        vector<string> words;
        string word;
        for (auto c : str) {
            if (c == ' ') {
                if (!word.empty()) {
                    words.push_back(std::move(word));
                    word.clear();
                }
            }
            else {
                word += c;
            }
        }
        if (!word.empty()) {
            words.push_back(std::move(word));
            word.clear();
        }
        return words;
    }
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {      
        if (sentence1.size() < sentence2.size()) {
            swap(sentence1, sentence2);
        }
        vector<string> words1 = split(sentence1);
        vector<string> words2 = split(sentence2);
        size_t i = 0;
        while (i < words2.size() && words1[i] == words2[i]) {
            i++;
        }
        if (words1.size() < words2.size()) {
            return false;
        }
        size_t j = words1.size() - words2.size() + i;
        while (i < words2.size() && words1[j] == words2[i]) {
            i++;
            j++;
        }
        return i == words2.size();
    }
};
