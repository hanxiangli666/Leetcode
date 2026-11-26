// Created by James at 2026/11/26 07:43
// leetgo: 1.5.2
// https://leetcode.com/problems/continuous-subarray-sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> first;
        first[0] = -1;
        int mod = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            mod = (mod + nums[i]) % k;
            auto it = first.find(mod);
            if (it != first.end()) {
                if (i - it->second >= 2) return true;
            } else {
                first[mod] = i;
            }
        }
        return false;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.checkSubarraySum(nums, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
