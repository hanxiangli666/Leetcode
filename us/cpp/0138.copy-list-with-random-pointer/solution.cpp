// Created by James at 2026/11/05 15:26
// leetgo: 1.5.2
// https://leetcode.com/problems/copy-list-with-random-pointer/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// 仅供本地测试；美国站会提供这个节点类型。
class Node {
public:
    int val;
    Node* next;
    Node* random;
    explicit Node(int value) : val(value), next(nullptr), random(nullptr) {}
};

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-05。
// 原题：https://leetcode.cn/problems/copy-list-with-random-pointer/
// 此提交为历史解法迁移，本轮重新练习进度单独记录。

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

// 本地入口把 [节点值, 随机指针下标] 还原成真实节点，并检查深拷贝。
int main() {
    ios_base::sync_with_stdio(false);
    try {
        auto input = LeetCodeIO::deserialize<vector<vector<optional<int>>>>(cin);
        vector<Node*> original;
        for (const auto& row : input) {
            original.push_back(new Node(row.at(0).value()));
        }
        for (size_t i = 0; i < original.size(); ++i) {
            original[i]->next = i + 1 < original.size() ? original[i + 1] : nullptr;
            if (input[i].at(1).has_value()) {
                original[i]->random = original.at(input[i][1].value());
            }
        }

        Solution obj;
        Node* result = obj.copyRandomList(original.empty() ? nullptr : original[0]);
        unordered_set<Node*> originalNodes(original.begin(), original.end());
        vector<Node*> copied;
        unordered_map<Node*, int> index;
        for (Node* node = result; node != nullptr; node = node->next) {
            if (originalNodes.count(node) || index.count(node) || copied.size() >= original.size()) {
                throw runtime_error("copy must contain new nodes and no cycle");
            }
            index[node] = static_cast<int>(copied.size());
            copied.push_back(node);
        }
        if (copied.size() != original.size()) {
            throw runtime_error("copied list length differs from input");
        }

        vector<vector<optional<int>>> output;
        for (Node* node : copied) {
            optional<int> randomIndex;
            if (node->random != nullptr) {
                if (!index.count(node->random)) {
                    throw runtime_error("random pointer must refer to a copied node");
                }
                randomIndex = index.at(node->random);
            }
            output.push_back({node->val, randomIndex});
        }
        stringstream out;
        out << '[';
        for (size_t i = 0; i < output.size(); ++i) {
            if (i != 0) out << ',';
            out << '[' << output[i][0].value() << ',';
            if (output[i][1].has_value()) out << output[i][1].value();
            else out << "null";
            out << ']';
        }
        out << ']';
        cout << "\noutput: " << out.rdbuf() << '\n';
        for (Node* node : original) delete node;
        for (Node* node : copied) delete node;
    } catch (const exception& error) {
        cerr << "Local input/output: " << error.what() << '\n';
        return 2;
    }
    return 0;
}
