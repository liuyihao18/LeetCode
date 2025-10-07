// 506_相对名次.cpp
#include "stdafx.h"
ustd

class Solution {
    struct Athlete {
        size_t index;
        int score;
        bool operator>(const Athlete& a) const {
            return score > a.score;
        }
    };
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<Athlete> athletes;
        for (size_t i = 0; i < score.size(); i++) {
            athletes.push_back({ i, score[i] });
        }
        sort(athletes.begin(), athletes.end(), greater<Athlete>());
        vector<string> result(athletes.size());
        vector<string> _map = { "Gold Medal","Silver Medal","Bronze Medal" };
        for (size_t i = 0; i < athletes.size(); i++) {
            if (i < 3) {
                result[athletes[i].index] = _map[i];
            }
            else {
                result[athletes[i].index] = to_string(i + 1);
            }
        }
        return result;
    }
};