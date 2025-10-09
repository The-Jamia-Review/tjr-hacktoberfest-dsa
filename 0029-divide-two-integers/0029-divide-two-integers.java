class Solution 
{
    public int divide(int dividend, int divisor) 
    {
        if(dividend == divisor) return 1;
        
        boolean sign = true;
        sign = !((dividend<0)^(divisor<0));
        
        long n = Math.abs((long) dividend);
        long d = Math.abs((long) divisor);
        
        long ans = 0;
        
        while(n >= d)
        {
            long currD = d;
            long currAns = 1;
            
            while(n >= (currD<<1))
            {
                currD = currD<<1;
                currAns = currAns<<1;
            }
            
            ans += currAns;
            n -= currD;
            
        }
        
        if (ans >= (1L << 31))
            return sign ? Integer.MAX_VALUE : Integer.MIN_VALUE;
        
        return sign? (int)ans: (int)-ans;
    }
}