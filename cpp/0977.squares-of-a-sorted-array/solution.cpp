// Created by James at 2026/06/28 13:10
// leetgo: dev
// https://leetcode.cn/problems/squares-of-a-sorted-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        int pos = static_cast<int>(nums.size()) - 1;
        vector<int> res(nums.size());

        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare > rightSquare) {
                res[pos] = leftSquare;
                left++;
            } else {
                res[pos] = rightSquare;
                right--;
            }
            pos--;
        }

        return res;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->sortedSquares(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
