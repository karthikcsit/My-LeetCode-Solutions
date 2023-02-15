class Solution {
public:
    /* int merge(vector<int>& nums,int low,int mid,int high){
         int cnt=0;
         int j=mid+1;
         for(int i=low;i<=mid;i++)
         {
            while(j<=high && (long)nums[i]> (long)2*nums[j])
                j++;
            
             cnt+=(j-(mid+1));
            
         }
         vector<int> temp;
         int left=low,right=mid+1;
          while(left<=mid && right<=high)
          {
              if(nums[left]<=nums[right]){
                  temp.push_back(nums[left++]);
              }
              else{
                   temp.push_back(nums[right++]);
              }
          }
         while(left<=mid){
              temp.push_back(nums[left++]);
         }
          while( right<=high){
               temp.push_back(nums[right++]);
          }
          for(int i=low;i<=high;i++){
         nums[i]=temp[i-low];
          }
         return cnt;
                
     }
     int mergesort(vector<int>& nums,int low,int high){
         if(low>=high)    return 0;
         int mid=(low+high)/2;
         int inv=mergesort(nums,low,mid);
         inv+=mergesort(nums,mid-1,high);
         inv+=merge(nums,low,mid,high);
         return inv;
         }
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }*/
    
    
    
    
    
    
     int count;
   
    void checkCount(vector<int>& nums, int start, int mid, int end){

        // two pointers;
        int l = start, r = mid + 1;
        while(l <= mid && r <= end){
            if((long)nums[l] > (long) 2 * nums[r]){
                count += (mid - l + 1);
                r++;
            }else{
                l++;
            }
        }
       // worst case might be nlog(n) 
        sort(nums.begin() + start, nums.begin() + end + 1);
        return;
        
        
        
        //every step sort
    }
    void mergeSort(vector<int>& nums, int start, int end){
        if(start == end) return;
        
        int mid = (start + end)/2;
        mergeSort(nums,start, mid);
        mergeSort(nums,mid+1,end);
        
        checkCount(nums,start,mid,end);
        return;
        
    }
public:
    int reversePairs(vector<int>& nums) {
        if(!nums.size())return 0;
        count = 0;
        mergeSort(nums,0,nums.size()-1);
        return count;
    }
};
