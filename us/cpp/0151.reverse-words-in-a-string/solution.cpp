// Created by James at 2026/11/28 07:44
// leetgo: 1.5.2
// https://leetcode.com/problems/reverse-words-in-a-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string w;
        for (char c : s) {
            if (c == ' ') {
                if (!w.empty()) { words.push_back(w); w.clear(); }
            } else {
                w += c;
            }
        }
        if (!w.empty()) words.push_back(w);
        string ans;
        for (int i = (int)words.size() - 1; i >= 0; i--) {
            ans += words[i];
            if (i > 0) ans += ' ';
        }
        return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.reverseWords(s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
