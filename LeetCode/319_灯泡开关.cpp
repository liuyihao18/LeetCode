// 319_���ݿ���.cpp
#include "custom.h"
ustd

class Solution {
public:
    int bulbSwitch(int n) {
        /**
        * ��ʵ��Ѱ����ȫƽ����
        * ��n�����ݿ��ش�����n����������
        * ���n������ȫƽ��������n������ż����������������״̬ΪϨ��
        * ��������������״̬Ϊ������n����������������nΪ��ȫƽ����
        */
        return static_cast<int>(floor(sqrt(n)));
    }
};