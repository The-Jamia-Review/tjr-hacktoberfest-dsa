class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;

        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);
        int sign = (dividend > 0) == (divisor > 0) ? 1 : -1;

        long long quotient = 0;
        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            quotient += multiple;
        }

        return sign * quotient;
    }
};
