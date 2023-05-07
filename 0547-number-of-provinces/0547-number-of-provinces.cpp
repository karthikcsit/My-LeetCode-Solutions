class Solution {
public:
    void dfs(int node, vector<int>adjls[] ,  vector<int>&vis)
    {
       
        
        for(auto it:adjls[node])
        {
           if(!vis[it])
           {
               vis[it]=1;
               dfs(it,adjls,vis);
           }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.empty()) return 0;
        int v=isConnected.size();
        vector<int>adjls[v];
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
       vector<int>vis(v+1,0);
        int count=0;
        for(int i=0;i<v;i++)
        {
           if(!vis[i]) 
           {
               count++;
               dfs(i,adjls,vis);
           }
        }
        return count;
        
    }
};