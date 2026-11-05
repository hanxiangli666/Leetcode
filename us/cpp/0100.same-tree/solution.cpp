// Created by James at 2026/11/05 15:26
// leetgo: 1.5.2
// https://leetcode.com/problems/same-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-05。
// 原题：https://leetcode.cn/problems/same-tree/
// 此提交为历史解法迁移，本轮重新练习进度单独记录。

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
	try {
		TreeNode* p = LeetCodeIO::deserialize<TreeNode*>(cin);
		TreeNode* q = LeetCodeIO::deserialize<TreeNode*>(cin);

		Solution obj;
		auto res = obj.isSameTree(p, q);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
