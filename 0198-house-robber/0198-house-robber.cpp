class Solution {
public:
    int fib(int n,vector<int>& dp,vector<int>& nums)
    {
        if(n==0)return nums[n];
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        int pick=nums[n]+fib(n-2,dp,nums);
        int notpick=fib(n-1,dp,nums);
        
        return dp[n]=max(pick,notpick);
        
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
            return fib(n-1,dp,nums);
    }
};