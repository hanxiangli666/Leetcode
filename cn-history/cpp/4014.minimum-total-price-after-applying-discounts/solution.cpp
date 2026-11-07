class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());

        double ans = accumulate(prices.begin(), prices.end(), 0.0);
        int k = min(prices.size(), discounts.size());

        for (int i = 0; i < k; ++i) {
            ans -= 1.0 * prices[i] * discounts[i] / 100.0;
        }

        return ans;
    }
};
