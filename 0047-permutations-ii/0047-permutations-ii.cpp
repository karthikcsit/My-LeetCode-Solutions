class Solution {
public:
   
  void   permute(int ind , vector<vector<int>>&ans,vector<int>& nums)
    {
       
         if(ind==nums.size())
         {
             ans.push_back(nums);
             return;
         }
        unordered_set<int>s;
        for(int i=ind;i<nums.size();i++)
        {
            if(s.find(nums[i])!=s.end())
                continue;
            s.insert(nums[i]);
           
           
            swap(nums[ind],nums[i]);
            permute(ind+1,ans,nums);
            swap(nums[i],nums[ind]);
            
        }
      
   }
     vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        permute(0,ans,nums);
        return ans;
    }
};