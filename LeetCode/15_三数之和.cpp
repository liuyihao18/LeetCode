// 15_����֮��.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        size_t n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (size_t i = 0; i + 2 < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int num1 = nums[i];
            /* ʹ��˫ָ�룬���Ӷ�O(n^2) */
            size_t j = i + 1, k = n - 1;
            while (j < k) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    j++;
                    continue;
                }
                int num2 = nums[j], num3 = nums[k];
                if (num1 + num2 + num3 == 0) {
                    ans.push_back({ num1, num2, num3 });
                    j++;
                    k--;
                }
                else if (num1 + num2 + num3 < 0) {
                    j++;
                }
                else {
                    k--;
                }
            }
            /* ʹ�ö��ֲ��ң����Ӷ�O(n^2 logn)
            for (size_t j = i + 1; j + 1 < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int num2 = nums[j];
                int num3 = -num1 - num2;
                auto iter = lower_bound(nums.begin() + j + 1, nums.end(), num3);
                if (iter != nums.end() && *iter == num3) {
                    ans.push_back({ num1, num2, num3 });
                }
            }
            */
        }
        return ans;
    }
};

/*
class Solution {
private:
    long long hash(long long a, long long b, long long c) {
        return a << 40 | b << 20 | c;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        size_t n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<long long, vector<int>> ans;
        for (size_t i = 0; i + 2 < n; i++) {
            int num1 = nums[i];
            for (size_t j = i + 1; j + 1 < n; j++) {
                int num2 = nums[j];
                int num3 = -num1 - num2;
                auto iter = lower_bound(nums.begin() + j + 1, nums.end(), num3);
                if (iter != nums.end() && *iter == num3 && !ans.count(hash(num1, num2, num3))) {
                    ans[hash(num1, num2, num3)] = { num1, num2, num3 };
                }
            }
        }
        // ��ans��value����vector
        vector<vector<int>> result;
        for (const auto& [key, value] : ans) {
            result.push_back(value);
        }
        return result;
    }
};
*/

/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        size_t n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // ö�� a
        for (size_t first = 0; first < n; ++first) {
            // ��Ҫ����һ��ö�ٵ�������ͬ
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // c ��Ӧ��ָ���ʼָ����������Ҷ�
            size_t third = n - 1;
            int target = -nums[first];
            // ö�� b
            for (size_t second = first + 1; second < n; ++second) {
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
