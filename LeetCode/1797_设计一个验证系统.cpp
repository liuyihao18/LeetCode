// 1797_���һ����֤ϵͳ.cpp
#include "custom.h"
ustd

class AuthenticationManager {
private:
    int timeToLive;
    unordered_map<string, int> mp;
public:
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }

    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime + timeToLive;
    }

    void renew(string tokenId, int currentTime) {
        if (mp.count(tokenId) && mp[tokenId] > currentTime) {
            mp[tokenId] = currentTime + timeToLive;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int res = 0;
        for (auto& [_, time] : mp) {
            if (time > currentTime) {
                res++;
            }
        }
        return res;
    }
};
/*
���ߣ����۹ٷ����
���ӣ�https ://leetcode.cn/problems/design-authentication-manager/solutions/2099432/she-ji-yi-ge-yan-zheng-xi-tong-by-leetco-kqqb/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
