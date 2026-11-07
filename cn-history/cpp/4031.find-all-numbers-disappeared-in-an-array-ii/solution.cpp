class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(
        vector<int>& nums,
        int lower,
        int upper
    ) {
        vector<bool> present(upper - lower + 1, false);

        for (int number : nums) {
            if (number >= lower && number <= upper) {
                present[number - lower] = true;
            }
        }
        vector<vector<int>> answer;
        int number = lower;

        while (number <= upper) {
            if (present[number - lower]) {
                ++number;
                continue;
            }

            int start = number;

            while (number <= upper &&
                   !present[number - lower]) {
                ++number;
            }

            answer.push_back({start, number - 1});
        }

        return answer;
    }
};
