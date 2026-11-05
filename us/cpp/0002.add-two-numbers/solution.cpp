// Created by James at 2026/11/05 15:26
// leetgo: 1.5.2
// https://leetcode.com/problems/add-two-numbers/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-05。
// 原题：https://leetcode.cn/problems/add-two-numbers/
// 此提交为历史解法迁移，本轮重新练习进度单独记录。

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

int main() {
	ios_base::sync_with_stdio(false);
	try {
		ListNode* l1 = LeetCodeIO::deserialize<ListNode*>(cin);
		ListNode* l2 = LeetCodeIO::deserialize<ListNode*>(cin);

		Solution obj;
		auto res = obj.addTwoNumbers(l1, l2);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
