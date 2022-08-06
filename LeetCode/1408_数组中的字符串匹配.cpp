// 1408_数组中的字符串匹配.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
        for_each(words.begin(), words.end(), [&](const string& word) {
            if (find_if(words.begin(), words.end(), [&](const string& other) {
                return word != other && other.find(word) != string::npos;
                }) != words.end())
                result.push_back(word);
            });
        return result;
    }
};
