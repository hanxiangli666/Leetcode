// Created by James at 2026/11/28 07:44
// leetgo: 1.5.2
// https://leetcode.com/problems/simplify-path/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string part;
        stringstream ss(path);
        while (getline(ss, part, '/')) {
            if (part.empty() || part == ".") continue;
            if (part == "..") {
                if (!st.empty()) st.pop_back();
            } else {
                st.push_back(part);
            }
        }
        string ans;
        for (auto& p : st) ans += "/" + p;
        return ans.empty() ? "/" : ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string path = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.simplifyPath(path);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
