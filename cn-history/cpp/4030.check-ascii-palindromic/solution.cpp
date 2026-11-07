class Solution {
public:
    bool isPalindromic(string s) {
        string binary;

        for (char character : s) {
            for (int bit = 7; bit >= 0; --bit) {
                int value = (character >> bit) & 1;
                binary.push_back(value + '0');
            }
        }
        int left = 0;
        int right = binary.size() - 1;

        while (left < right) {
            if (binary[left] != binary[right]) {
                return false;
            }

            ++left;
            --right;
        }

        return true;
    }
};
