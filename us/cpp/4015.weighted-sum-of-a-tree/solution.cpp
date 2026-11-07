// Created by James at 2026/11/07 10:48
// leetgo: 1.5.2
// https://leetcode.com/problems/weighted-sum-of-a-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/weighted-sum-of-a-tree/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/741017421/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int node = 1; node < n; ++node) {
            children[parent[node]].push_back(node);
        }
        vector<int> depth(n);
        
        queue<int> q;

        depth[0] = 1;
        
        q.push(0);

        int height = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            height = max(height, depth[node]);

            for (int child : children[node]) {
                depth[child] = depth[node] + 1;
                q.push(child);
            }
        }
        long long ans = 0;

        for (int node = 0; node < n; ++node) {
            ans += 1LL * nums[node]
                   * (height - depth[node] + 1);
        }

        return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> parent = LeetCodeIO::deserialize<vector<int>>(cin);
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.weightedSum(parent, nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
