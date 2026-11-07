// Created by James at 2026/11/07 10:48
// leetgo: 1.5.2
// https://leetcode.com/problems/linked-list-cycle/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/linked-list-cycle/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/611098328/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p = head, *q = head;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
            if (p == q) {
                return true;
            }
        }
        return false;
    }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
	ios_base::sync_with_stdio(false);
	try {
		ListNode* head = LeetCodeIO::deserialize<ListNode*>(cin);
		int pos = LeetCodeIO::deserialize<int>(cin);
        vector<ListNode*> nodes;
        for (ListNode* node = head; node; node = node->next) nodes.push_back(node);
        if (pos >= 0) {
            if (pos >= static_cast<int>(nodes.size())) throw LeetCodeIO::Error("invalid cycle position");
            nodes.back()->next = nodes[pos];
        }

		Solution obj;
		auto res = obj.hasCycle(head);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
