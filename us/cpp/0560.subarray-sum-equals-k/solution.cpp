// Created by James at 2026/11/21 01:52
// leetgo: 1.5.2
// https://leetcode.com/problems/subarray-sum-equals-k/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 前缀和 + 哈希表：sum(i..j) = pre[j] - pre[i-1] = k
        // 等价于：找之前出现过多少次前缀和 pre[j] - k
        unordered_map<int, int> count;
        count[0] = 1;                    // 空前缀，处理从下标 0 开始的子数组
        int pre = 0, ans = 0;
        for (int x : nums) {
            pre += x;
            auto it = count.find(pre - k);
            if (it != count.end()) ans += it->second;
            ++count[pre];
        }
        return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.subarraySum(nums, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
