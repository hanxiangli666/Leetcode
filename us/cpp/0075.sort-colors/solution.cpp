// Created by James at 2026/11/09 23:40
// leetgo: 1.5.2
// https://leetcode.com/problems/sort-colors/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0;
        int i = 0;
        int p2 = static_cast<int>(nums.size()) - 1;

        while (i <= p2) {
            if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                ++p0;
                ++i;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[p2]);
                --p2;
            } else {
                ++i;
            }
        }
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		obj.sortColors(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, nums);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
