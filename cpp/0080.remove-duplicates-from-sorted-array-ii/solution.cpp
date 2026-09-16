// Created by James at 2026/09/16 15:35
// leetgo: dev
// https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;

        for (int fast = 0; fast < nums.size(); fast++) {
            if (slow < 2 || nums[fast] != nums[slow - 2]) {
                nums[slow] = nums[fast];
                slow++;
            }
        }

        return slow;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);
	vector<int> expected;
	for (int value : nums) {
		if (expected.size() < 2 || value != expected[expected.size() - 2]) {
			expected.push_back(value);
		}
	}

	Solution *obj = new Solution();
	auto res = obj->removeDuplicates(nums);
	if (res < 0 || static_cast<size_t>(res) != expected.size() ||
	    nums.size() < expected.size() ||
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
