// Created by James at 2026/11/05 20:58
// leetgo: 1.5.2
// https://leetcode.com/problems/valid-palindrome/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = static_cast<int>(s.size()) - 1;

        while (left < right) {
            while (left < right && !isalnum(static_cast<unsigned char>(s[left]))) {
                ++left;
            }
            while (left < right && !isalnum(static_cast<unsigned char>(s[right]))) {
                --right;
            }
            if (tolower(static_cast<unsigned char>(s[left])) !=
                tolower(static_cast<unsigned char>(s[right]))) {
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
        auto res = obj.isPalindrome(s);

        stringstream out_stream;
        LeetCodeIO::print(out_stream, res);
        cout << "\noutput: " << out_stream.rdbuf() << '\n';
    } catch (const LeetCodeIO::Error &error) {
        cerr << "LC_IO: " << error.what() << '\n';
        return 2;
    }
    return 0;
}
