class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>front(2,0),curr(2,0);
        front[0]=front[1]=0;
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int buy=0;buy<=1;buy++)
            {
              int profit=0;
                if(buy)
                {
                    profit=max(-prices[ind]+front[0] , front[1]);
                }
                else
                {
                     profit=max(prices[ind]+front[1] , front[0]);
                }
                          curr[buy]=profit;       

            }
            front=curr;
        }
        return front[1];
    }
};