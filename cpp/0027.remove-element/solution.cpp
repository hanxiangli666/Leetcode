// Created by James at 2026/09/13 08:56
// leetgo: dev
// https://leetcode.cn/problems/remove-element/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;

        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != val) {
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
	int val;
	LeetCodeIO::scan(cin, val);
	multiset<int> expected(nums.begin(), nums.end());
	expected.erase(val);

	Solution *obj = new Solution();
	auto res = obj->removeElement(nums, val);
	// Verify the retained prefix, including duplicate counts, in any order.
	if (res < 0 || static_cast<size_t>(res) != expected.size() ||
	    nums.size() < expected.size() ||
	    multiset<int>(nums.begin(), nums.begin() + res) != expected) {
		cerr << "Incorrect length or retained prefix\n";
		delete obj;
		return 1;
	}
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
