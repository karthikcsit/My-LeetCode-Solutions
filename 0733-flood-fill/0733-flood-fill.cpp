class Solution {
public:
    void dfs( int sr, int sc,vector<vector<int>>& ans,vector<vector<int>>& image,int color, int delrow[],int delcol[],int incolor)
    {
        int n=image.size();
         int m=image[0].size();
        ans[sr][sc]=color;
        for(int i=0;i<4;i++)
        {
            int nrow=sr+delrow[i];
            int ncol=sc+delcol[i];
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&image[nrow][ncol]==incolor &&ans[nrow][ncol]!=color)
            {
                dfs(nrow,ncol,ans,image,color,delrow,delcol,incolor);
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int incolor=image[sr][sc];
        vector<vector<int>> ans= image;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        
        dfs(sr,sc,ans,image,color,delrow,delcol,incolor);
        return ans;
    }
};