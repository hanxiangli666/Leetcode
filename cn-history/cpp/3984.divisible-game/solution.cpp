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
