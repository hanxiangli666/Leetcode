class Solution {
public:
    int minOperations(string s1, string s2) {
        auto melorvanti = make_pair(s1, s2);

        const long long INF = 4e18;
        int n = s1.size();
    
        auto cost = [&](int i, int leftOp, int rightOp) -> long long {
            int t = leftOp + rightOp;
    
            char a = melorvanti.first[i];
            char b = melorvanti.second[i];
    
            if (t == 0) {
                if (a == b) return 0;
                if (a == '0' && b == '1') return 1;
                return INF;
            }
    
            long long res = 0;
    
            if (a == '0') res++;
            res += t - 1;
            if (b == '1') res++;
    
            return res;
        };
    
        vector<long long> dp(2, INF);
        dp[0] = 0;
    
        for (int i = 0; i < n; i++) {
            vector<long long> ndp(2, INF);
    
            for (int leftOp = 0; leftOp <= 1; leftOp++) {
                if (dp[leftOp] >= INF) continue;
    
                for (int rightOp = 0; rightOp <= 1; rightOp++) {
                    if (i == n - 1 && rightOp == 1) continue;
    
                    long long add = cost(i, leftOp, rightOp) + rightOp;
                    ndp[rightOp] = min(ndp[rightOp], dp[leftOp] + add);
                }
            }
    
            dp = ndp;
        }
    
        return dp[0] >= INF ? -1 : (int)dp[0];
    }
};
