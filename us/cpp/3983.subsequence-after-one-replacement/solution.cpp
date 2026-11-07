// Created by James at 2026/11/07 10:48
// leetgo: 1.5.2
// https://leetcode.com/problems/subsequence-after-one-replacement/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/subsequence-after-one-replacement/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/734138157/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int sLen = s.size();
        int tLen = t.size();

        if (sLen > tLen) return false;

        vector<int> leftEnd(sLen + 1, tLen + 1);
        leftEnd[0] = 0;

        int tPos = 0;

        for (int sPos = 0; sPos < sLen; sPos++) {
            while (tPos < tLen && t[tPos] != s[sPos]) {
                tPos++;
            }

            if (tPos == tLen) break;

            leftEnd[sPos + 1] = tPos + 1;
            tPos++;
        }

        if (leftEnd[sLen] <= tLen) return true;

        vector<int> rightStart(sLen + 1, -1);
        rightStart[sLen] = tLen;

        tPos = tLen - 1;

        for (int sPos = sLen - 1; sPos >= 0; sPos--) {
            while (tPos >= 0 && t[tPos] != s[sPos]) {
                tPos--;
            }

            if (tPos < 0) break;

            rightStart[sPos] = tPos;
            tPos--;
        }

        for (int replaceIndex = 0; replaceIndex < sLen; replaceIndex++) {
            if (leftEnd[replaceIndex] < rightStart[replaceIndex + 1]) {
                return true;
            }
        }

        return false;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);
		string t = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.canMakeSubsequence(s, t);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
