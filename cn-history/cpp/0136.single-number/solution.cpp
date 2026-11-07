class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> count;
        // 遍历数组，统计每个数字出现的次数
        for (int num : nums) {
            count[num]++;
        }
        for (int num : nums) {
            if (count[num] == 1) {
                return num;
            }
        }
        return -1; // 题目保证一定存在一个只出现一次的数字
    }
};
