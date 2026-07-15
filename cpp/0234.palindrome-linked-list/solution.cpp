// Created by James at 2026/07/15 00:04
// leetgo: dev
// https://leetcode.cn/problems/palindrome-linked-list/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        vector<int> values;

        while (head != nullptr)
        {
            values.push_back(head->val);
            head = head->next;
        }

        int left = 0;
        int right = values.size() - 1;

        while (left < right)
        {
            if (values[left] != values[right])
            {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

// @lc code=end

int main()
{
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    ListNode* head;
    LeetCodeIO::scan(cin, head);

    Solution *obj = new Solution();
    auto res = obj->isPalindrome(head);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
