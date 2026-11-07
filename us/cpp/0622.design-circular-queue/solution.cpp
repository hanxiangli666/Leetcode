// Created by James at 2026/11/07 10:48
// leetgo: 1.5.2
// https://leetcode.com/problems/design-circular-queue/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/design-circular-queue/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/612207290/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

struct Node {
    int data;
    Node *next;
};



class MyCircularQueue {
public:
    int count, size;
    Node *head, *tail;
    MyCircularQueue(int k) {
        head = new Node();
        tail = head;
        for (int i = 1; i < k; i++) {
            tail->next = new Node();
            tail = tail->next;
        }
        tail->next = head;
        size = k;
        count = 0;
        return ;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        tail = tail->next;
        tail->data = value;
        count += 1;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        head = head->next;
        count -= 1;
        return true;        
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return head->data;
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return tail->data;
    }
    
    bool isEmpty() {
       return count == 0; 
    }
    
    bool isFull() {
        return count == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		auto method_names = LeetCodeIO::deserialize<vector<string>>(cin);
		auto params = LeetCodeIO::split_array(cin);

		unique_ptr<MyCircularQueue> obj;
		vector<string> output;
		const unordered_map<string, function<void(const vector<string> &)>> methods = {
			{ "MyCircularQueue", [&](const vector<string> &method_params) {
				int k = LeetCodeIO::deserialize<int>(method_params, 0);
				obj = make_unique<MyCircularQueue>(k);
				output.push_back("null");
			} },
			{ "enQueue", [&](const vector<string> &method_params) {
				int value = LeetCodeIO::deserialize<int>(method_params, 0);
				output.push_back(LeetCodeIO::serialize(obj->enQueue(value)));
			} },
			{ "deQueue", [&](const vector<string> &) {
				output.push_back(LeetCodeIO::serialize(obj->deQueue()));
			} },
			{ "Front", [&](const vector<string> &) {
				output.push_back(LeetCodeIO::serialize(obj->Front()));
			} },
			{ "Rear", [&](const vector<string> &) {
				output.push_back(LeetCodeIO::serialize(obj->Rear()));
			} },
			{ "isEmpty", [&](const vector<string> &) {
				output.push_back(LeetCodeIO::serialize(obj->isEmpty()));
			} },
			{ "isFull", [&](const vector<string> &) {
				output.push_back(LeetCodeIO::serialize(obj->isFull()));
			} },
		};
		if (method_names.size() != params.size()) {
			throw LeetCodeIO::Error("method and parameter counts differ");
		}
		for (size_t i = 0; i < method_names.size(); ++i) {
			auto method_params = LeetCodeIO::split_array(params[i]);
			methods.at(method_names[i])(method_params);
		}
		cout << "\noutput: " << LeetCodeIO::join_array(output) << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
