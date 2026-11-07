// Created by James at 2026/11/07 10:48
// leetgo: 1.5.2
// https://leetcode.com/problems/minimum-total-price-after-applying-discounts/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/minimum-total-price-after-applying-discounts/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/741015799/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

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

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> prices = LeetCodeIO::deserialize<vector<int>>(cin);
		vector<int> discounts = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.minPrice(prices, discounts);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
