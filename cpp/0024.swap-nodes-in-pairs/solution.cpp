// Created by James at 2026/07/15 15:45
// leetgo: dev
// https://leetcode.cn/problems/swap-nodes-in-pairs/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode dummy(0, head);
        ListNode* previous = &dummy;

        while (previous->next != nullptr &&
               previous->next->next != nullptr)
        {
            ListNode* first = previous->next;
            ListNode* second = first->next;

            first->next = second->next;
            second->next = first;
            previous->next = second;

            previous = first;
        }

        return dummy.next;
    }
};

// @lc code=end

int main()
{
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    ListNode* head;
    LeetCodeIO::scan(cin, head);

    Solution* obj = new Solution();
    auto res = obj->swapPairs(head);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
