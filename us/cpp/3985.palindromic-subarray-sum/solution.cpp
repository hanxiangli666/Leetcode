// Created by James at 2026/11/07 10:48
// leetgo: 1.5.2
// https://leetcode.com/problems/palindromic-subarray-sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/palindromic-subarray-sum/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/734143496/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution {
public:
    long long getSum(vector<int>& nums) {
        vector<int> arr = nums;

        int n = arr.size();

        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + arr[i];
        }

        long long answer = 0;

        vector<int> oddRadius(n);
        int leftBound = 0;
        int rightBound = -1;

        for (int center = 0; center < n; center++) {
            int radius = 1;

            if (center <= rightBound) {
                int mirror = leftBound + rightBound - center;
                radius = min(oddRadius[mirror], rightBound - center + 1);
            }

            while (
                center - radius >= 0 &&
                center + radius < n &&
                arr[center - radius] == arr[center + radius]
            ) {
                radius++;
            }

            oddRadius[center] = radius;

            int start = center - radius + 1;
            int end = center + radius - 1;

            answer = max(answer, prefixSum[end + 1] - prefixSum[start]);

            if (end > rightBound) {
                leftBound = start;
                rightBound = end;
            }
        }

        vector<int> evenRadius(n);
        leftBound = 0;
        rightBound = -1;

        for (int center = 0; center < n; center++) {
            int radius = 0;

            if (center <= rightBound) {
                int mirror = leftBound + rightBound - center + 1;
                radius = min(evenRadius[mirror], rightBound - center + 1);
            }

            while (
                center - radius - 1 >= 0 &&
                center + radius < n &&
                arr[center - radius - 1] == arr[center + radius]
            ) {
                radius++;
            }

            evenRadius[center] = radius;

            if (radius > 0) {
                int start = center - radius;
                int end = center + radius - 1;

                answer = max(answer, prefixSum[end + 1] - prefixSum[start]);

                if (end > rightBound) {
                    leftBound = start;
                    rightBound = end;
                }
            }
        }

        return answer;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.getSum(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
