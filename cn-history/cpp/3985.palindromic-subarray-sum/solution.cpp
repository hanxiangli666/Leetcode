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
