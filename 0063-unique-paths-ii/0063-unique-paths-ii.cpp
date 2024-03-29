class Solution {
public:
     int uniquePaths(int m, int n,vector<vector<int>>& obstacleGrid) {
        vector<int>prev(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int>temp(n,0);
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j]==1 ) temp[j]=0;
               else if(i==0 && j==0)
                    temp[j]=1;
                else
                {
                    int up=0;
                    int left=0;
                    if(i>0) up=prev[j];
                    if(j>0) left=temp[j-1];
                    temp[j]=up+left;
                    
                }
            }
            prev=temp;
        }
        return prev[n-1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        return uniquePaths(m,n,obstacleGrid);
    }
};