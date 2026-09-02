// Created by James at 2026/09/01 21:27
// leetgo: dev
// https://leetcode.cn/problems/diameter-of-binary-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

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
	stringstream out_stream;

	TreeNode* root;
	LeetCodeIO::scan(cin, root);

	Solution *obj = new Solution();
	auto res = obj->diameterOfBinaryTree(root);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
