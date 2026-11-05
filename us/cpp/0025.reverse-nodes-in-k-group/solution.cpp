// Created by James at 2026/11/05 15:26
// leetgo: 1.5.2
// https://leetcode.com/problems/reverse-nodes-in-k-group/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-05。
// 原题：https://leetcode.cn/problems/reverse-nodes-in-k-group/
// 此提交为历史解法迁移，本轮重新练习进度单独记录。

class Solution
{
private:
    ListNode* getKth(ListNode* node, int k)
    {
        while (node != nullptr && k > 0)
        {
            node = node->next;
            k--;
        }

        return node;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode dummy(0, head);
        ListNode* groupPrevious = &dummy;

        while (true)
        {
            ListNode* kth = getKth(groupPrevious, k);

            if (kth == nullptr)
            {
                return dummy.next;
            }

            ListNode* nextGroup = kth->next;
            ListNode* groupStart = groupPrevious->next;

            ListNode* reversedHead = nextGroup;
            ListNode* nodeToReverse = groupStart;

            while (nodeToReverse != nextGroup)
            {
                ListNode* nextNode = nodeToReverse->next;
                nodeToReverse->next = reversedHead;
                reversedHead = nodeToReverse;
                nodeToReverse = nextNode;
            }

            groupPrevious->next = reversedHead;
            groupPrevious = groupStart;
        }
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		ListNode* head = LeetCodeIO::deserialize<ListNode*>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.reverseKGroup(head, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
