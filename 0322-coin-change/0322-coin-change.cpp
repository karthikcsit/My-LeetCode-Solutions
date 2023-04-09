class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int N=coins.size();
         int t[N+1][amount+1];
        for(int i=0;i<N+1;i++)
        {
            for(int j=0;j<amount+1;j++)
            {
                if(j==0)
                    t[i][j]=0;
                if(i==0)
                    t[i][j]=INT_MAX-1;
                if(i==1)
                {
                    if(j% coins[i-1] ==0)
                        t[i][j]=j/coins[i-1];
                    else
                         t[i][j]=INT_MAX-1;
                }
            }
        }
         for(int i=1;i<N+1;i++)
         {
            for(int j=1;j<amount+1;j++)
            {
                if(coins[i-1]<=j)
                    t[i][j]=  min( t[i][j-coins[i-1]] +1, t[i-1][j]);
                
                else
                    t[i][j]=t[i-1][j];
            }
         }
        int res= t[N][amount];
        if(res==INT_MAX-1)
            return -1;
        else
            return res;
                
    }
};