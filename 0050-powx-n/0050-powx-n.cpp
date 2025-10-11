class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double result = 1;
        while (N) {
            if (N % 2) result *= x;
            x *= x;
            N /= 2;
        }
        return result;
    }
};
