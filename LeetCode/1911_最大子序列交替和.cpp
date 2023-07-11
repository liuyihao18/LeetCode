// 1911_��������н����.cpp
#include "custom.h"
ustd

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        if (nums.empty()) return 0;
        long long even = nums[0]; // ���һ�����±�Ϊż��ʱ�ĺ�
        long long odd = 0; // ���һ�����±�Ϊ����ʱ�ĺ�
        for (size_t i = 1; i < nums.size(); i++) {
            even = max(even, odd + nums[i]);
            odd = max(odd, even - nums[i]);
        }
        return even;
    }
};

/*
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        /*
        ̰��:
        ��ĿҪ��ż���±�ļ�ȥ�����±�ģ�������Щ�Ǵ�������ȡ�������У�Ҳ����˵����ȡҲ���Բ�ȡ
        ��ô�Ϳ��Կ����ǹ�Ʊ���׵ļ۸�����׬�ľ��ǲ��
        ����̰�ĵ��ռ�ÿһ���ܹ������Ľ��׾��Ǵ�
        ����:nums = [6,2,1,2,4,5] ���ǿ��Դ����nums = [0,6,2,1,2,4,5]
        �ڲ����ƹ�Ʊ���״���(�����зָ����ȿ��Ե�1)������£����ǿ��Խ�����������С�����ռ�ÿ���ܹ������ĸ��콻��
         */
        /*
        long res = 0;
        int pre = 0;    // ǰһ��۸�
        for (int num : nums) {
            // 1.�����������׬Ǯ
            if (num > pre) res += num - pre;
            // 2.��������첻��׬Ǯ���߿�Ǯ�Ͳ�������
            // ������һ�ֵ����ռ۸�
            pre = num;
        }
        return res;
    }
};
 */
