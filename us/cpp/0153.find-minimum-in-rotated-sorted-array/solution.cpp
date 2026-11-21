// Created by James at 2026/11/21 01:52
// leetgo: 1.5.2
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int findMin(vector<int>& nums) {
        // 二分：和最右端比较，判断 mid 在“左高段”还是“右低段”
        int left = 0, right = (int)nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;          // mid 在左高段，最小值一定在右边
            } else {
                right = mid;             // mid 在右低段，mid 可能就是最小值
            }
        }
        return nums[left];
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.findMin(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
