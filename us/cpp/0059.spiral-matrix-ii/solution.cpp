// Created by James at 2026/11/27 07:43
// leetgo: 1.5.2
// https://leetcode.com/problems/spiral-matrix-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n, vector<int>(n));
        int top = 0, bottom = n - 1, left = 0, right = n - 1, v = 1;
        while (v <= n * n) {
            for (int j = left; j <= right && v <= n * n; j++) m[top][j] = v++;
            top++;
            for (int i = top; i <= bottom && v <= n * n; i++) m[i][right] = v++;
            right--;
            for (int j = right; j >= left && v <= n * n; j--) m[bottom][j] = v++;
            bottom--;
            for (int i = bottom; i >= top && v <= n * n; i--) m[i][left] = v++;
            left++;
        }
        return m;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int n = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.generateMatrix(n);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
