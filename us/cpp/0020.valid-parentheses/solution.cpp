// Created by James at 2026/11/07 10:47
// leetgo: 1.5.2
// https://leetcode.com/problems/valid-parentheses/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/valid-parentheses/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/704147152/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution {
public:
    bool isValid(string str) {
        stack<char> left;
        for (char c : str) {
            if (c == '(' || c == '{' || c == '[') {
                left.push(c);
            } else {
                if (!left.empty() && leftOf(c) == left.top()) {
                    left.pop();
                } else {
                    return false;
                }
            }
        }
        return left.empty();
    }

    char leftOf(char c) {
        switch (c) {
            case ')': return '(';
            case '}': return '{';
            case ']': return '[';
            default: return 0;
        }
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.isValid(s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
