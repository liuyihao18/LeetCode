// 3272_统计好整数的数目.cpp
#include "custom.h"
ustd

class Solution {
    pair<string, string> getPalindrome(int num) {
        string numStrLeft = to_string(num);
        string numStrRight1 = numStrLeft, numStrRight2 = numStrLeft.substr(0, numStrLeft.size() - 1);
        reverse(numStrRight1.begin(), numStrRight1.end());
        reverse(numStrRight2.begin(), numStrRight2.end());
        string palindrome1 = numStrLeft + numStrRight1, palindrome2 = numStrLeft + numStrRight2;
        return { palindrome1, palindrome2 };
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
        int N2 = static_Cast<int>(pow(10, (n + 1) / 2));
        cout << N1 << " - " << N2 << endl;
        for (int i = N1; i < N2; i++) {
            auto [palindrome1, palindrome2] = getPalindrome(i);
            if (palindrome1.size() == n) {
                if (stoll(palindrome1) % k == 0) {
                    string digitCounts = getDigitCounts(palindrome1);
                    if (!visited.count(digitCounts)) {
                        visited.insert(digitCounts);
                        result += getResult(digitCounts);
                    }
                }
            }
            if (palindrome2.size() == n) {
                if (stoll(palindrome2) % k == 0) {
                    string digitCounts = getDigitCounts(palindrome2);
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
