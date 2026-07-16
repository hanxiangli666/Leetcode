// Created by James at 2026/07/16 10:04
// leetgo: dev
// https://leetcode.cn/problems/sort-list/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution
{
public:
    ListNode* mergeSortedLists(ListNode* list1, ListNode* list2)
    {
        ListNode dummy;
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

    ListNode* sortList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* rightHead = slow->next;
        slow->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        return mergeSortedLists(left, right);
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
    auto res = obj->sortList(head);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
