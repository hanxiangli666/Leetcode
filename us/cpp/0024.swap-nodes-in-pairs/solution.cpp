// Created by James at 2026/11/05 15:26
// leetgo: 1.5.2
// https://leetcode.com/problems/swap-nodes-in-pairs/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-05。
// 原题：https://leetcode.cn/problems/swap-nodes-in-pairs/
// 此提交为历史解法迁移，本轮重新练习进度单独记录。

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

int main() {
	ios_base::sync_with_stdio(false);
	try {
		ListNode* head = LeetCodeIO::deserialize<ListNode*>(cin);

		Solution obj;
		auto res = obj.swapPairs(head);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
