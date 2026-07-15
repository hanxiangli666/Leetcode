// Created by James at 2026/07/12 21:01
// leetgo: dev
// https://leetcode.cn/problems/intersection-of-two-linked-lists/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

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
int main()
{
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    int intersectVal;
    LeetCodeIO::scan(cin, intersectVal);
    ListNode* listA;
    LeetCodeIO::scan(cin, listA);
    ListNode* listB;
    LeetCodeIO::scan(cin, listB);
    int skipA;
    LeetCodeIO::scan(cin, skipA);
    int skipB;
    LeetCodeIO::scan(cin, skipB);

    if (intersectVal != 0)
    {
        ListNode* intersection = listA;

        for (int i = 0; i < skipA; i++)
        {
            intersection = intersection->next;
        }

        if (skipB == 0)
        {
            listB = intersection;
        }
        else
        {
            ListNode* beforeIntersection = listB;

            for (int i = 1; i < skipB; i++)
            {
                beforeIntersection = beforeIntersection->next;
            }

            beforeIntersection->next = intersection;
        }
    }

    Solution *obj = new Solution();
    auto res = obj->getIntersectionNode(listA, listB);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
