// 3093_最长公共后缀查询.cpp
#include "stdafx.h"
ustd

/** 
 * 随机爆内存，vector<shared_ptr<Node>> 的存储效率还是不如纯指针数组
 */

struct Node {
	string_view str;
	size_t index;
	vector<shared_ptr<Node>> children;
	Node() : index(-1), children(26) {}
	void build()
	{
		size_t len = str.empty() ? INT_MAX : str.size();
		for (const shared_ptr<Node>& node : children)
		{
			if (node)
			{
				node->build();
				if (node->str.size() < len || node->str.size() == len && node->index < index)
				{
					str = node->str;
					len = str.size();
					index = node->index;
				}
			}
		}
	}
};

class Trie {
public:
	Trie() : root(new Node) {}
	void insert(const string_view str, const size_t index) const
	{
		shared_ptr<Node> curr = root;
		for (const char c : views::reverse(str))
		{
			if (curr->children[c - 'a'] == nullptr)
			{
				curr->children[c - 'a'] = make_shared<Node>();
			}
			curr = curr->children[c - 'a'];
		}
		curr->str = str;
		curr->index = min(curr->index, index);
	}
	void build() const
	{
		root->build();
	}
	size_t find(const string_view str) const
	{
		shared_ptr<Node> curr = root;
		for (const char c : views::reverse(str))
		{
			if (curr->children[c - 'a'] == nullptr)
			{
				return curr->index;
			}
			curr = curr->children[c - 'a'];
		}
		return curr->index;
	}
private:
	shared_ptr<Node> root;
};

class Solution {
public:
	vector<int> stringIndices(const vector<string>& wordsContainer, const vector<string>& wordsQuery) {
		const Trie trie;
		for (size_t i = 0, n = wordsContainer.size(); i < n; i++)
		{
			trie.insert(wordsContainer[i], i);
		}
		trie.build();
		vector<int> result(wordsQuery.size());
		for (size_t i = 0, n = wordsQuery.size(); i < n; i++)
		{
			result[i] = static_cast<int>(trie.find(wordsQuery[i]));
		}
		return result;
	}
};
