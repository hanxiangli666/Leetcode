// Created by James at 2026/11/05 15:26
// leetgo: 1.5.2
// https://leetcode.com/problems/diameter-of-binary-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-05。
// 原题：https://leetcode.cn/problems/diameter-of-binary-tree/
// 此提交为历史解法迁移，本轮重新练习进度单独记录。

class Solution {
public:
    int answer = 0;

    int depth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);

        answer = max(answer, leftDepth + rightDepth);

        return max(leftDepth, rightDepth) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        answer = 0;
        depth(root);
        return answer;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		TreeNode* root = LeetCodeIO::deserialize<TreeNode*>(cin);

		Solution obj;
		auto res = obj.diameterOfBinaryTree(root);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
