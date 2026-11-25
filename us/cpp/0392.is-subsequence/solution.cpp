// Created by James at 2026/11/25 07:44
// leetgo: 1.5.2
// https://leetcode.com/problems/is-subsequence/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool isSubsequence(string s, string t) {
        size_t i = 0;
        for (char c : t) {
            if (i < s.size() && s[i] == c) i++;
        }
        return i == s.size();
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);
		string t = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.isSubsequence(s, t);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
