class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
          vector<vector<int>>ans;
        vector<int> ds;
        findcombinationSum(0,target,candidates,ans,ds);
        return ans;
    }
void findcombinationSum(int ind,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds)
    {
        
           
               if(target==0)
               {
                   ans.push_back(ds);
                    return;
               } 
              
          
    for(int i=ind ;i<arr.size();i++)
    {
        if(i>ind && arr[i]==arr[i-1]) continue;    
        if(arr[ind]>target) break;
           
               ds.push_back(arr[i]);
               findcombinationSum(i+1,target-arr[i],arr,ans,ds);
              ds.pop_back();
           
   
           
    }  
}    
    
};