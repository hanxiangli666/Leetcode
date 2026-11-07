// Created by James at 2026/11/07 10:48
// leetgo: 1.5.2
// https://leetcode.com/problems/validate-stack-sequences/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/validate-stack-sequences/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/612096992/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int x = 0, n = pushed.size();
        stack<int> s;
        for (int i = 0; i < n; i++) {
            if (s.empty() || s.top() != popped[i]) {
                while (x < pushed.size() && pushed[x] != popped[i]) {
                    s.push(pushed[x]);
                    x += 1;
                }
                if (x == pushed.size()) return false;
                s.push(pushed[x]);
                x += 1;
            }
            s.pop();
        }
        return true;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> pushed = LeetCodeIO::deserialize<vector<int>>(cin);
		vector<int> popped = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.validateStackSequences(pushed, popped);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
