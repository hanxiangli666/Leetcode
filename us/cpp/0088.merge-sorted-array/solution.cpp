// Created by James at 2026/11/05 15:26
// leetgo: 1.5.2
// https://leetcode.com/problems/merge-sorted-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-05。
// 原题：https://leetcode.cn/problems/merge-sorted-array/
// 此提交为历史解法迁移，本轮重新练习进度单独记录。

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums1 = LeetCodeIO::deserialize<vector<int>>(cin);
		int m = LeetCodeIO::deserialize<int>(cin);
		vector<int> nums2 = LeetCodeIO::deserialize<vector<int>>(cin);
		int n = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		obj.merge(nums1, m, nums2, n);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, nums1);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
