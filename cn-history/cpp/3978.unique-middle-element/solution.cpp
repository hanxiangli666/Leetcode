class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int mid = nums.size() / 2;
        int target = nums[mid];
        
        int cnt = 0;
        for (int x : nums) {
            if (x == target) {
                cnt++;
            }
        }
        
        return cnt == 1;
    }
};
