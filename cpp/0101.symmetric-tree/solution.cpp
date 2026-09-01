// Created by James at 2026/08/31 21:59
// leetgo: dev
// https://leetcode.cn/problems/symmetric-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool check(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }

        if (p == nullptr || q == nullptr) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        return check(p->left, q->right) &&
               check(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        return check(root->left, root->right);
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	TreeNode* root;
	LeetCodeIO::scan(cin, root);

	Solution *obj = new Solution();
	auto res = obj->isSymmetric(root);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
