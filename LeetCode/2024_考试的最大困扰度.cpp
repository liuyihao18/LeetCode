// 2024_考试的最大困扰度.cpp
#include "stdafx.h"
ustd

class Solution {
    int maxConsecutiveChar(string& answerKey, int k, char ch) {
        size_t n = answerKey.size();
        size_t ans = 0;
        for (size_t left = 0, right = 0, sum = 0; right < n; right++) {
            sum += answerKey[right] != ch;
            while (sum > k) {
                sum -= answerKey[left] != ch;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return static_cast<int>(ans);
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxConsecutiveChar(answerKey, k, 'T'),
            maxConsecutiveChar(answerKey, k, 'F'));
    }
};
