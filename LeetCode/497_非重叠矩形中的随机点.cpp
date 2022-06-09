// 497_���ص������е������.cpp
#include "custom.h"
#include <random>
ustd

/*
* ����д��ȡ����ʲ���ƽ����Ӧ��ֻʹ��һ��������ȷֲ���Ȼ������ӳ�䵽��������Ӧ�ĵ�
class Solution {
    mt19937 gen{ random_device{}()};
    uniform_int_distribution<int> areaDis;
    const vector<vector<int>>& rects;
    vector<int> areaSums;
public:
    Solution(const vector<vector<int>>& rects) :rects(rects) {
        for (const auto& rect : rects) {
            if (areaSums.empty()) {
                areaSums.push_back((rect[2] - rect[0]) * (rect[3] - rect[1]));
            }
            else {
                areaSums.push_back(areaSums.back() + (rect[2] - rect[0]) * (rect[3] - rect[1]));
            }
        }
        areaDis = uniform_int_distribution(0, areaSums.back());
    }

    vector<int> pick() {
        int areaSum = areaDis(gen);
        int i = distance(areaSums.begin(), lower_bound(areaSums.begin(), areaSums.end(), areaSum));
        const auto& rect = rects[i];
        uniform_int_distribution<int> xDis(rect[0], rect[2]);
        uniform_int_distribution<int> yDis(rect[1], rect[3]);
        return { xDis(gen), yDis(gen) };
    }
};
*/

class Solution {
public:
    Solution(vector<vector<int>>& rects) : rects{ rects } {
        this->arr.emplace_back(0);
        for (auto& rect : rects) {
            this->arr.emplace_back(arr.back() + (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1));
        }
    }

    vector<int> pick() {
        uniform_int_distribution<int> dis(0, arr.back() - 1);
        int k = dis(gen) % arr.back();
        int rectIndex = static_cast<int>(upper_bound(arr.begin(), arr.end(), k) - arr.begin() - 1);
        k = k - arr[rectIndex];
        int a = rects[rectIndex][0], b = rects[rectIndex][1];
        int y = rects[rectIndex][3];
        int col = y - b + 1;
        int da = k / col;
        int db = k - col * da;
        return { a + da, b + db };
    }
private:
    vector<int> arr;
    vector<vector<int>>& rects;
    mt19937 gen{ random_device{}() };
};
/*
���ߣ�LeetCode-Solution
���ӣ�https://leetcode.cn/problems/random-point-in-non-overlapping-rectangles/solution/fei-zhong-die-ju-xing-zhong-de-sui-ji-di-6s33/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
