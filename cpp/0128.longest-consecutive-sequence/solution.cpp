// Created by James at 2026/07/10 21:08
// leetgo: dev
// https://leetcode.cn/problems/longest-consecutive-sequence/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> numbers(nums.begin(), nums.end());
        int longest = 0;

        for (int value : numbers)
        {
            if (!numbers.count(value - 1))
            {
                int current = value;
                int length = 1;

                while (numbers.count(current + 1))
                {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
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
    auto res = obj->longestConsecutive(nums);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
