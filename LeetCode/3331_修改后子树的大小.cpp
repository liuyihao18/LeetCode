// 3331_修改后子树的大小.cpp
#include "stdafx.h"
ustd

class Solution 
{
    long long combine(const int index, const char c)
    {
        return static_cast<long long>(static_cast<unsigned>(index))
            | static_cast<long long>(c) << 32;
    }

    pair<int, char> split(const long long request)
    {
        return
        {
            static_cast<int>(request & 0xffffffff),
            static_cast<char>(request >> 32)
        };
    }

    int findNearestAncestor(const vector<int>& parent, const string& s,
        const long long request, unordered_map<long long, int>& nearestAncesotr)
    {
        if (nearestAncesotr.contains(request))
        {
            return nearestAncesotr[request];
        }

        auto [index, c] = split(request);
        if (index == -1)
        {
            return -1;
        }

        if (s[index] == c)
        {
            nearestAncesotr[request] = index;
            return index;
        }
        else
        {
            long long parentRequest = combine(parent[index], c);
            const int parentNearestAncestor = findNearestAncestor(parent, s, parentRequest, nearestAncesotr);
            nearestAncesotr[request] = parentNearestAncestor;
            return parentNearestAncestor;
        }        
    }

    int calculateTreeSize(const vector<vector<int>>& children, int root, vector<int>& outTreeSize)
    {
        if (outTreeSize[root] > 0)
        {
            return outTreeSize[root];
        }
        if (children[root].size() == 0)
        {
            outTreeSize[root] = 1;
            return outTreeSize[root];
        }
        int treeSize = 1;
        for (int child : children[root])
        {
            treeSize += calculateTreeSize(children, child, outTreeSize);
        }
        outTreeSize[root] = treeSize;
        return outTreeSize[root];
    }

public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) 
    {
        const int n = static_cast<int>(parent.size());
        unordered_map<long long, int> nearestAncestor;
        int root = -1;
        vector<vector<int>> newChildren(n);
        for (int i = 0; i < n; i++) 
        {
            long long selfRequest = combine(i, s[i]);
            nearestAncestor[selfRequest] = i;
            if (parent[i] == -1) 
            {
                root = i;
                continue;
            }
            long long parentRequest = combine(parent[i], s[i]);
            if (const int nearastAncestor = findNearestAncestor(parent, s, parentRequest, nearestAncestor);
                nearastAncestor != -1)
            {
                newChildren[nearastAncestor].push_back(i);
            }
            else 
            {
                newChildren[parent[i]].push_back(i);
            }
        }
        vector<int> treeSize(n);
        calculateTreeSize(newChildren, root, treeSize);
        return treeSize;
    }
};
