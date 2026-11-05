// Created by James at 2026/11/05 15:26
// leetgo: 1.5.2
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-05。
// 原题：https://leetcode.cn/problems/kth-smallest-element-in-a-bst/
// 此提交为历史解法迁移，本轮重新练习进度单独记录。

class Solution {
public:
    int count = 0;
    int answer = 0;

    void dfs(TreeNode* node, int k) {
        if (node == nullptr) {
            return;
        }

        dfs(node->left, k);

        count++;

        if (count == k) {
            answer = node->val;
        }

        dfs(node->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return answer;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		TreeNode* root = LeetCodeIO::deserialize<TreeNode*>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.kthSmallest(root, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
