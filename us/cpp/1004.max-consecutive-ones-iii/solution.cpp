// Created by James at 2026/11/21 01:52
// leetgo: 1.5.2
// https://leetcode.com/problems/max-consecutive-ones-iii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // 滑动窗口：窗口内 0 的个数不超过 k，就是一段“翻转后全 1”的子数组
        int left = 0, zeros = 0, best = 0;
        for (int right = 0; right < (int)nums.size(); ++right) {
            if (nums[right] == 0) ++zeros;          // 扩大窗口
            while (zeros > k) {                      // 不合法就收缩左边
                if (nums[left] == 0) --zeros;
                ++left;
            }
            best = max(best, right - left + 1);      // 每个合法窗口都更新答案
        }
        return best;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.longestOnes(nums, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
