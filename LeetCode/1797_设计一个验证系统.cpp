// 1797_设计一个验证系统.cpp
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
作者：力扣官方题解
链接：https ://leetcode.cn/problems/design-authentication-manager/solutions/2099432/she-ji-yi-ge-yan-zheng-xi-tong-by-leetco-kqqb/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
