// 833_字符串中的查找与替换.cpp
#include "custom.h"
ustd

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<size_t> idxs(indices.size());
        iota(idxs.begin(), idxs.end(), 0);
        sort(idxs.begin(), idxs.end(), [&](size_t i, size_t j) { return indices[i] < indices[j]; });        
        size_t idx = 0, i = 0, j = indices[idxs[idx]];
        string result;
        while (i < s.size()) {
            if (i < j) {
                result += s[i];
                i++;
            }
            else {
                bool same = true;
                size_t realI = idxs[idx];
                    for (size_t k = 0; k < sources[realI].size(); k++) {
                        if (i + k >= s.size() || s[i + k] != sources[realI][k]) {
                            same = false;
                            break;
                        }
                    }
                if (same) {
                    result += targets[realI];
                }
                else {
                    for (size_t k = 0; k < sources[realI].size(); k++) {
                        if (i + k < s.size()) {
                            result += s[i + k];
                        }
                    }
                }
                i += sources[realI].size();
                if (idx + 1 == idxs.size()) {
                    j = s.size();
                }
                else {
                    j = indices[idxs[idx + 1]];
                    idx++;
                }
            }
        }
        return result;
    }
};
