class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 0.0)
            return 0.0;

        long long N = n;
        if (N < 0)
        {
            x = 1.0 / x;
            N = -N;
        }

        double result = 1.0;
        while (N > 0)
        {
            if (N & 1)
                result *= x;
            x *= x;
            N >>= 1;
        }
        return result;
    }
};
