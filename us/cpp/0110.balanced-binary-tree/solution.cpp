// Created by James at 2026/11/05 15:26
// leetgo: 1.5.2
// https://leetcode.com/problems/balanced-binary-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-05。
// 原题：https://leetcode.cn/problems/balanced-binary-tree/
// 此提交为历史解法迁移，本轮重新练习进度单独记录。

class Solution {
public:
    int checkHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = checkHeight(node->left);
        int rightHeight = checkHeight(node->right);

        // 任意子树已经不平衡
        if (leftHeight == -1 || rightHeight == -1) {
            return -1;
        }

        // 当前节点的左右子树高度差超过 1
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        // 当前子树平衡，返回它的高度
        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		TreeNode* root = LeetCodeIO::deserialize<TreeNode*>(cin);

		Solution obj;
		auto res = obj.isBalanced(root);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
