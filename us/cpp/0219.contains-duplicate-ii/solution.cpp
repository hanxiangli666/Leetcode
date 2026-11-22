// Created by James at 2026/11/22 07:43
// leetgo: 1.5.2
// https://leetcode.com/problems/contains-duplicate-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // 固定宽度的窗口：只看最近 k 个数里有没有和当前数一样的
        unordered_set<int> window;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (window.count(nums[i])) return true;
            window.insert(nums[i]);
            if ((int)window.size() > k) window.erase(nums[i - k]);   // 最老的那个移出窗口
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
		auto res = obj.containsNearbyDuplicate(nums, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
