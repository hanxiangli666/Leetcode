// Created by James at 2026/07/15 21:43
// leetgo: dev
// https://leetcode.cn/problems/copy-list-with-random-pointer/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node* copyRandomList(Node* head)
    {
        unordered_map<Node*, Node*> copies;
        copies[nullptr] = nullptr;

        Node* current = head;

        while (current != nullptr)
        {
            copies[current] = new Node(current->val);
            current = current->next;
        }

        current = head;

        while (current != nullptr)
        {
            Node* copiedNode = copies[current];

            copiedNode->next = copies[current->next];
            copiedNode->random = copies[current->random];

            current = current->next;
        }

        return copies[head];
    }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main()
{
    ios_base::sync_with_stdio(false);
    stringstream out_stream;

    ListNode* head;
    LeetCodeIO::scan(cin, head);

    Solution* obj = new Solution();
    auto res = obj->copyRandomList(head);
    LeetCodeIO::print(out_stream, res);
    cout << "\noutput: " << out_stream.rdbuf() << endl;

    delete obj;
    return 0;
}
