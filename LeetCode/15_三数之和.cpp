// 15_����֮��.cpp
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
        // ö�� a
        for (int first = 0; first < n; ++first) {
            // ��Ҫ����һ��ö�ٵ�������ͬ
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // c ��Ӧ��ָ���ʼָ����������Ҷ�
            int third = n - 1;
            int target = -nums[first];
            // ö�� b
            for (int second = first + 1; second < n; ++second) {
                // ��Ҫ����һ��ö�ٵ�������ͬ
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                // ��Ҫ��֤ b ��ָ���� c ��ָ������
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                // ���ָ���غϣ����� b ����������
                // �Ͳ��������� a+b+c=0 ���� b<c �� c �ˣ������˳�ѭ��
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
���ߣ����۹ٷ����
���ӣ�https ://leetcode.cn/problems/3sum/solutions/284681/san-shu-zhi-he-by-leetcode-solution/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
