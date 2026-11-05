// Created by James at 2026/11/05 15:26
// leetgo: 1.5.2
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-05。
// 原题：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
// 此提交为历史解法迁移，本轮重新练习进度单独记录。

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

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> prices = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.maxProfit(prices);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
