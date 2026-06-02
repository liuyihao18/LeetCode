// 1161_最大层内元素和.cpp
#include "stdafx.h"
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

class Solution {
    int levelSum(queue<TreeNode*>& inQueue, queue<TreeNode*>& outQueue)
    {
        int sum = 0;
        while (!inQueue.empty())
        {
            const TreeNode* currNode = inQueue.front();
            inQueue.pop();
            sum += currNode->val;
            if (currNode->left)
            {
                outQueue.push(currNode->left);
            }
            if (currNode->right)
            {
                outQueue.push(currNode->right);
            }
        }
        return sum;
    }
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int maxSumLevelId = -1;
    	queue<TreeNode*> inQueue, outQueue;
        inQueue.push(root);
        int currLevelId = 1;
        while (!inQueue.empty())
        {
	        if (const int currSum = levelSum(inQueue, outQueue); 
                currSum > maxSum)
            {
                maxSum = currSum;
                maxSumLevelId = currLevelId;
            }
            currLevelId++;
            swap(inQueue, outQueue);
        }
        return maxSumLevelId;
    }
};

/*
class Solution {
    struct State {
        TreeNode* node;
        int level;
        State(TreeNode* node, int level) : node(node), level(level) {}
    };
public:
    int maxLevelSum(TreeNode* root) {
        queue<State> q;
        q.emplace(root, 1);
        int maxSum = INT_MIN;
        int sum = 0;
        int maxSumLevel = 1;
        int currLevel = 1;
        while (!q.empty()) {
            State curr = q.front();
            q.pop();
            if (curr.level > currLevel) {
                if (sum > maxSum) {
                    maxSum = sum;
                    maxSumLevel = currLevel;
                }
                sum = 0;
                currLevel = curr.level;
            }
            sum += curr.node->val;
            if (curr.node->left) {
                q.emplace(curr.node->left, curr.level + 1);
            }
            if (curr.node->right) {
                q.emplace(curr.node->right, curr.level + 1);
            }
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxSumLevel = currLevel;
        }
        return maxSumLevel;
    }
};
*/
