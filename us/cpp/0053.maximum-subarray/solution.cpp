// Created by James at 2026/11/05 15:26
// leetgo: 1.5.2
// https://leetcode.com/problems/maximum-subarray/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-05。
// 原题：https://leetcode.cn/problems/maximum-subarray/
// 此提交为历史解法迁移，本轮重新练习进度单独记录。

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int current = nums[0];
        int best = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            current = max(nums[i], current + nums[i]);
            best = max(best, current);
        }

        return best;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.maxSubArray(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
