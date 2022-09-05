// 652_寻找重复的子树.cpp
#include "custom.h"
ustd


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
 
/*
class Solution {
    set<int> heights;
    map<int, vector<TreeNode*>> nodes;
    map<int, map<TreeNode*, vector<int>>> preOrders;
    map<int, map<TreeNode*, vector<int>>> inOrders;
    int dfs(TreeNode* root) {
        int leftHeight = 0, rightHeight = 0;
        vector<int> preOrder;
        vector<int> inOrder;
        preOrder.push_back(root->val);
        if (root->left) {
            leftHeight = dfs(root->left);
            copy(preOrders[leftHeight][root->left].begin(), preOrders[leftHeight][root->left].end(), back_inserter(preOrder));
            copy(inOrders[leftHeight][root->left].begin(), inOrders[leftHeight][root->left].end(), back_inserter(inOrder));
            inOrder.push_back(INT_MIN);
        }
        inOrder.push_back(root->val);
        if (root->right) {
            rightHeight = dfs(root->right);
            inOrder.push_back(INT_MAX);
            copy(preOrders[rightHeight][root->right].begin(), preOrders[rightHeight][root->right].end(), back_inserter(preOrder));
            copy(inOrders[rightHeight][root->right].begin(), inOrders[rightHeight][root->right].end(), back_inserter(inOrder));
        }
        int height = max(leftHeight, rightHeight) + 1;
        heights.insert(height);
        preOrders[height][root] = std::move(preOrder);
        inOrders[height][root] = std::move(inOrder);
        nodes[height].push_back(root);
        return height;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        vector<TreeNode*> result;
        for (auto height : heights) {
            auto& n = nodes[height];
            auto& m1 = preOrders[height];
            auto& m2 = inOrders[height];
            set<TreeNode*> visited;
            for (size_t i = 0; i + 1 < n.size(); i++) {
                visited.insert(n[i]);
                bool found = false;
                for (size_t j = i + 1; j < n.size(); j++) {
                    if (!visited.count(n[j])) {
                        if (m1[n[i]] == m1[n[j]] && m2[n[i]] == m2[n[j]]) {
                            if (!found) {
                                result.push_back(n[i]);
                                found = true;
                            }
                            visited.insert(n[j]);
                        }
                    }
                }
            }
        }
        return result;
    }
};
*/

// 太妙了
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return { repeat.begin(), repeat.end() };
    }

    int dfs(TreeNode* node) {
        if (!node) {
            return 0;
        }
        auto tri = tuple{ node->val, dfs(node->left), dfs(node->right) };
        if (auto it = seen.find(tri); it != seen.end()) {
            repeat.insert(it->second.first);
            return it->second.second;
        }
        else {
            seen[tri] = { node, ++idx };
            return idx;
        }
    }

private:
    static constexpr auto tri_hash = [fn = hash<int>()](const tuple<int, int, int>& o)->size_t {
        auto&& [x, y, z] = o;
        return (fn(x) << 24) ^ (fn(y) << 8) ^ fn(z);
    };

    unordered_map<tuple<int, int, int>, pair<TreeNode*, int>, decltype(tri_hash)> seen{ 0, tri_hash };
    unordered_set<TreeNode*> repeat;
    int idx = 0;
};
/*
作者：LeetCode - Solution
链接：https ://leetcode.cn/problems/find-duplicate-subtrees/solution/xun-zhao-zhong-fu-de-zi-shu-by-leetcode-zoncw/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
