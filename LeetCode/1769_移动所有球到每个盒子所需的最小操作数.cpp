// 1769_�ƶ�������ÿ�������������С������.cpp
#include "stdafx.h"
ustd

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> answer(boxes.size(), 0);
        for (int i = 0; i < static_cast<int>(boxes.size()); i++) {
            int temp = 0;
            for (int j = 0; j < static_cast<int>(boxes.size()); j++) {
                temp += (boxes[j] - '0') * abs(j - i);
            }
            answer[i] = temp;
        }
        return answer;
    }
};
