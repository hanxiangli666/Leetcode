// Created by James at 2026/07/11 22:06
// leetgo: dev
// https://leetcode.cn/problems/maximum-subarray/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int current = nums[0];
        int best = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            current = max(nums[i], current + nums[i]);
            best = max(best, current);
        }

        return best;
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
    auto res = obj->maxSubArray(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
