// Created by James at 2026/11/07 10:47
// leetgo: 1.5.2
// https://leetcode.com/problems/reverse-linked-list-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/reverse-linked-list-ii/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/611132917/
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1 && right == 1) return head;
        if (left != 1) {
            head->next = reverseBetween(head->next, left-1, right-1);
        } else {
            ListNode *tail = head->next, *new_head;
            new_head = reverseBetween(head->next, left, right - 1);
            head->next = tail->next;
            tail->next = head;
            head = new_head;
        }
        return head;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		ListNode* head = LeetCodeIO::deserialize<ListNode*>(cin);
		int left = LeetCodeIO::deserialize<int>(cin);
		int right = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.reverseBetween(head, left, right);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
