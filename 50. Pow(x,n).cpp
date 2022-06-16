class Solution {
public:
    double myPow(double x, int n) {
        // x^n = x^(n/2) * x^(n/2)      when n is even
        //     = x^(n/2) * x^(n/2) * x  when n is odd
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1.0 / x;

        double temp = myPow(x, n/2);
        double ans = temp * temp;
        if (n & 1) ans *= (n < 0 ? 1.0 / x : x);
        return ans;
    }
};