// Created by James at 2026/09/03 22:25
// leetgo: dev
// https://leetcode.cn/problems/binary-tree-right-side-view/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;

        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            int levelSize = nodes.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = nodes.front();
                nodes.pop();

                if (i == levelSize - 1) {
                    result.push_back(current->val);
                }

                if (current->left != nullptr) {
                    nodes.push(current->left);
                }

                if (current->right != nullptr) {
                    nodes.push(current->right);
                }
            }
        }

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
	auto res = obj->rightSideView(root);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
