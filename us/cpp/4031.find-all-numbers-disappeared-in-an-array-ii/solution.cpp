// Created by James at 2026/11/07 10:48
// leetgo: 1.5.2
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array-ii/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/744019095/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(
        vector<int>& nums,
        int lower,
        int upper
    ) {
        vector<bool> present(upper - lower + 1, false);

        for (int number : nums) {
            if (number >= lower && number <= upper) {
                present[number - lower] = true;
            }
        }
        vector<vector<int>> answer;
        int number = lower;

        while (number <= upper) {
            if (present[number - lower]) {
                ++number;
                continue;
            }

            int start = number;

            while (number <= upper &&
                   !present[number - lower]) {
                ++number;
            }

            answer.push_back({start, number - 1});
        }

        return answer;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		int lower = LeetCodeIO::deserialize<int>(cin);
		int upper = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.findDisappearedNumbers(nums, lower, upper);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
