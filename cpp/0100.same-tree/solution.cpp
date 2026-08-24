// Created by James at 2026/08/22 00:26
// leetgo: dev
// https://leetcode.cn/problems/same-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }

        if (p == nullptr || q == nullptr)
        {
            return false;
        }

        if (p->val != q->val)
        {
            return false;
        }

        bool leftSame = isSameTree(p->left, q->left);
        bool rightSame = isSameTree(p->right, q->right);

        return leftSame && rightSame;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	TreeNode* p;
	LeetCodeIO::scan(cin, p);
	TreeNode* q;
	LeetCodeIO::scan(cin, q);

	Solution *obj = new Solution();
	auto res = obj->isSameTree(p, q);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
