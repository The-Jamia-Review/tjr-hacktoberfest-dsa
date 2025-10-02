class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());

        int i,j,k,n=nums.size();
        for(i=0;i<n;i++)
        {
            if(i!=0&&nums[i]==nums[i-1])
            continue;
            j=i+1;
            k=n-1;
            while(j<k)
            {
            if(nums[i]+nums[j]+nums[k]>0)
            k--;
             else if(nums[i]+nums[j]+nums[k]<0)
            j++;
             else
             {
            vector<int> v={nums[i],nums[j],nums[k]};
            ans.push_back(v);
            
            k--;
            j++;
            while(j<k&&nums[j]==nums[j-1])
            j++;
             while(j<k&&nums[k]==nums[k+1])
            k--;
            } 
            
            }

        }
        return ans;
    }
};
