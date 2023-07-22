class Solution {
public:
    int fun(vector<int>& nums, int k)
    {
        int i=0,j=0;
        int n=nums.size();
        int odd=0,size=0;
        while(j<n)
        {
            if(nums[j]%2)
                odd++;
           
            
            
            while(odd>k)
           {
                  if(nums[i]%2)
                     odd--;
                  i++;
           }
            size+=(j-i+1);
            j++;
            
                
         }
        return size;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return fun(nums,k)-fun(nums,k-1);
    }
};