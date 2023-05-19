class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
             adj[it[1]].push_back({it[0],it[2]});
        }
            
            
        priority_queue<pair<long long,long long>,
        vector<pair<long long,long long>>,
        greater<pair<long long,long long>>>pq;
        vector<long long>dist(n,1e15),ways(n,0);
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        int mod=(1e9+7);
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            long long dis=it.first;
            int node=it.second;
            
          
            for(auto it:adj[node])
            {
                int adjnd=it.first;
                long long edw=it.second;
                
                if(dis+edw<dist[adjnd])
                {
                    dist[adjnd]=dis+edw;
                    pq.push({dis+edw,adjnd});
                    ways[adjnd]=ways[node];
                }
                else if(dis+edw==dist[adjnd])
                {
                     ways[adjnd]=(ways[adjnd]+ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
    
};