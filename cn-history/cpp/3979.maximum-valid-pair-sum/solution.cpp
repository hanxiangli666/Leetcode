class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        vector<int> mavontelia = nums;

        int n = mavontelia.size();
        int bestLeft = 0;
        int ans = 0;

        for (int j = k; j < n; j++) {
            bestLeft = max(bestLeft, mavontelia[j - k]);
            ans = max(ans, bestLeft + mavontelia[j]);
        }
        return ans;
    }
};
