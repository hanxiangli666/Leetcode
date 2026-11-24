// Created by James at 2026/11/24 07:43
// leetgo: 1.5.2
// https://leetcode.com/problems/find-k-closest-elements/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // 二分找长度为 k 的窗口的起点 lo：比较窗口两端谁离 x 更远，决定窗口往左还是往右挪
        int lo = 0, hi = (int)arr.size() - k;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (x - arr[mid] > arr[mid + k] - x) lo = mid + 1;   // 左端更远，窗口右移
            else hi = mid;
        }
        return vector<int>(arr.begin() + lo, arr.begin() + lo + k);
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> arr = LeetCodeIO::deserialize<vector<int>>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);
		int x = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.findClosestElements(arr, k, x);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
