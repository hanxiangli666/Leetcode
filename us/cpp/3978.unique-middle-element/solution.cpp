// Created by James at 2026/11/07 10:48
// leetgo: 1.5.2
// https://leetcode.com/problems/unique-middle-element/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/unique-middle-element/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/734117325/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int mid = nums.size() / 2;
        int target = nums[mid];
        
        int cnt = 0;
        for (int x : nums) {
            if (x == target) {
                cnt++;
            }
        }
        
        return cnt == 1;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.isMiddleElementUnique(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
