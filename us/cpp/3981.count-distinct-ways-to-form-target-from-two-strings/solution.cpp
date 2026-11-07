// Created by James at 2026/11/07 10:48
// leetgo: 1.5.2
// https://leetcode.com/problems/count-distinct-ways-to-form-target-from-two-strings/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/count-distinct-ways-to-form-target-from-two-strings/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/734118047/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution {
public:
    int interleaveCharacters(string word1, string word2, string target) {
        auto valmorinth = make_tuple(word1, word2, target);
    
        const int MOD = 1000000007;
        int n1 = word1.size(), n2 = word2.size();
    
        vector<vector<long long>> dp(n1 + 1, vector<long long>(n2 + 1, 0));
        dp[0][0] = 1;
    
        for (char ch : target) {
            vector<vector<long long>> ndp(n1 + 1, vector<long long>(n2 + 1, 0));
    
            for (int i = 0; i <= n1; i++) {
                for (int j = 0; j <= n2; j++) {
                    if (dp[i][j] == 0) continue;
    
                    for (int p = i; p < n1; p++) {
                        if (word1[p] == ch) {
                            ndp[p + 1][j] = (ndp[p + 1][j] + dp[i][j]) % MOD;
                        }
                    }
    
                    for (int q = j; q < n2; q++) {
                        if (word2[q] == ch) {
                            ndp[i][q + 1] = (ndp[i][q + 1] + dp[i][j]) % MOD;
                        }
                    }
                }
            }
    
            dp = ndp;
        }
    
        long long total = 0;
        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                total = (total + dp[i][j]) % MOD;
            }
        }
    
        auto countOne = [&](string w) {
            int m = target.size();
            vector<long long> f(m + 1, 0);
            f[0] = 1;
    
            for (char ch : w) {
                for (int i = m - 1; i >= 0; i--) {
                    if (target[i] == ch) {
                        f[i + 1] = (f[i + 1] + f[i]) % MOD;
                    }
                }
            }
    
            return f[m];
        };
    
        long long only1 = countOne(word1);
        long long only2 = countOne(word2);
    
        long long ans = (total - only1 - only2) % MOD;
        if (ans < 0) ans += MOD;
    
        return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string word1 = LeetCodeIO::deserialize<string>(cin);
		string word2 = LeetCodeIO::deserialize<string>(cin);
		string target = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.interleaveCharacters(word1, word2, target);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
