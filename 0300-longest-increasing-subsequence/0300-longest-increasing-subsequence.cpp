class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>LIS(n+1,1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] && LIS[i]<=LIS[j] )
                {
                    LIS[i]=max(LIS[i],1+LIS[j]);
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++)
            mx=max(mx,LIS[i]);
        
        return mx;
    }
};