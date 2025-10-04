import java.util.*;

class Solution 
{
    public List<String> generateParenthesis(int n) 
    {
        List<String> list = new ArrayList<String>();
        backtrack(0, 0, n, list, "");
        return list;
    }
    public void backtrack(int open, int closed, int n, List<String> ans, String s)
    {
        if(open==n&&closed==n)
        {
            ans.add(s);
            return;
        }
        
        if(open < n)
        {
            backtrack(open+1, closed, n, ans, s +"(");
        }
        if(closed<open)
        {
            backtrack(open, closed+1, n, ans, s+")");
        }
    }
}