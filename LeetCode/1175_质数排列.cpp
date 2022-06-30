// 1175_ÖÊÊıÅÅÁĞ.cpp
#include "custom.h"
ustd

const int primes[] = { 
    2, 3, 5, 7, 
    11, 13, 17, 19,
    23, 29,
    31, 37,
    41, 43, 47,
    53, 59,
    61, 67, 
    71, 73, 79,
    83, 89,
    97
};

class Solution {
public:
    int numPrimeArrangements(int n) {
        long long nPrime = distance(begin(primes), upper_bound(begin(primes), end(primes), n));
        long long remainder = 1000000007;
        long long result = 1;
        for (long long i = nPrime; i > 1; i--) {
            result = (result * i) % remainder;
        }
        for (long long i = n - nPrime; i > 1; i--) {
            result = (result * i) % remainder;
        }
        return static_cast<int>(result);
    }
};
