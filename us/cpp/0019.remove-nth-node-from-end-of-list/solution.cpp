// Created by James at 2026/11/07 10:47
// leetgo: 1.5.2
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/611116956/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode new_head, *p = &new_head, *q = p;
        new_head.next = head;
        for (int i = 0; i <= n; i++) q = q->next;
        while (q) p = p->next, q = q->next;
        p->next = p->next->next;
        return new_head.next;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		ListNode* head = LeetCodeIO::deserialize<ListNode*>(cin);
		int n = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.removeNthFromEnd(head, n);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
