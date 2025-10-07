// 792_ƥ�������еĵ�����.cpp
#include "stdafx.h"
ustd

// TLE
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int result = 0;
        for (const auto& word : words) {
            size_t i = 0, j = 0;
            while (i < s.size() && j < word.size()) {
                if (s[i] == word[j]) {
                    i++;
                    j++;
                }
                else {
                    i++;
                }
            }
            if (j == word.size()) {
                result++;
            }
        }
        return result;
    }
};
/*
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.size(); ++i) {
            pos[s[i] - 'a'].push_back(i);
        }
        int res = words.size();
        for (auto& w : words) {
            if (w.size() > s.size()) {
                --res;
                continue;
            }
            int p = -1;
            for (char c : w) {
                auto& ps = pos[c - 'a'];
                auto it = upper_bound(ps.begin(), ps.end(), p);
                if (it == ps.end()) {
                    --res;
                    break;
                }
                p = *it;
            }
        }
        return res;
    }
};
*/
/*
���ߣ����۹ٷ����
���ӣ�https ://leetcode.cn/problems/number-of-matching-subsequences/solutions/1973995/pi-pei-zi-xu-lie-de-dan-ci-shu-by-leetco-vki7/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
