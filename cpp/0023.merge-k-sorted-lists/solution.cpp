// Created by James at 2026/07/17 11:42
// leetgo: dev
// https://leetcode.cn/problems/merge-k-sorted-lists/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution
{
public:
    struct Compare
    {
        bool operator()(ListNode* left, ListNode* right)
        {
            return left->val > right->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

        for (ListNode* head : lists)
        {
            if (head != nullptr)
            {
                minHeap.push(head);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!minHeap.empty())
        {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next != nullptr)
            {
                minHeap.push(smallest->next);
            }
        }

        return dummy.next;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<ListNode*> lists;
	LeetCodeIO::scan(cin, lists);

	Solution *obj = new Solution();
	auto res = obj->mergeKLists(lists);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
