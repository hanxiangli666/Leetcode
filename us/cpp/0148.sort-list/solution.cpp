// Created by James at 2026/11/05 15:26
// leetgo: 1.5.2
// https://leetcode.com/problems/sort-list/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-05。
// 原题：https://leetcode.cn/problems/sort-list/
// 此提交为历史解法迁移，本轮重新练习进度单独记录。

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

int main() {
	ios_base::sync_with_stdio(false);
	try {
		ListNode* head = LeetCodeIO::deserialize<ListNode*>(cin);

		Solution obj;
		auto res = obj.sortList(head);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
