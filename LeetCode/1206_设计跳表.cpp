// 1206_�������.cpp
#include "stdafx.h"
#include <random>
ustd

constexpr int MAX_LEVEL = 32;
constexpr double P_FACTOR = 0.25;

struct SkiplistNode {
    int val;
    vector<SkiplistNode*> forward;
    SkiplistNode(int _val, int _maxLevel = MAX_LEVEL) : val(_val), forward(_maxLevel, nullptr) {

    }
};

class Skiplist {
private:
    SkiplistNode* head;
    int level;
    mt19937 gen{ random_device{}() };
    uniform_real_distribution<double> dis;

public:
    Skiplist() : head(new SkiplistNode(-1)), level(0), dis(0, 1) {

    }

    bool search(int target) {
        SkiplistNode* curr = this->head;
        for (int i = level - 1; i >= 0; i--) {
            /* �ҵ��� i ��С������ӽ� target ��Ԫ��*/
            while (curr->forward[i] && curr->forward[i]->val < target) {
                curr = curr->forward[i];
            }
        }
        curr = curr->forward[0];
        /* ��⵱ǰԪ�ص�ֵ�Ƿ���� target */
        if (curr && curr->val == target) {
            return true;
        }
        return false;
    }

    void add(int num) {
        vector<SkiplistNode*> update(MAX_LEVEL, head);
        SkiplistNode* curr = this->head;
        for (int i = level - 1; i >= 0; i--) {
            /* �ҵ��� i ��С������ӽ� num ��Ԫ��*/
            while (curr->forward[i] && curr->forward[i]->val < num) {
                curr = curr->forward[i];
            }
            update[i] = curr;
        }
        int lv = randomLevel();
        level = max(level, lv);
        SkiplistNode* newNode = new SkiplistNode(num, lv);
        for (int i = 0; i < lv; i++) {
            /* �Ե� i ���״̬���и��£�����ǰԪ�ص� forward ָ���µĽڵ� */
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }

    bool erase(int num) {
        vector<SkiplistNode*> update(MAX_LEVEL, nullptr);
        SkiplistNode* curr = this->head;
        for (int i = level - 1; i >= 0; i--) {
            /* �ҵ��� i ��С������ӽ� num ��Ԫ��*/
            while (curr->forward[i] && curr->forward[i]->val < num) {
                curr = curr->forward[i];
            }
            update[i] = curr;
        }
        curr = curr->forward[0];
        /* ���ֵ�������򷵻� false */
        if (!curr || curr->val != num) {
            return false;
        }
        for (int i = 0; i < level; i++) {
            if (update[i]->forward[i] != curr) {
                break;
            }
            /* �Ե� i ���״̬���и��£��� forward ָ��ɾ���ڵ����һ�� */
            update[i]->forward[i] = curr->forward[i];
        }
        delete curr;
        /* ���µ�ǰ�� level */
        while (level > 1 && head->forward[static_cast<size_t>(level) - 1] == nullptr) {
            level--;
        }
        return true;
    }

    int randomLevel() {
        int lv = 1;
        /* ������� lv */
        while (dis(gen) < P_FACTOR && lv < MAX_LEVEL) {
            lv++;
        }
        return lv;
    }
};
/*
���ߣ�LeetCode - Solution
���ӣ�https ://leetcode.cn/problems/design-skiplist/solution/she-ji-tiao-biao-by-leetcode-solution-e8yh/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/
