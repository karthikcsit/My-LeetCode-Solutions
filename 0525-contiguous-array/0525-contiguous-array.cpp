class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       int maxlen=0;
        int endind=-1;
        int sum=0;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i]==0?-1:1;
            if(sum==0)
            {
                if(maxlen<i+1)
                {
                    maxlen=i+1;
                    endind=i;
                }
            }
            else if(mp.find(sum)!=mp.end())
            {
                if(maxlen<i-mp[sum])
                {
                    maxlen=i-mp[sum];
                    endind=i;
                }
                    
            }
            else
                mp[sum]=i;
        }
        
        int startind=endind-maxlen+1;
        cout<<startind<<" "<<endind<<endl;
        for(int i=startind;i<=endind;i++)
            cout<<nums[i]<<" ";
        
    return maxlen;
    }
};