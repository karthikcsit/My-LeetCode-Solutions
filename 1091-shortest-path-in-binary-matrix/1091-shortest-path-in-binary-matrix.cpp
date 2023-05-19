class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        if(grid.size()==1&&grid[0][0]==0) return 1;
        if(grid[0][0]==1) return -1;
        dist[0][0]=1;
        q.push({1,{0,0}});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            
            for(int nr=-1;nr<=1;nr++)
            {
                for(int nc=-1;nc<=1;nc++)
                {
                    int newr=r+nr;
                    int newc=c+nc;
                    if(newr>=0&&newr<n&&newc>=0&&newc<m&&grid[newr]                                                [newc]==0&&dis+1<dist[newr][newc])
                    {
                        dist[newr][newc]=dis+1;
                        if(newr==n-1 && newc==m-1) return dis+1;
                        q.push({dist[newr][newc],{newr,newc}});
                    }
                }
            }
        }
        return -1;
    }
};