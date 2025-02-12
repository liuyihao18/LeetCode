// 128_���������.cpp
#include "custom.h"
ustd

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        for (int num : nums) {
            us.insert(num);
        }

        // ������visited��Ϊunorder_set������ģ����Բ����Ǵ�С�������
        // unordered_set<int> visited;

        int maxLen = 0;
        for (int num : us) {
            if (!us.count(num - 1)) {
                int len = 1;

                while (us.count(num + 1)) {
                    num++;
                    len++;
                }

                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};
