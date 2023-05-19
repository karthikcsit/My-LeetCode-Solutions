class Solution {
public:
    /*int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
             adj[it[1]].push_back({it[0],it[2]});
        }
            
            
        priority_queue<pair<long long,long long>,
        vector<pair<long long,long long>>,
        greater<pair<long long,long long>>>pq;
        vector<long long>dist(n,1e9),ways(n,0);
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
    }*/
     int countPaths(int n, vector<vector<int>>& r) {
        int mod=1e9+7;
        vector<vector<pair<long long,long long>>>adj(n);
        for(int i=0;i<r.size();i++){
            adj[r[i][0]].push_back({r[i][1],r[i][2]});
            adj[r[i][1]].push_back({r[i][0],r[i][2]});
        }
        vector<long long>c(n,0);
        c[0]=1;
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        vector<long long int>dist(n,1e15);
        dist[0]=0;
        pq.push({0,0});
        while(pq.empty()==false){
            auto x=pq.top();
            long long dis=x.first;
            long long node=x.second;
            pq.pop();
            for(auto it:adj[node]){
                long long wt=it.second;
                long long y=it.first; 
                if(wt+dis<dist[y]){
                    dist[y]=(wt+dis);
                    pq.push({dist[y],y});
                    c[y]=c[node];
                }
                else if((wt+dis)==dist[y]){
                    c[y]=(c[y]+c[node])%mod;
                }
                
            }
        }
        return c[n-1];
    }
};