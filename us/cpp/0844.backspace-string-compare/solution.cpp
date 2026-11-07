// Created by James at 2026/11/07 10:48
// leetgo: 1.5.2
// https://leetcode.com/problems/backspace-string-compare/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/backspace-string-compare/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/612074293/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution {
public:
void pushStack(string &s, stack<char> &s1) {
    for (int i = 0; s[i]; i++) {
        if (s[i] == '#' ){
            if (!s1.empty()) s1.pop();
        } else s1.push(s[i]);
    }
    return ;
}
    bool backspaceCompare(string s, string t) {
        stack<char> s1, s2;
        pushStack(s, s1);
        pushStack(t, s2);
        if (s1.size() != s2.size()) return false;
        while (!s1.empty()) {
            if (s1.top() != s2.top()) return false;
            s1.pop(), s2.pop();
        }
        return true;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);
		string t = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.backspaceCompare(s, t);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
