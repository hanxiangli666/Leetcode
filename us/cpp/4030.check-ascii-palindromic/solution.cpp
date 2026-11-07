// Created by James at 2026/11/07 10:48
// leetgo: 1.5.2
// https://leetcode.com/problems/check-ascii-palindromic/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/check-ascii-palindromic/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/744017759/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution {
public:
    bool isPalindromic(string s) {
        string binary;

        for (char character : s) {
            for (int bit = 7; bit >= 0; --bit) {
                int value = (character >> bit) & 1;
                binary.push_back(value + '0');
            }
        }
        int left = 0;
        int right = binary.size() - 1;

        while (left < right) {
            if (binary[left] != binary[right]) {
                return false;
            }

            ++left;
            --right;
        }

        return true;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.isPalindromic(s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
