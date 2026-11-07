// Created by James at 2026/11/07 10:48
// leetgo: 1.5.2
// https://leetcode.com/problems/nearest-available-drone/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/nearest-available-drone/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/742527581/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones,
                     vector<int>& target) {
        int answer = -1;
        int minimumDistance = INT_MAX;

        for (int index = 0; index < drones.size(); ++index) {
            int distance =
                abs(drones[index][0] - target[0]) +
                abs(drones[index][1] - target[1]);

            if (distance <= drones[index][2] &&
                distance < minimumDistance) {
                minimumDistance = distance;
                answer = index;
            }
        }

        return answer;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<int>> drones = LeetCodeIO::deserialize<vector<vector<int>>>(cin);
		vector<int> target = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.nearestDrone(drones, target);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
