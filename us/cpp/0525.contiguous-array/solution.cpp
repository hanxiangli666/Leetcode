// Created by James at 2026/11/26 07:43
// leetgo: 1.5.2
// https://leetcode.com/problems/contiguous-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> first;
        first[0] = -1;
        int sum = 0, best = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            sum += nums[i] == 1 ? 1 : -1;
            auto it = first.find(sum);
            if (it != first.end()) best = max(best, i - it->second);
            else first[sum] = i;
        }
        return best;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.findMaxLength(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
