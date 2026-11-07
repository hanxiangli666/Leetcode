// Created by James at 2026/11/07 10:48
// leetgo: 1.5.2
// https://leetcode.com/problems/maximum-area-of-two-non-overlapping-square-submatrices/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/maximum-area-of-two-non-overlapping-square-submatrices/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/741019250/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int rows = mat.size();
        int columns = mat[0].size();
        vector<vector<int>> prefix(
            rows + 1,
            vector<int>(columns + 1, 0)
        );

        for (int row = 0; row < rows; ++row) {
            for (int column = 0; column < columns; ++column) {
                prefix[row + 1][column + 1] =
                    mat[row][column]
                    + prefix[row][column + 1]
                    + prefix[row + 1][column]
                    - prefix[row][column];
            }
        }

        auto canChooseTwo = [&](int sideLength) {
            int minimumRow = rows;
            int maximumRow = -1;
            int minimumColumn = columns;
            int maximumColumn = -1;

            for (int topRow = 0;
                 topRow + sideLength <= rows;
                 ++topRow) {

                for (int leftColumn = 0;
                     leftColumn + sideLength <= columns;
                     ++leftColumn) {

                    int bottomRow = topRow + sideLength;
                    int rightColumn = leftColumn + sideLength;

                    int numberOfOnes =
                        prefix[bottomRow][rightColumn]
                        - prefix[topRow][rightColumn]
                        - prefix[bottomRow][leftColumn]
                        + prefix[topRow][leftColumn];

                    if (numberOfOnes ==
                        sideLength * sideLength) {

                        minimumRow = min(minimumRow, topRow);
                        maximumRow = max(maximumRow, topRow);

                        minimumColumn =
                            min(minimumColumn, leftColumn);
                        maximumColumn =
                            max(maximumColumn, leftColumn);

                        if (maximumRow - minimumRow >= sideLength ||
                            maximumColumn - minimumColumn >= sideLength) {
                            return true;
                        }
                    }
                }
            }

            return false;
        };

        int lowSide = 1;
        int highSide = min(rows, columns);
        int bestSide = 0;

        while (lowSide <= highSide) {
            int middleSide =
                lowSide + (highSide - lowSide) / 2;

            if (canChooseTwo(middleSide)) {
                bestSide = middleSide;
                lowSide = middleSide + 1;
            } else {
                highSide = middleSide - 1;
            }
        }

        return bestSide * bestSide;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<int>> mat = LeetCodeIO::deserialize<vector<vector<int>>>(cin);

		Solution obj;
		auto res = obj.maxArea(mat);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
