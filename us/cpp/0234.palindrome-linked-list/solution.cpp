// Created by James at 2026/11/05 15:26
// leetgo: 1.5.2
// https://leetcode.com/problems/palindrome-linked-list/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-05。
// 原题：https://leetcode.cn/problems/palindrome-linked-list/
// 此提交为历史解法迁移，本轮重新练习进度单独记录。

class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        vector<int> values;

        while (head != nullptr)
        {
            values.push_back(head->val);
            head = head->next;
        }

        int left = 0;
        int right = values.size() - 1;

        while (left < right)
        {
            if (values[left] != values[right])
            {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		ListNode* head = LeetCodeIO::deserialize<ListNode*>(cin);

		Solution obj;
		auto res = obj.isPalindrome(head);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
