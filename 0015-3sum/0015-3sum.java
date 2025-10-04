import java.util.*;

class Solution 
{
    public List<List<Integer>> threeSum(int[] nums) 
    {
        Arrays.sort(nums);
        Set<List<Integer>> uniq = new HashSet<>();
        for(int i = 0; i < nums.length; i++)
        {
            //remove duplicates:
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            int left = i+1;
            int right = nums.length-1;
            while(left<right)
            {
                if(nums[i]+nums[left]+nums[right]==0)
                {
                    uniq.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    left++; right--;
                    //skip the duplicates:
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
                else if(nums[i]+nums[left]+nums[right]<0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        
        return new ArrayList<>(uniq);
    }
}