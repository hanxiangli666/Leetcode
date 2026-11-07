// Created by James at 2026/11/07 10:47
// leetgo: 1.5.2
// https://leetcode.com/problems/powx-n/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/powx-n/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/668661343/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution {
public:
    double myPow(double x, int n) {
        long long exponent = n;
        // 美国站精度兼容：先求正指数幂，负指数只在最后取倒数。
        // 先提升为 long long，避免 INT_MIN 取反溢出。
        return exponent < 0 ? 1.0 / power(x, -exponent) : power(x, exponent);
    }

private:
    double power(double x, long long exponent) {
        if (exponent == 0) return 1.0;
        double half = power(x, exponent / 2);
        return exponent % 2 == 0 ? half * half : half * half * x;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		double x = LeetCodeIO::deserialize<double>(cin);
		int n = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.myPow(x, n);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
