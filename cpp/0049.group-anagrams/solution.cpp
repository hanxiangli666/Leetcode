// Created by James at 2026/07/10 20:03
// leetgo: dev
// https://leetcode.cn/problems/group-anagrams/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

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
	stringstream out_stream;

	vector<string> strs;
	LeetCodeIO::scan(cin, strs);

	Solution *obj = new Solution();
	auto res = obj->groupAnagrams(strs);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
