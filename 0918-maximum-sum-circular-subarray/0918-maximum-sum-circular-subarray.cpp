class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int maxnormal=normalsub( nums);
        if(maxnormal<0)  return maxnormal;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            nums[i]=-nums[i];
        }
        int circular=sum+normalsub( nums);
        
        return max(maxnormal,circular);
        
        
    }
    int normalsub(vector<int>& nums)
    {
        int res=nums[0],maxend=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            maxend=max(maxend+nums[i],nums[i]);
            res=max(res,maxend);
        }
        return res;
    }
        
    
};