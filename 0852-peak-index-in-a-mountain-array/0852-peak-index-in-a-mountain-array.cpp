class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
         int l=0,n=arr.size(),h=n-1;
        if(n==1)
            return 0;
        while(l<=h)
        {
            int mid=(l+h)/2;
           
            if((mid==0||arr[mid]>=arr[mid-1]) &&(mid==n-1 ||arr[mid]>=arr[mid+1]))
                return mid;
            else if(mid>0&&arr[mid-1]>=arr[mid])
                h=mid-1;
             else 
                l=mid+1;
              if(mid==0 && n==2)
            {
                if(arr[mid]>arr[mid+1])
                    return mid; 
                else 
                    return mid+1;
            }
           
            
           
        }
        return -1;
        
    }
};