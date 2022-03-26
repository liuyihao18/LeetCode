// 682_∞Ù«Ú±»»¸.cpp
#include "custom.h"
ustd

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> scores;
        for (const auto& op : ops) {
            if (op == "C") {
                scores.pop_back();
            }
            else if (op == "D") {
                scores.push_back(2 * scores.back());
            }
            else if (op == "+") {
                scores.push_back(*scores.rbegin() + *++scores.rbegin());
            }
            else {
                scores.push_back(stoi(op));
            }
        }
        return accumulate(scores.begin(), scores.end(), 0);
    }
};
