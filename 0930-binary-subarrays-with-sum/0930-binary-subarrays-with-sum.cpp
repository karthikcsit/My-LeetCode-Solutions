class Solution {
public:
    int fun(vector<int>& nums, int goal)
    {
        if(goal<0)return 0;
      int i=0,j=0;
      int n=nums.size();
      int sum=0;
        int size=0;
      while(j<n)
      {
          sum+=nums[j];
          while(sum>goal)
          {
              sum-=nums[i];
              i++;
          }
          size+=(j-i+1);
          j++;
      }
        return size;
    }
   
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return fun(nums,goal)- fun(nums,goal-1);
    }
};