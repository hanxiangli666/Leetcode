// Created by James at 2026/11/27 07:43
// leetgo: 1.5.2
// https://leetcode.com/problems/car-pooling/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1002, 0);
        for (auto& t : trips) {
            diff[t[1]] += t[0];
            diff[t[2]] -= t[0];
        }
        int cur = 0;
        for (int x : diff) {
            cur += x;
            if (cur > capacity) return false;
        }
        return true;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<int>> trips = LeetCodeIO::deserialize<vector<vector<int>>>(cin);
		int capacity = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.carPooling(trips, capacity);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
