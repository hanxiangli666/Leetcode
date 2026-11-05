// Created by James at 2026/11/05 15:26
// leetgo: 1.5.2
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-05。
// 原题：https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
// 此提交为历史解法迁移，本轮重新练习进度单独记录。

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr) {
            return root;
        }

        if (left != nullptr) {
            return left;
        }

        return right;
    }
};

// @lc code=end

// 本地入口根据题目给出的节点值，在原树中查找对应节点。
TreeNode* findNodeByValue(TreeNode* root, int value) {
    if (root == nullptr || root->val == value) return root;
    TreeNode* left = findNodeByValue(root->left, value);
    return left != nullptr ? left : findNodeByValue(root->right, value);
}

int main() {
	ios_base::sync_with_stdio(false);
	try {
		TreeNode* root = LeetCodeIO::deserialize<TreeNode*>(cin);
		int pValue = LeetCodeIO::deserialize<int>(cin);
		int qValue = LeetCodeIO::deserialize<int>(cin);
		TreeNode* p = findNodeByValue(root, pValue);
		TreeNode* q = findNodeByValue(root, qValue);

		Solution obj;
		auto res = obj.lowestCommonAncestor(root, p, q);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
