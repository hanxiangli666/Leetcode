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
