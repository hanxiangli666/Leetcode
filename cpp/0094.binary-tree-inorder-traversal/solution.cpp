// Created by James at 2026/07/18 22:11
// leetgo: dev
// https://leetcode.cn/problems/binary-tree-inorder-traversal/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution
{
private:
    void traverse(TreeNode* node, vector<int>& result)
    {
        if (node == nullptr)
        {
            return;
        }

        traverse(node->left, result);
        result.push_back(node->val);
        traverse(node->right, result);
    }

public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> result;
        traverse(root, result);
        return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	TreeNode* root;
	LeetCodeIO::scan(cin, root);

	Solution *obj = new Solution();
	auto res = obj->inorderTraversal(root);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
