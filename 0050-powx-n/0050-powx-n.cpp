class Solution {
public:
    double myPow(double x, int n) {
        if(n<0)
        return 1/helper(x,-((long long)n));
        return helper(x,n);
    }

    double helper (double x,long long n)
    {
        if(n<=0)
        return 1;
        if(n%2!=0)
        return x*helper(x,n-1);
        return helper(x*x,n/2);
    }
};