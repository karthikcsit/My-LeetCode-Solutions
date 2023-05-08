class Solution {
public:
    void dfs(int row,int col, vector<vector<int>>&vis,vector<vector<char>>& board,int delr[],int delc[])
    {
        int n=board.size();
        int m=board[0].size();
        vis[row][col]=1;
        for(int i=0;i<4;i++)
        {
            int nr=row+delr[i];
            int nc=col+delc[i];
            if(nr>=0&&nr<n&& nc>=0&&nc<m&&!vis[nr][nc]&&board[nr][nc]=='O')
                dfs(nr,nc,vis,board,delr,delc);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        
        for(int j=0;j<m;j++)
        {
            if(!vis[0][j] && board[0][j]=='O')
                dfs(0,j,vis,board,delr,delc);
            
             if(!vis[n-1][j] && board[n-1][j]=='O')
                dfs(n-1,j,vis,board,delr,delc);
            
        }
        
         for(int i=0;i<n;i++)
        {
            if(!vis[i][0] && board[i][0]=='O')
                dfs(i,0,vis,board,delr,delc);
            
             if(!vis[i][m-1] && board[i][m-1]=='O')
                dfs(i,m-1,vis,board,delr,delc);
            
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && board[i][j]=='O')
                    board[i][j]='X';
            }
        }
        
        
    }
};