class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        
        // 先递归计算一半，避免直接取反
        double half = myPow(x, n / 2);
        
        if (n % 2 == 0) {
            return half * half;
        } else if (n > 0) {
            return half * half * x;
        } else {
            return half * half / x;  // 负数情况，除以 x
        }
    }
};
