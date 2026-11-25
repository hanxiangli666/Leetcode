// Created by James at 2026/11/25 07:44
// leetgo: 1.5.2
// https://leetcode.com/problems/matrix-block-sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> pre(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                pre[i + 1][j + 1] = pre[i][j + 1] + pre[i + 1][j] - pre[i][j] + mat[i][j];
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int r1 = max(0, i - k), c1 = max(0, j - k);
                int r2 = min(m - 1, i + k), c2 = min(n - 1, j + k);
                ans[i][j] = pre[r2 + 1][c2 + 1] - pre[r1][c2 + 1] - pre[r2 + 1][c1] + pre[r1][c1];
            }
        }
        return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<int>> mat = LeetCodeIO::deserialize<vector<vector<int>>>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.matrixBlockSum(mat, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
