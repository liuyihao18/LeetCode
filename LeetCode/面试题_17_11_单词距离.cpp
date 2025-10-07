// √Ê ‘Ã‚_17_11_µ•¥ æ‡¿Î.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        map<string, vector<size_t>> wordsIndex;
        for (size_t i = 0; i < words.size(); i++) {
            wordsIndex[words[i]].push_back(i);
        }
        const auto& word1Index = wordsIndex[word1];
        const auto& word2Index = wordsIndex[word2];
        size_t i = 0, j = 0;
        int minDistance = INT_MAX;
        while (i < word1Index.size() && j < word2Index.size()) {
            size_t index1 = word1Index[i];
            size_t index2 = word2Index[j];
            if (index1 <= index2) {
                int distance = static_cast<int>(index2) - static_cast<int>(index1);
                minDistance = min(minDistance, distance);
                i++;
            }
            else {
                int distance = static_cast<int>(index1) - static_cast<int>(index2);
                minDistance = min(minDistance, distance);
                j++;
            }
        }
        return minDistance;
    }
};
