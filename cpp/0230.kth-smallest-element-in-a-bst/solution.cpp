// Created by James at 2026/09/07 12:15
// leetgo: dev
// https://leetcode.cn/problems/kth-smallest-element-in-a-bst/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

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
	stringstream out_stream;

	TreeNode* root;
	LeetCodeIO::scan(cin, root);
	int k;
	LeetCodeIO::scan(cin, k);

	Solution *obj = new Solution();
	auto res = obj->kthSmallest(root, k);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
