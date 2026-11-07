// Created by James at 2026/11/07 10:48
// leetgo: 1.5.2
// https://leetcode.com/problems/maximum-valid-pair-sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/maximum-valid-pair-sum/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/734117613/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        vector<int> mavontelia = nums;

        int n = mavontelia.size();
        int bestLeft = 0;
        int ans = 0;

        for (int j = k; j < n; j++) {
            bestLeft = max(bestLeft, mavontelia[j - k]);
            ans = max(ans, bestLeft + mavontelia[j]);
        }
        return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.maxValidPairSum(nums, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
