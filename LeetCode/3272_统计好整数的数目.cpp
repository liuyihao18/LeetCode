// 3272_统计好整数的数目.cpp
#include "stdafx.h"
ustd

class Solution {
    string getPalindrome(int num, int n) {
        string numStrLeft = to_string(num);
        string numStrRight = numStrLeft;
        if (n & 1) {
            numStrRight.pop_back();
        }
        reverse(numStrRight.begin(), numStrRight.end());
        return numStrLeft + numStrRight;
    }
    string getDigitCounts(const string& numStr) {
        string digitCounts(10, 0);
        for (auto c : numStr) {
            digitCounts[static_cast<size_t>(c) - '0']++;
        }
        return digitCounts;
    }
    long long factorial(long long n) {
        long long result = 1;
        while (n > 1) {
            result *= n;
            n--;
        }
        return result;
    }
    long long getResult(const string& digitCounts) {
        long long count0 = digitCounts[0];
        long long counts = accumulate(digitCounts.begin(), digitCounts.end(), 0);
        long long result = (counts - count0) * factorial(counts - 1);
        for (auto count : digitCounts) {
            result /= factorial(count);
        }
        return result;
    }
public:
    long long countGoodIntegers(int n, int k) {
        long long result = 0;
        unordered_set<string> visited;
        int N1 = static_cast<int>(pow(10, (n - 1) / 2));
        int N2 = static_cast<int>(pow(10, (n + 1) / 2));
        for (int i = N1; i < N2; i++) {
            string palindrome = getPalindrome(i, n);
            if (palindrome.size() == n) {
                if (stoll(palindrome) % k == 0) {
                    string digitCounts = getDigitCounts(palindrome);
                    if (!visited.count(digitCounts)) {
                        visited.insert(digitCounts);
                        result += getResult(digitCounts);
                    }
                }
            }
        }
        return result;
    }
};
