// Created by James at 2026/11/23 07:43
// leetgo: 1.5.2
// https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 从右上角出发：比目标大就往左走（这一列都更大），比目标小就往下走（这一行都更小）
        int r = 0, c = (int)matrix[0].size() - 1;
        while (r < (int)matrix.size() && c >= 0) {
            int v = matrix[r][c];
            if (v == target) return true;
            if (v > target) --c;
            else ++r;
        }
        return false;
    }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
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
