// Created by James at 2026/11/07 10:48
// leetgo: 1.5.2
// https://leetcode.com/problems/happy-number/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/happy-number/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/611104260/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution {
public:
int getNext(int x) {
    int d, y = 0;
    while (x) {
        d = x % 10;
        y += d * d;
        x /= 10;
    }
    return y;
}
    bool isHappy(int n) {
        int p = n, q = n;
        while (q != 1) {
            p = getNext(p);
            q = getNext(getNext(q));
            if (p == q && p != 1) {
                return false;
            }
        }
        return true;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int n = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.isHappy(n);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
