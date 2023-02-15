class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
         vector<vector<int>>ans;
         vector<int>ds;
        subsetnum(0,ds,nums,ans);
        return ans;
        
    }
      void        subsetnum(int ind,vector<int>&ds,vector<int>&arr,vector<vector<int>>&ans)
              {
                  if(ind==arr.size())
                  {
                      ans.push_back(ds);
                      return;
                  }
                  ds.push_back(arr[ind]);
                   subsetnum(ind+1,ds,arr,ans);
                  ds.pop_back();
                   subsetnum(ind+1,ds,arr,ans);
              }
};