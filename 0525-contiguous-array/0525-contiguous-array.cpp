class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxlen=0;
        int sum=0;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i]==0?-1:1;
            if(sum==0)
            {
                if(maxlen<i+1)
                    maxlen=i+1;
            }
            else if(mp.find(sum)!=mp.end())
            {
                if(maxlen<i-mp[sum])
                    maxlen=i-mp[sum];
                    
            }
            else
                mp[sum]=i;
        }
        return maxlen;
    }
};