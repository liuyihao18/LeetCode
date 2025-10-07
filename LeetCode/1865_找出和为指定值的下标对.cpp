// 1865_找出和为指定值的下标对.cpp
#include "stdafx.h"
ustd

class FindSumPairs {
	vector<int> nums1, nums2;
    unordered_map<int, int> cnts2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums1(nums1), nums2(nums2) {
        for (int num2 : nums2) {
            cnts2[num2]++;
        }
    }

    void add(int index, int val) {
        if (--cnts2[nums2[index]] == 0) {
			cnts2.erase(nums2[index]);
        }
        nums2[index] += val;
		cnts2[nums2[index]]++;
    }

    int count(int tot) {
        int ans = 0;
        for (int num1 : nums1) {
            if (cnts2.count(tot - num1)) {
                ans += cnts2[tot - num1];
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

