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
