// Created by James at 2026/11/07 10:48
// leetgo: 1.5.2
// https://leetcode.com/problems/maximum-gap-between-stations/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/maximum-gap-between-stations/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/742531103/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution {
public:
    int maximumGap(string skill, string station) {
        int workerCount = skill.size();

        if (workerCount == 1) {
            return 0;
        }

        vector<int> earliest(workerCount);
        vector<int> latest(workerCount);

        int stationIndex = 0;

        // 每名工人最早可以分配到的位置
        for (int worker = 0; worker < workerCount; ++worker) {
            while (station[stationIndex] != skill[worker]) {
                ++stationIndex;
            }

            earliest[worker] = stationIndex;
            ++stationIndex;
        }

        stationIndex = station.size() - 1;

        // 每名工人最晚可以分配到的位置
        for (int worker = workerCount - 1; worker >= 0; --worker) {
            while (station[stationIndex] != skill[worker]) {
                --stationIndex;
            }

            latest[worker] = stationIndex;
            --stationIndex;
        }

        int answer = 0;

        for (int worker = 1; worker < workerCount; ++worker) {
            int gap = latest[worker] - earliest[worker - 1];
            answer = max(answer, gap);
        }

        return answer;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string skill = LeetCodeIO::deserialize<string>(cin);
		string station = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.maximumGap(skill, station);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
