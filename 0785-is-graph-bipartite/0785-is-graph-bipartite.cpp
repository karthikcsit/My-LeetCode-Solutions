class Solution {
public:
     bool bfs(int ini,int v,int color[], vector<vector<int>>& graph)
    {
        queue<int>q;
        q.push(ini);
       
        
        color[0]=0;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto it:graph[node])
            {
                if(color[it]==-1)
                {
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[it]==color[node])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int v=graph.size();
        
      
        
       
        int color[v];
        for(int i=0;i<v;i++)
            color[i]=-1;
        
         for(int i=0;i<v;i++)
        {
            if(color[i]==-1)
            {
                if( !bfs(i,v,color,graph))
                    return false;
            }
        }
        
       
        return true;
    }
};