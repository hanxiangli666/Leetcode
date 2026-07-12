// Created by James at 2026/07/12 00:08
// leetgo: dev
// https://leetcode.cn/problems/merge-two-sorted-lists/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        if (list1 != nullptr)
        {
            tail->next = list1;
        }
        else
        {
            tail->next = list2;
        }

        return dummy.next;
    }
};

// @lc code=end

int main()
{
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    ListNode* list1;
    LeetCodeIO::scan(cin, list1);
    ListNode* list2;
    LeetCodeIO::scan(cin, list2);

    Solution *obj = new Solution();
    auto res = obj->mergeTwoLists(list1, list2);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
