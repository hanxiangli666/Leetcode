// Created by James at 2026/11/05 15:26
// leetgo: 1.5.2
// https://leetcode.com/problems/intersection-of-two-linked-lists/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-05。
// 原题：https://leetcode.cn/problems/intersection-of-two-linked-lists/
// 此提交为历史解法迁移，本轮重新练习进度单独记录。

class Solution
{
public:
    int getLength(ListNode* head)
    {
        int length = 0;

        while (head != nullptr)
        {
            length++;
            head = head->next;
        }

        return length;
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);

        ListNode* pointerA = headA;
        ListNode* pointerB = headB;

        while (lengthA > lengthB)
        {
            pointerA = pointerA->next;
            lengthA--;
        }

        while (lengthB > lengthA)
        {
            pointerB = pointerB->next;
            lengthB--;
        }

        while (pointerA != pointerB)
        {
            pointerA = pointerA->next;
            pointerB = pointerB->next;
        }

        return pointerA;
    }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
	ios_base::sync_with_stdio(false);
	try {
		int intersectVal = LeetCodeIO::deserialize<int>(cin);
		ListNode* listA = LeetCodeIO::deserialize<ListNode*>(cin);
		ListNode* listB = LeetCodeIO::deserialize<ListNode*>(cin);
		int skipA = LeetCodeIO::deserialize<int>(cin);
		int skipB = LeetCodeIO::deserialize<int>(cin);

		// 本地入口按下标连接共享尾部，让相交处具有同一个节点地址。
		ListNode* intersection = nullptr;
		if (intersectVal != 0) {
			intersection = listA;
			for (int i = 0; i < skipA; ++i) intersection = intersection->next;
			if (skipB == 0) {
				listB = intersection;
			} else {
				ListNode* before = listB;
				for (int i = 1; i < skipB; ++i) before = before->next;
				before->next = intersection;
			}
		}

		Solution obj;
		auto res = obj.getIntersectionNode(listA, listB);
		if (res != intersection) {
			cerr << "Local check: incorrect intersection node address\n";
			return 1;
		}

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
