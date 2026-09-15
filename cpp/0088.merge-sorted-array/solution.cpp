// Created by James at 2026/09/15 11:31
// leetgo: dev
// https://leetcode.cn/problems/merge-sorted-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

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
	stringstream out_stream;

	vector<int> nums1;
	LeetCodeIO::scan(cin, nums1);
	int m;
	LeetCodeIO::scan(cin, m);
	vector<int> nums2;
	LeetCodeIO::scan(cin, nums2);
	int n;
	LeetCodeIO::scan(cin, n);

	Solution *obj = new Solution();
	obj->merge(nums1, m, nums2, n);
	LeetCodeIO::print(out_stream, nums1);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
