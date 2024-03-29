// 420_膿畜鷹殊刮匂.cpp
#include "custom.h"
ustd

// TODO: 畠隼やりたくない。
class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = static_cast<int>(password.size());
        bool has_lower = false, has_upper = false, has_digit = false;
        for (char ch : password) {
            if (islower(ch)) {
                has_lower = true;
            }
            else if (isupper(ch)) {
                has_upper = true;
            }
            else if (isdigit(ch)) {
                has_digit = true;
            }
        }
        int categories = has_lower + has_upper + has_digit;

        if (n < 6) {
            return max(6 - n, 3 - categories);
        }
        else if (n <= 20) {
            int replace = 0;
            int cnt = 0;
            char cur = '#';

            for (char ch : password) {
                if (ch == cur) {
                    ++cnt;
                }
                else {
                    replace += cnt / 3;
                    cnt = 1;
                    cur = ch;
                }
            }
            replace += cnt / 3;
            return max(replace, 3 - categories);
        }
        else {
            // 紋算肝方才評茅肝方
            int replace = 0, remove = n - 20;
            // k mod 3 = 1 議怏方��軸評茅 2 倖忖憲辛參受富 1 肝紋算荷恬
            int rm2 = 0;
            int cnt = 0;
            char cur = '#';

            for (char ch : password) {
                if (ch == cur) {
                    ++cnt;
                }
                else {
                    if (remove > 0 && cnt >= 3) {
                        if (cnt % 3 == 0) {
                            // 泌惚頁 k % 3 = 0 議怏��椎担單枠評茅 1 倖忖憲��受富 1 肝紋算荷恬
                            --remove;
                            --replace;
                        }
                        else if (cnt % 3 == 1) {
                            // 泌惚頁 k % 3 = 1 議怏��椎担贋和栖姥喘
                            ++rm2;
                        }
                        // k % 3 = 2 議怏涙俶�塋戎実�
                    }
                    replace += cnt / 3;
                    cnt = 1;
                    cur = ch;
                }
            }
            if (remove > 0 && cnt >= 3) {
                if (cnt % 3 == 0) {
                    --remove;
                    --replace;
                }
                else if (cnt % 3 == 1) {
                    ++rm2;
                }
            }
            replace += cnt / 3;

            // 聞喘 k % 3 = 1 議怏議方楚��喇複噫議紋算肝方、怏方才複噫議評茅肝方慌揖畳協
            int use2 = min({ replace, rm2, remove / 2 });
            replace -= use2;
            remove -= use2 * 2;
            // 喇噐耽嗤匯肝紋算肝方祥匯協嗤 3 倖銭偬�猴�議忖憲��k / 3 畳協����咀緩宸戦辛參岷俊柴麻竃聞喘 k % 3 = 2 議怏議方楚
            int use3 = min({ replace, remove / 3 });
            replace -= use3;
            remove -= use3 * 3;
            return (n - 20) + max(replace, 3 - categories);
        }
    }
};
/*
恬宀��LeetCode - Solution
全俊��https ://leetcode-cn.com/problems/strong-password-checker/solution/qiang-mi-ma-jian-yan-qi-by-leetcode-solu-4fqx/
栖坿�坐�諏��LeetCode��
广恬幡拷恬宀侭嗤。斌匍廬墮萩選狼恬宀資誼娩幡��掲斌匍廬墮萩廣苧竃侃。
*/
