// 1733_需要教语言的最少人数.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int minTech = INT_MAX;
        int m = static_cast<int>(languages.size());
        vector<int> languageIndex(n, 0);
        vector<int> languageCount(n, 0);
        for (vector<int>& language : languages) {
            sort(language.begin(), language.end());
            for (int l : language) {
                languageCount[--l]++;
            }
        }
        iota(languageIndex.begin(), languageIndex.end(), 1);
        sort(languageIndex.begin(), languageIndex.end(), [&](int i, int j) {
            return languageCount[--i] > languageCount[--j];
            }
        );
        for (int li : languageIndex) {
            vector<int> tech(m, 0);
            int sum = 0;
            for (const vector<int>& friendship : friendships) {
                int u = friendship[0] - 1;
                int v = friendship[1] - 1;
                const vector<int>& language1 = languages[u];
                const vector<int>& language2 = languages[v];
                vector<int> bothLanguage;
                set_intersection(language1.begin(), language1.end(), language2.begin(), language2.end(), back_inserter(bothLanguage));
                if (bothLanguage.size() == 0) {
                    auto iter1 = lower_bound(language1.begin(), language1.end(), li);
                    if (iter1 == language1.end() || *iter1 != li) {
                        sum += tech[u] != 1;
                        tech[u] = 1;
                    }
                    auto iter2 = lower_bound(language2.begin(), language2.end(), li);
                    if (iter2 == language2.end() || *iter2 != li) {
                        sum += tech[v] != 1;
                        tech[v] = 1;
                    }
                }
                if (sum >= minTech) {
                    break;
                }
            }
            minTech = min(minTech, sum);
        }
        return minTech;
    }
};
