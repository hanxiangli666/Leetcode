// Created by James at 2026/11/07 10:48
// leetgo: 1.5.2
// https://leetcode.com/problems/divisible-game/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/divisible-game/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/734142048/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        const long long MOD = 1000000007;

        set<int> ks;

        for (int x : nums) {
            for (int d = 2; d <= x / d; d++) {
                if (x % d == 0) {
                    ks.insert(d);
                    ks.insert(x / d);
                }
            }

            if (x > 1) {
                ks.insert(x);
            }
        }

        if (ks.empty()) {
            return MOD - 2;
        }

        long long bestDiff = -(1LL << 60);
        int bestK = 2;

        for (int k : ks) {
            long long current = 0;
            long long bestForK = -(1LL << 60);

            for (int x : nums) {
                long long score;

                if (x % k == 0) {
                    score = x;
                } else {
                    score = -x;
                }

                current = max(score, current + score);
                bestForK = max(bestForK, current);
            }

            if (bestForK > bestDiff) {
                bestDiff = bestForK;
                bestK = k;
            }
        }

        long long ans = bestDiff * bestK % MOD;
        if (ans < 0) ans += MOD;

        return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.divisibleGame(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
