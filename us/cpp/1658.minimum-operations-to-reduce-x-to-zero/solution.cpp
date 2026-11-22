// Created by James at 2026/11/22 07:43
// leetgo: 1.5.2
// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // 换个说法：两头拿走的和 = x  <=>  中间留下的一段和 = total - x
        // 要拿得最少 = 中间留下的那段最长。正数数组，用滑动窗口找和正好为 target 的最长一段
        int total = 0;
        for (int v : nums) total += v;
        int target = total - x;
        if (target < 0) return -1;
        int n = nums.size(), left = 0, sum = 0, best = -1;
        for (int right = 0; right < n; ++right) {
            sum += nums[right];                 // 窗口右边拉长
            while (sum > target) {              // 太大了，左边收短
                sum -= nums[left];
                ++left;
            }
            if (sum == target) best = max(best, right - left + 1);
        }
        return best == -1 ? -1 : n - best;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		int x = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.minOperations(nums, x);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
