// Created by James at 2026/11/07 10:48
// leetgo: 1.5.2
// https://leetcode.com/problems/longest-subarray-with-at-most-k-distinct-prime-factors/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

// 由中文站已通过解法迁移至美国站，迁移日期：2026-11-07。
// 原题：https://leetcode.cn/problems/longest-subarray-with-at-most-k-distinct-prime-factors/
// 原 Accepted 提交：https://leetcode.cn/submissions/detail/744021819/
// 此提交为历史解法迁移，重新练习与比赛成绩单独记录。

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int count = nums.size();
        int maximumValue =
            *max_element(nums.begin(), nums.end());

        vector<int> smallestPrimeFactor(maximumValue + 1);

        for (int prime = 2; prime <= maximumValue; ++prime) {
            if (smallestPrimeFactor[prime] != 0) {
                continue;
            }

            for (int multiple = prime;
                 multiple <= maximumValue;
                 multiple += prime) {

                if (smallestPrimeFactor[multiple] == 0) {
                    smallestPrimeFactor[multiple] = prime;
                }
            }
        }
        vector<vector<int>> primeFactors(count);

        for (int index = 0; index < count; ++index) {
            int value = nums[index];

            while (value > 1) {
                int prime = smallestPrimeFactor[value];
                primeFactors[index].push_back(prime);
                while (value % prime == 0) {
                    value /= prime;
                }
            }
        }

        vector<int> primeFrequency(maximumValue + 1);

        int left = 0;
        int differentPrimes = 0;
        int answer = 0;

        for (int right = 0; right < count; ++right) {
            for (int prime : primeFactors[right]) {
                if (primeFrequency[prime] == 0) {
                    ++differentPrimes;
                }

                ++primeFrequency[prime];
            }
            while (differentPrimes > k) {
                for (int prime : primeFactors[left]) {
                    --primeFrequency[prime];

                    if (primeFrequency[prime] == 0) {
                        --differentPrimes;
                    }
                }

                ++left;
            }

            answer = max(answer, right - left + 1);
        }

        return answer;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.longestSubarray(nums, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
