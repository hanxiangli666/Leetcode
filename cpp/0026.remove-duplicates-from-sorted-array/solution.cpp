// Created by James at 2026/09/12 16:43
// leetgo: dev
// https://leetcode.cn/problems/remove-duplicates-from-sorted-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;

        for (int fast = 1; fast < nums.size(); fast++) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
        }

        return slow + 1;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);
	const set<int> expected(nums.begin(), nums.end());

	Solution *obj = new Solution();
	auto res = obj->removeDuplicates(nums);
	// Verify both the returned length and the in-place result prefix.
	if (res != expected.size() || nums.size() < expected.size() ||
	    !equal(expected.begin(), expected.end(), nums.begin())) {
		cerr << "Incorrect length or deduplicated prefix\n";
		delete obj;
		return 1;
	}
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
