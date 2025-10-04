class Solution 
{
    public List<List<Integer>> threeSum(int[] nums) 
    {
        List<List<Integer>> list=new ArrayList<>();
        int n=nums.length;
        Arrays.sort(nums);
        for(int i=0;i<nums.length;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int mid=i+1;
            int end=n-1;
            while(mid<end){
                int sum=nums[i]+nums[mid]+nums[end];
                if(sum==0){
                    List<Integer> l=new ArrayList<>();
                    l.add(nums[i]);
                    l.add(nums[mid]);
                    l.add(nums[end]);
                    list.add(l);
                    mid++;
                    end--;
                    while(mid<end && nums[mid]==nums[mid-1]) mid++;
                    while(mid<end && nums[end]==nums[end+1]) end--;
                }
                else if(sum>0){
                    end--;
                }
                else{
                    mid++;
                }
            }
        }
        return list;
    }
}