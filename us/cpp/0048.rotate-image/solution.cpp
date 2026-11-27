// Created by James at 2026/11/27 07:43
// leetgo: 1.5.2
// https://leetcode.com/problems/rotate-image/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
        for (auto& row : matrix) reverse(row.begin(), row.end());
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<int>> matrix = LeetCodeIO::deserialize<vector<vector<int>>>(cin);

		Solution obj;
		obj.rotate(matrix);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, matrix);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
