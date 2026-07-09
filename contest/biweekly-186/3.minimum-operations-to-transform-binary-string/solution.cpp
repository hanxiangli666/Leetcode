// Created by James at 2026/07/04 14:02
// leetgo: dev
// https://leetcode.cn/problems/minimum-operations-to-transform-binary-string/
// https://leetcode.cn/contest/biweekly-contest-186/problems/minimum-operations-to-transform-binary-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int minOperations(string s1, string s2) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string s1;
	LeetCodeIO::scan(cin, s1);
	string s2;
	LeetCodeIO::scan(cin, s2);

	Solution *obj = new Solution();
	auto res = obj->minOperations(s1, s2);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
