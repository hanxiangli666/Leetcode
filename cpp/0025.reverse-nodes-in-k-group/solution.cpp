// Created by James at 2026/07/18 15:30
// leetgo: dev
// https://leetcode.cn/problems/reverse-nodes-in-k-group/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

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
	stringstream out_stream;

	ListNode* head;
	LeetCodeIO::scan(cin, head);
	int k;
	LeetCodeIO::scan(cin, k);

	Solution *obj = new Solution();
	auto res = obj->reverseKGroup(head, k);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
