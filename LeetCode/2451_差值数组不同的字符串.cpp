// 2451_差值数组不同的字符串.cpp
#include "custom.h"
ustd

class Solution {
    vector<int> getDifference(const string& word) {
        if (word.size() < 2) return {};
        vector<int> difference;
        vector<size_t> index(word.size() - 1);
        iota(index.begin(), index.end(), 0);
        transform(index.begin(), index.end(), back_inserter(difference), [&](size_t i) {
            return word[i + 1] - word[i];
            }
        );
        return difference;
    }
public:
    string oddString(vector<string>& words) {
        if (words.size() < 3) return "";
        vector<vector<int>> differences;
        transform(words.begin(), words.end(), back_inserter(differences), std::bind(&Solution::getDifference, this, placeholders::_1));
        vector<size_t> index(words.size()); 
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&](size_t i, size_t j) {
            return differences[i] < differences[j];
            }
        );        
        return differences[index[0]] == differences[index[1]] ? words[index.back()] : words[index.front()];
    }
};
