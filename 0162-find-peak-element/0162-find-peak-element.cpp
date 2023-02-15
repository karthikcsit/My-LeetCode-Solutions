class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int l=0,n=nums.size(),h=n-1;
        if(n==1)
            return 0;
        while(l<=h)
        {
            int mid=(l+h)/2;
           
            if((mid==0||nums[mid]>=nums[mid-1]) &&(mid==n-1 ||nums[mid]>=nums[mid+1]))
                return mid;
            else if(mid>0&&nums[mid-1]>=nums[mid])
                h=mid-1;
             else 
                l=mid+1;
              if(mid==0 && n==2)
            {
                if(nums[mid]>nums[mid+1])
                    return mid; 
                else 
                    return mid+1;
            }
           
            
           
        }
        return -1;
    }
};