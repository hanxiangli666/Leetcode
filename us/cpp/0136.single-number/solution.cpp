// Created by James at 2026/11/07 10:47
// leetgo: 1.5.2
// https://leetcode.com/problems/single-number/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/single-number/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/704144994/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> count;
        // 遍历数组，统计每个数字出现的次数
        for (int num : nums) {
            count[num]++;
        }
        for (int num : nums) {
            if (count[num] == 1) {
                return num;
            }
        }
        return -1; // 题目保证一定存在一个只出现一次的数字
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.singleNumber(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
