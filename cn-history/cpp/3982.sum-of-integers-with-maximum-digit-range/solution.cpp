class Solution {
public:
    int digitRange(int x) {
        int mn = 9, mx = 0;

        while (x > 0) {
            int d = x % 10;
            mn = min(mn, d);
            mx = max(mx, d);
            x /= 10;
        }

        return mx - mn;
    }

    int maxDigitRange(vector<int>& nums) {
        int bestRange = -1;
        int ans = 0;

        for (int x : nums) {
            int r = digitRange(x);

            if (r > bestRange) {
                bestRange = r;
                ans = x;
            } else if (r == bestRange) {
                ans += x;
            }
        }

        return ans;
    }
};
