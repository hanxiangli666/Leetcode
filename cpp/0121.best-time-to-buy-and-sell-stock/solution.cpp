// Created by James at 2026/07/11 23:25
// leetgo: dev
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int lowestPrice = prices[0];
        int bestProfit = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            bestProfit = max(bestProfit, prices[i] - lowestPrice);
            lowestPrice = min(lowestPrice, prices[i]);
        }

        return bestProfit;
    }
};

// @lc code=end

int main()
{
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> prices;
    LeetCodeIO::scan(cin, prices);

    Solution *obj = new Solution();
    auto res = obj->maxProfit(prices);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
