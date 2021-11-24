// 423_英文中重建数字.cpp
#include "custom.h"
ustd

constexpr size_t INDEX(char c) {
    return static_cast<size_t>(c);
}

#ifdef DFS
const string num2str[] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};
#endif // DFS

class Solution {
#ifdef DFS
    bool contains(const vector<size_t>& counts, int num) {
        vector<size_t> _counts(128, 0);
        for (auto c : num2str[num]) {
            _counts[INDEX(c)]++;
        }
        bool found = true;
        for (size_t i = 0; i < counts.size(); i++) {
            if (_counts[i] > counts[i]) {
                found = false;
                break;
            }
        }
        return found;
    }
    void erase(vector<size_t>& counts, int num) {
        for (auto c : num2str[num]) {
            counts[INDEX(c)]--;
        }
    }
    void restore(vector<size_t>& counts, int num) {
        for (auto c : num2str[num]) {
            counts[INDEX(c)]++;
        }
    }
    bool dfs(vector<size_t>& counts, vector<size_t>& nums) {
        if (accumulate(counts.begin(), counts.end(), 0) == 0) {
            return true;
        }
        for (int i = 0; i < 10; i++) {
            if (counts[INDEX(num2str[i][0])] == 0) {
                continue;
            }
            if (contains(counts, i)) {
                erase(counts, i);
                nums[i]++;
                if (dfs(counts, nums)) {
                    return true;
                }
                nums[i]--;
                restore(counts, i);
            }
        }
        return false;
    }
#endif // DFS
public:
    string originalDigits(const string& s) {
        vector<size_t> counts(128, 0);
        for (auto c : s) {
            counts[INDEX(c)]++;
        }
        vector<size_t> nums(10, 0);
#ifdef DFS
        dfs(counts, nums);
#endif // DFS
        nums[8] = counts[INDEX('g')];
        nums[4] = counts[INDEX('u')];
        nums[2] = counts[INDEX('w')];
        nums[6] = counts[INDEX('x')];
        nums[0] = counts[INDEX('z')];
        nums[5] = counts[INDEX('f')] - nums[4];
        nums[3] = counts[INDEX('h')] - nums[8];
        nums[7] = counts[INDEX('s')] - nums[6];
        nums[1] = counts[INDEX('o')] - nums[0] - nums[2] - nums[4];
        nums[9] = counts[INDEX('i')] - nums[5] - nums[6] - nums[8];
        string result;
        for (size_t i = 0; i < nums.size(); i++) {
            string temp;
            for (size_t j = 0; j < nums[i]; j++) {
                temp += to_string(i);
            }
            result += temp;
        }
        return result;
    }
};
