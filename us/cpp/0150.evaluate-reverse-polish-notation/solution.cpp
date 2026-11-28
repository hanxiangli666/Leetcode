// Created by James at 2026/11/28 07:44
// leetgo: 1.5.2
// https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<long long> st;
        for (auto& t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                long long b = st.back(); st.pop_back();
                long long a = st.back(); st.pop_back();
                if (t == "+") st.push_back(a + b);
                else if (t == "-") st.push_back(a - b);
                else if (t == "*") st.push_back(a * b);
                else st.push_back(a / b);
            } else {
                st.push_back(stoll(t));
            }
        }
        return (int)st.back();
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<string> tokens = LeetCodeIO::deserialize<vector<string>>(cin);

		Solution obj;
		auto res = obj.evalRPN(tokens);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
