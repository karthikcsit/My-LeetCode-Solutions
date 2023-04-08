class Solution {
public:
     int subset(vector<int>& nums,int sum)
    {
          int n=nums.size();
        int t[n+1][sum+1];
        for(int i=0;i<n+1;i++)
        {
         for(int j=0;j<sum+1;j++)
         {
            if(i==0)
                t[i][j]=0;
            if(j==0)
                 t[i][j]=1;
         }
        }
        for(int i=1;i<n+1;i++)
        {
         for(int j=0;j<sum+1;j++)
         {
          if(nums[i-1]<=j)
             t[i][j]=  t[i-1][j] + t[i-1][j-nums[i-1]];
        
          else 
             t[i][j]=t[i-1][j];
         }
        }
        return t[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
       // int sum=(target+sum1)/2;
         if(sum<abs(target) || (target+sum)%2!=0)
        {
            return 0;
        }
         int s1=(target+sum)/2;
        return subset(nums,abs(s1));
    }
    
    
    
    
    
    
  
};