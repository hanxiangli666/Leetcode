// Created by James at 2026/11/05 15:26
// leetgo: 1.5.2
// https://leetcode.com/problems/group-anagrams/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-05。
// 原题：https://leetcode.cn/problems/group-anagrams/
// 此提交为历史解法迁移，本轮重新练习进度单独记录。

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (string word : strs) {
            string key = word;
            sort(key.begin(), key.end());
            groups[key].push_back(word);
        }

        vector<vector<string>> result;

        for (auto& entry : groups) {
            result.push_back(entry.second);
        }

        return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<string> strs = LeetCodeIO::deserialize<vector<string>>(cin);

		Solution obj;
		auto res = obj.groupAnagrams(strs);

		// 本地比较统一顺序；题目允许分组及组内元素按任意顺序返回。
		for (auto& group : res) {
			sort(group.begin(), group.end());
		}
		sort(res.begin(), res.end());

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
