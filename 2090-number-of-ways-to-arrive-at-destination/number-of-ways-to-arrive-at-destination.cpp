class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int wt=roads[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        vector<int> ways(n,0);
        vector<long long> dist(n,LLONG_MAX);
        dist[0]=0;
        pq.push({0,0});
        ways[0]=1;
        const int MOD = 1e9 + 7;
        while(!pq.empty()){
            long long dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int v=it.first;
                int wt=it.second;
                long long newdis=wt+dis;
                if(newdis<dist[v]){
                    dist[v]=newdis;
                    pq.push({newdis,v});
                    ways[v]=ways[node];
                }
                else if(newdis==dist[v]){
                    ways[v]=(ways[v]+ways[node])%MOD;
                }
            }
        }
        return ways[n-1];
    }
};