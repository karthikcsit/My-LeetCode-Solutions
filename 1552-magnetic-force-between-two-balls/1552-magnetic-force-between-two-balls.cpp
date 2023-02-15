class Solution {
public:
     bool canpossible(vector<int>& arr,int n,int m,int mid)
        {
            int cow=arr[0],count=1;
            for(int i=1;i<n;i++)
            {
                if(arr[i]-cow >= mid)
                {
                    count++;
                    cow=arr[i];
                }
                if(count==m)  return true;
                
            }
            return false;
        }
    int maxDistance(vector<int>& arr, int m) {
        
        sort(arr.begin(),arr.end());
        int n=arr.size(), res=-1;
        int lo=1,high=arr[n-1]-arr[0];
        
        while(lo<=high)
        {
            int mid=(lo+high)/2;
            if(canpossible(arr,n,m,mid))
            {
                res=mid;
                lo=mid+1;
            }
            else
                high=mid-1;
        }
       return res;
    }
};


    
