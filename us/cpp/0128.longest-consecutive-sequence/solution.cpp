// Created by James at 2026/11/05 15:26
// leetgo: 1.5.2
// https://leetcode.com/problems/longest-consecutive-sequence/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-05。
// 原题：https://leetcode.cn/problems/longest-consecutive-sequence/
// 此提交为历史解法迁移，本轮重新练习进度单独记录。

class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> numbers(nums.begin(), nums.end());
        int longest = 0;

        for (int value : numbers)
        {
            if (!numbers.count(value - 1))
            {
                int current = value;
                int length = 1;

                while (numbers.count(current + 1))
                {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.longestConsecutive(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
