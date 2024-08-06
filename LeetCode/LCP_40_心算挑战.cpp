// LCP_40_–ƒÀ„ÃÙ’Ω.cpp
#include "custom.h"
ustd

class Solution {
    bool _maxmiumScore(vector<int>& cards, size_t i, int cnt, int& sum) {
        if (cnt == 0) {
            return sum % 2 == 0;
        }
        sum += cards[i];
        cout << "Choose " << cards[i] << endl;
        for (size_t j = 1; i + j + cnt <= cards.size() + 1; j++) {
            if (_maxmiumScore(cards, i + j, cnt - 1, sum)) {
                return true;
            }
        }
        sum -= cards[i];
        cout << "Delete " << cards[i] << endl;
        return false;
    }
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        sort(cards.begin(), cards.end(), greater<>());
        int maxSum = 0;
        for (size_t i = 0; i + cnt <= cards.size(); i++) {
            int sum = 0;
            if (_maxmiumScore(cards, i, cnt, sum)) {
                maxSum = max(sum, maxSum);
                cout << "Sum " << sum << endl;
            }
            cout << "-------------------" << endl;
        }
        return maxSum;
    }
};

class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        sort(cards.begin(), cards.end(), greater<>());
        int sum = accumulate(cards.begin(), cards.begin() + cnt, 0);
        if (sum % 2 == 0) {
            return sum;
        }
        auto minOdd = find_if(vector<int>::reverse_iterator(cards.begin() + cnt), cards.rend(),
            [](int a) {
                return a % 2 != 0;
            }
        );
        auto minEven = find_if(vector<int>::reverse_iterator(cards.begin() + cnt), cards.rend(),
            [](int a) {
                return a % 2 == 0;
            }
        );
        auto maxOdd = find_if(cards.begin() + cnt, cards.end(),
            [](int a) {
                return a % 2 != 0;
            }
        );
        auto maxEven = find_if(cards.begin() + cnt, cards.end(),
            [](int a) {
                return a % 2 == 0;
            }
        );
        int res = 0;
        if (minOdd != cards.rend() && maxEven != cards.end()) {
            res = sum - *minOdd + *maxEven;
        }
        if (minEven != cards.rend() && maxOdd != cards.end()) {
            res = max(res, sum - *minEven + *maxOdd);
        }
        return res;
    }
};
