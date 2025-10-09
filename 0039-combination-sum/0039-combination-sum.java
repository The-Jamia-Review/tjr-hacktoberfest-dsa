import java.util.*;
class Solution 
{
    public List<List<Integer>> combinationSum(int[] candidates, int target) 
    {
        List<List<Integer>> ans = new ArrayList<>();
        backtrack(0, candidates, target, ans, new ArrayList<>());
        return ans;
    }
    
    public void backtrack(int i, int[] arr, int target,  List<List<Integer>> ans, List<Integer> sub)
    {
        if (i == arr.length) 
        {
            if (target == 0) 
            {
                ans.add(new ArrayList < > (sub));
            }
            return;
        }

        if (arr[i] <= target) 
        {
            sub.add(arr[i]);
            backtrack(i, arr, target - arr[i], ans, sub);
            sub.remove(sub.size() - 1);
        }
        backtrack(i + 1, arr, target, ans, sub);
    }
}