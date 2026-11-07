// Created by James at 2026/11/07 10:48
// leetgo: 1.5.2
// https://leetcode.com/problems/time-needed-to-buy-tickets/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/time-needed-to-buy-tickets/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/704149865/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        // 用队列模拟整个过程
        // 初始化队列，存储每个人的编号 id
        queue<int> queue;
        for (int i = 0; i < tickets.size(); i++) {
            queue.push(i);
        }

        int time = 0;
        while (!queue.empty()) {
            // 队头的人买票
            int front = queue.front();
            queue.pop();
            time++;
            tickets[front]--;
            
            if (front == k && tickets[front] == 0) {
                // 如果是 k 号买完票了，返回总时间
                return time;
            }

            if (tickets[front] == 0) {
                continue;
            }

            // 如果还要继续买票，重新排到队尾
            queue.push(front);
        }
        return time;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> tickets = LeetCodeIO::deserialize<vector<int>>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.timeRequiredToBuy(tickets, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
