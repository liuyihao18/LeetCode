// 1592_重新排列单词间的空格.cpp
#include "custom.h"
ustd

class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> words;
        string word;
        int totalSpaceCount = 0;
        for (auto c : text) {
            if (c == ' ') {
                totalSpaceCount++;
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
        int nSpace = static_cast<int>(words.size() - 1);
        string result;
        if (nSpace == 0) {
            result += std::move(words.back());
            for (int j = 0; j < totalSpaceCount; j++) {
                result += ' ';
            }
        }
        else {
            int nSpaceCount = totalSpaceCount / nSpace, remainSpaceCount = totalSpaceCount % nSpace;
            for (size_t i = 0; i + 1 < words.size(); i++) {
                result += std::move(words[i]);
                for (int j = 0; j < nSpaceCount; j++) {
                    result += ' ';
                }
            }
            result += std::move(words.back());
            for (int j = 0; j < remainSpaceCount; j++) {
                result += ' ';
            }
        }
        return result;
    }
};
