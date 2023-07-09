// 15_三数之和.cpp
#include "custom.h"
ustd

/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, vector<size_t>> m;
        for (size_t i = 0; i < nums.size(); i++) {
            m[nums[i]].push_back(i);
        }
        set<vector<int>> s;
        for (size_t i = 0; i + 1 < nums.size(); i++) {
            for (size_t j = i + 1; j < nums.size(); j++) {
                vector<int> temp = { nums[i], nums[j], 0 - nums[i] - nums[j] };
                sort(temp.begin(), temp.end());
                if (s.count(temp)) {
                    continue;
                }
                if (m.count(0 - nums[i] - nums[j])) {
                    const auto& indices = m[0 - nums[i] - nums[j]];
                    for (size_t index : indices) {
                        if (index != i && index != j) {
                            s.insert(temp);
                            break;
                        }
                    }
                }
            }
        }
        return vector<vector<int>>(s.begin(), s.end());
    }
};
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 枚举 a
        for (int first = 0; first < n; ++first) {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // c 对应的指针初始指向数组的最右端
            int third = n - 1;
            int target = -nums[first];
            // 枚举 b
            for (int second = first + 1; second < n; ++second) {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                // 需要保证 b 的指针在 c 的指针的左侧
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({ nums[first], nums[second], nums[third] });
                }
            }
        }
        return ans;
    }
};
/*
作者：力扣官方题解
链接：https ://leetcode.cn/problems/3sum/solutions/284681/san-shu-zhi-he-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
