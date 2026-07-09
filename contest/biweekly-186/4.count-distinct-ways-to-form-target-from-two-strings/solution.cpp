// Created by James at 2026/07/04 14:02
// leetgo: dev
// https://leetcode.cn/problems/count-distinct-ways-to-form-target-from-two-strings/
// https://leetcode.cn/contest/biweekly-contest-186/problems/count-distinct-ways-to-form-target-from-two-strings/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int interleaveCharacters(string word1, string word2, string target) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string word1;
	LeetCodeIO::scan(cin, word1);
	string word2;
	LeetCodeIO::scan(cin, word2);
	string target;
	LeetCodeIO::scan(cin, target);

	Solution *obj = new Solution();
	auto res = obj->interleaveCharacters(word1, word2, target);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
