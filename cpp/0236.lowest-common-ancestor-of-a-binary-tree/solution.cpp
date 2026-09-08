// Created by James at 2026/09/08 15:12
// leetgo: dev
// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

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

TreeNode* findNodeByValue(TreeNode* root, int target) {
	if (root == nullptr || root->val == target) {
		return root;
	}

	TreeNode* left = findNodeByValue(root->left, target);
	if (left != nullptr) {
		return left;
	}

	return findNodeByValue(root->right, target);
}

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	TreeNode* root;
	LeetCodeIO::scan(cin, root);
	int pValue;
	LeetCodeIO::scan(cin, pValue);
	int qValue;
	LeetCodeIO::scan(cin, qValue);

	TreeNode* p = findNodeByValue(root, pValue);
	TreeNode* q = findNodeByValue(root, qValue);

	Solution *obj = new Solution();
	auto res = obj->lowestCommonAncestor(root, p, q);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
