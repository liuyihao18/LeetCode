// 3133_数组最后一个元素的最小值.cpp
#include "custom.h"
ustd

class Solution {
    vector<int> toBits(int num) {
        vector<int> bits;
        while (num > 0) {
            bits.push_back(num % 2);
            num /= 2;
        }
        return bits;
    }
    long long fromBits(const vector<int>& bits) {
        long long num = accumulate(bits.rbegin(), bits.rend(), 0LL,
            [](long long num, int bit) {
                return num * 2 + bit;
            }
        );
        return num;
    }

public:
    long long minEnd(int n, int x) {
        auto&& bits = toBits(x);
        auto&& insertBits = toBits(n - 1);
        size_t j = 0;
        for (size_t i = 0; i < bits.size() && j < insertBits.size(); i++) {
            if (bits[i] == 0) {
                bits[i] = insertBits[j];
                j++;
            }
        }
        for (; j < insertBits.size(); j++) {
            bits.push_back(insertBits[j]);
        }
        cout << fromBits(bits) << endl;
        return fromBits(bits);
    }
};
