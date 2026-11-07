class Solution {
public:
    int minPenalty(int period, vector<int>& lights,
                   vector<int>& arrivalTime) {
        int longestGreen = 0;

        for (int greenTime : lights) {
            longestGreen = max(longestGreen, greenTime);
        }

        int penalty = 0;

        for (int time : arrivalTime) {
            int remainder = time % period;
            int waitingTime = 0;

            if (remainder >= longestGreen) {
                waitingTime = period - remainder;
            }

            penalty = max(penalty, waitingTime);
        }

        return penalty;
    }
};
