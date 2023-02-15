class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++)
            freq[i]=0;
        vector<vector<int>>ans;
        vector<int>ds;
        findpermute(ds,freq,nums,ans);
        return ans;
    }
   void findpermute(vector<int>&ds,int freq[],vector<int>&nums, vector<vector<int>>&ans)
   {
       if(ds.size()==nums.size())
       {
           ans.push_back(ds);
           return;
       }
       for(int i=0;i<nums.size();i++)
       {
           if(!freq[i])
           {
               ds.push_back(nums[i]);
               freq[i]=1;
                findpermute(ds,freq,nums,ans);
               ds.pop_back();
                freq[i]=0;
           }
       }
   }
};