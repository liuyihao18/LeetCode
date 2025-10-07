// 2511_�����Դݻٵĵ��˳Ǳ���Ŀ.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    int captureForts(vector<int>& forts) {
        int pre = -2, post = 2;
        int maxForts = 0, currForts = 0;
        for (auto fort : forts) {
            if (fort != 0) {
                post = fort;
                if (pre == 1 && post == -1 || pre == -1 && post == 1) {
                    maxForts = max(maxForts, currForts);
                }
                currForts = 0;
                pre = fort;
            }
            else {
                currForts++;
            }
        }
        return maxForts;
    }
};
