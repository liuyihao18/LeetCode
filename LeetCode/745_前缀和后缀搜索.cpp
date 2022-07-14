// 745_Ç°×ººÍºó×ºËÑË÷.cpp
#include "custom.h"
ustd

class WordFilter {
    map<string, vector<int>> prefix;
    map<string, vector<int>> suffix;
public:
    WordFilter(vector<string>& words) {
        int n = static_cast<int>(words.size());
        for (int i = 0; i < n; i++) {
            const auto& word = words[i];
            for (size_t l = 1; l <= word.size(); l++) {
                prefix[word.substr(0, l)].push_back(i);
                suffix[word.substr(word.size() - l)].push_back(i);
            }
        }
    }

    int f(string pref, string suff) {
        if (prefix.count(pref) && suffix.count(suff)) {
            const auto& index1 = prefix[pref];
            const auto& index2 = suffix[suff];
            int n1 = static_cast<int>(index1.size()), n2 = static_cast<int>(index2.size());
            int i1 = n1 - 1, i2 = n2 - 1;
            while (i1 >= 0 && i2 >= 0) {
                if (index1[i1] == index2[i2]) {
                    return index1[i1];
                }
                else if (index1[i1] < index2[i2]) {
                    i2--;
                }
                else {
                    i1--;
                }
            }
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
