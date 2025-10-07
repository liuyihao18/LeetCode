// 1994_好子集的数目.cpp
#include "stdafx.h"
ustd

/* 总算做对了，但是还是TLE了 */
const int directs[] = {
    2, 3, 5, 6, 7, 10, 11, 13, 14, 15, 17, 19, 21, 22, 23, 26, 29, 30
};

class Solution {
    const int remainder = static_cast<int>(1e9 + 7);
    int gcd(int m, int n) {
        while (n != 0) {
            int temp = m % n;
            m = n;
            n = temp;
        }
        return m;
    }
    bool allCoprime(int n, const set<int>& nums) {
        for (auto num : nums) {
            if (gcd(n, num) != 1) {
                return false;
            }
        }
        return true;
    }
    long long pow2(long long n) {
        long long result = 1;
        for (int i = 0; i < n; i++) {
            result *= 2;
            result %= remainder;
        }
        return result;
    }
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        vector<long long> counts(31, 0);
        for (auto num : nums) {
            counts[num]++;
        }
        long long result = 0;
        queue<set<int>> q;
        set<set<int>> s;
        for (auto direct : directs) {
            if (counts[direct] > 0) {
                q.push({ direct });
                s.insert({ direct });
            }
        }
        long long x = pow2(counts[1]);
        while (!q.empty()) {
            set<int> curr = q.front();
            q.pop();
            long long temp = 1;
            for (int num : curr) {
                temp *= counts[num];
                temp %= remainder;
            }
            result += (temp * x) % remainder;
            for (auto i : directs) {
                if (counts[i] > 0) {
                    if (allCoprime(i, curr)) {
                        set<int> next = curr;
                        next.insert(i);
                        if (!s.count(next)) {
                            q.push(next);
                            s.insert(next);
                        }
                    }
                }
            }
        }
        return result % remainder;
    }
};

/*
class Solution {
private:
    static constexpr array<int, 10> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
    static constexpr int num_max = 30;
    static constexpr int mod = 1000000007;

public:
    int numberOfGoodSubsets(vector<int>& nums) {
        vector<int> freq(num_max + 1);
        for (int num : nums) {
            ++freq[num];
        }

        vector<int> f(1 << primes.size());
        f[0] = 1;
        for (int _ = 0; _ < freq[1]; ++_) {
            f[0] = f[0] * 2 % mod;
        }

        for (int i = 2; i <= num_max; ++i) {
            if (!freq[i]) {
                continue;
            }

            // 检查 i 的每个质因数是否均不超过 1 个
            int subset = 0, x = i;
            bool check = true;
            for (int j = 0; j < primes.size(); ++j) {
                int prime = primes[j];
                if (x % (prime * prime) == 0) {
                    check = false;
                    break;
                }
                if (x % prime == 0) {
                    subset |= (1 << j);
                }
            }
            if (!check) {
                continue;
            }

            // 动态规划
            for (int mask = (1 << primes.size()) - 1; mask > 0; --mask) {
                if ((mask & subset) == subset) {
                    f[mask] = (f[mask] + static_cast<long long>(f[mask ^ subset]) * freq[i]) % mod;
                }
            }
        }

        int ans = 0;
        for (int mask = 1, mask_max = (1 << primes.size()); mask < mask_max; ++mask) {
            ans = (ans + f[mask]) % mod;
        }

        return ans;
    }
};
/*
作者：LeetCode - Solution
链接：https ://leetcode-cn.com/problems/the-number-of-good-subsets/solution/hao-zi-ji-de-shu-mu-by-leetcode-solution-ky65/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
