// Created by James at 2026/07/11 15:36
// leetgo: dev
// https://leetcode.cn/problems/product-of-array-except-self/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> answer(n, 1);

        int left = 1;

        for (int i = 0; i < n; i++)
        {
            answer[i] = left;
            left = left * nums[i];
        }

        int right = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            answer[i] = answer[i] * right;
            right = right * nums[i];
        }

        return answer;
    }
};

// @lc code=end

int main()
{
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    vector<int> nums;
    LeetCodeIO::scan(cin, nums);

    Solution *obj = new Solution();
    auto res = obj->productExceptSelf(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
