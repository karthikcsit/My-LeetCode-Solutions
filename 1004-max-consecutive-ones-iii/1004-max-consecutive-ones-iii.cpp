class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int ones=0;
        int n=nums.size();
        int zero=0;
        
        int res=0;
        while(j<n)
        {
            
           if(nums[j]) 
               ones++;
            if(!nums[j])
                zero++;
                
           if((j-i+1)-ones<k)
               j++;
           else if((j-i+1)-ones==k)
           {
               res=max(res,j-i+1);
               j++;
           }
           else if((j-i+1)-ones>k)
           {
               while((j-i+1)-ones>k)
               {
                   if(nums[i])
                       ones--;
                   i++;
               }
               j++;
            }
              
            
        }
        if(zero<k)
            return n;
        return res;
    }
};