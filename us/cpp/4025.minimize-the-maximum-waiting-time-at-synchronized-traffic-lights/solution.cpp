// Created by James at 2026/11/07 10:48
// leetgo: 1.5.2
// https://leetcode.com/problems/minimize-the-maximum-waiting-time-at-synchronized-traffic-lights/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/minimize-the-maximum-waiting-time-at-synchronized-traffic-lights/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/742529504/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution {
public:
    int minPenalty(int period, vector<int>& lights,
                   vector<int>& arrivalTime) {
        int longestGreen = 0;

        for (int greenTime : lights) {
            longestGreen = max(longestGreen, greenTime);
        }

        int penalty = 0;

        for (int time : arrivalTime) {
            int remainder = time % period;
            int waitingTime = 0;

            if (remainder >= longestGreen) {
                waitingTime = period - remainder;
            }

            penalty = max(penalty, waitingTime);
        }

        return penalty;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int period = LeetCodeIO::deserialize<int>(cin);
		vector<int> lights = LeetCodeIO::deserialize<vector<int>>(cin);
		vector<int> arrivalTime = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.minPenalty(period, lights, arrivalTime);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
