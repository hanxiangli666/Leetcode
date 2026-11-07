// Created by James at 2026/11/07 10:47
// leetgo: 1.5.2
// https://leetcode.com/problems/rotate-list/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/rotate-list/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/611112050/
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
    int getLength(ListNode *head) {
        int n = 0;
        while (head) {
            n += 1;
            head = head->next;
        }
        return n;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        int n = getLength(head);
        k %= n;
        if (k == 0) return head;
        ListNode *p = head, *q = head;
        for (int i = 0; i <= k; i++) p = p->next;
        while (p) p = p->next, q = q->next;
        p = q->next;
        q->next = NULL;
        q = p;
        while (q->next != NULL) q = q->next;
        q->next = head;
        return p;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		ListNode* head = LeetCodeIO::deserialize<ListNode*>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.rotateRight(head, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
