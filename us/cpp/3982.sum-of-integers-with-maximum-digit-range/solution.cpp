// Created by James at 2026/11/07 10:48
// leetgo: 1.5.2
// https://leetcode.com/problems/sum-of-integers-with-maximum-digit-range/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/sum-of-integers-with-maximum-digit-range/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/734135173/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution {
public:
    int digitRange(int x) {
        int mn = 9, mx = 0;

        while (x > 0) {
            int d = x % 10;
            mn = min(mn, d);
            mx = max(mx, d);
            x /= 10;
        }

        return mx - mn;
    }

    int maxDigitRange(vector<int>& nums) {
        int bestRange = -1;
        int ans = 0;

        for (int x : nums) {
            int r = digitRange(x);

            if (r > bestRange) {
                bestRange = r;
                ans = x;
            } else if (r == bestRange) {
                ans += x;
            }
        }

        return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.maxDigitRange(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
