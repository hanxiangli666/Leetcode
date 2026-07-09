// Created by James at 2026/07/04 14:02
// leetgo: dev
// https://leetcode.cn/problems/unique-middle-element/
// https://leetcode.cn/contest/biweekly-contest-186/problems/unique-middle-element/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int target = nums[nums.size() / 2];
        int count = 0;
        for (int x : nums) {
            if (x == target) {
                ++count;
            }
        }
        return count == 1;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->isMiddleElementUnique(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
