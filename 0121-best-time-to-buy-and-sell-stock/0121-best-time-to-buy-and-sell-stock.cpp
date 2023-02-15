class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int mini=INT_MAX;
        int res=0;
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
           mini=min(mini,prices[i]);
            res=max(res,prices[i]-mini);
        }
        return res;
       
    }
};