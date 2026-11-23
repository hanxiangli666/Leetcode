// Created by James at 2026/11/23 07:43
// leetgo: 1.5.2
// https://leetcode.com/problems/search-a-2d-matrix/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 把整张表按行接起来看成一条有序的长队，在长队上二分
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int v = matrix[mid / n][mid % n];
            if (v == target) return true;
            if (v < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<int>> matrix = LeetCodeIO::deserialize<vector<vector<int>>>(cin);
		int target = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.searchMatrix(matrix, target);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
