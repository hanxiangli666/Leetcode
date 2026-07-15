// Created by James at 2026/07/15 00:21
// leetgo: dev
// https://leetcode.cn/problems/add-two-numbers/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int value1 = l1 != nullptr ? l1->val : 0;
            int value2 = l2 != nullptr ? l2->val : 0;

            int sum = value1 + value2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            tail->next = new ListNode(digit);
            tail = tail->next;

            if (l1 != nullptr)
            {
                l1 = l1->next;
            }

            if (l2 != nullptr)
            {
                l2 = l2->next;
            }
        }

        return dummy.next;
    }
};

// @lc code=end

int main()
{
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    ListNode* l1;
    LeetCodeIO::scan(cin, l1);
    ListNode* l2;
    LeetCodeIO::scan(cin, l2);

    Solution* obj = new Solution();
    auto res = obj->addTwoNumbers(l1, l2);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
