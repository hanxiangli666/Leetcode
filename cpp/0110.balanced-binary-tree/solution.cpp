// Created by James at 2026/09/11 22:41
// leetgo: dev
// https://leetcode.cn/problems/balanced-binary-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

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
	stringstream out_stream;

	TreeNode* root;
	LeetCodeIO::scan(cin, root);

	Solution *obj = new Solution();
	auto res = obj->isBalanced(root);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
