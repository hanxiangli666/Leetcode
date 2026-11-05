// Created by James at 2026/11/05 15:26
// leetgo: 1.5.2
// https://leetcode.com/problems/binary-tree-right-side-view/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-05。
// 原题：https://leetcode.cn/problems/binary-tree-right-side-view/
// 此提交为历史解法迁移，本轮重新练习进度单独记录。

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
	try {
		TreeNode* root = LeetCodeIO::deserialize<TreeNode*>(cin);

		Solution obj;
		auto res = obj.rightSideView(root);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
