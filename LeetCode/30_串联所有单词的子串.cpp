// 30_串联所有单词的子串.cpp
#include "custom.h"
ustd

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        size_t m = words.size(), n = words.front().size(), ls = s.size();
        for (size_t i = 0; i < n && i + m * n <= ls; i++) {
            unordered_map<string, size_t> differ;
            // 先划分
            for (size_t j = 0; j < m; j++) {
                differ[s.substr(i + j * n, n)]++;
            }
            for (const auto& word : words) {
                if (--differ[word] == 0) {
                    differ.erase(word);
                }
            }
            if (differ.empty()) {
                result.push_back(static_cast<int>(i));
            }
            // 然后滑动窗口
            for (size_t start = i + n; start + m * n <= ls; start += n) {
                if (--differ[s.substr(start - n, n)] == 0) {
                    differ.erase(s.substr(start - n, n));
                }
                if (++differ[s.substr(start + (m - 1) * n, n)] == 0) {
                    differ.erase(s.substr(start + (m - 1) * n, n));
                }
                if (differ.empty()) {
                    result.push_back(static_cast<int>(start));
                }
            }
        }
        return result;
    }
};
