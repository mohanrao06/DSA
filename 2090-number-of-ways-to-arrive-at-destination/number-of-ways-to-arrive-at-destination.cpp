class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int time=roads[i][2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        ways[0]=1;
        dist[0]=0;
        int MOD = 1e9 + 7;
        while(!pq.empty()){
            auto node=pq.top();
            pq.pop();
            long long d=node.first;
            int ele=node.second;
            for(auto it:adj[ele]){
                int nd=it.first;
                long long tm=it.second;
                long long newd=d+tm;
                if(newd<dist[nd]){
                    dist[nd]=d+tm;
                    ways[nd]=ways[ele];
                    pq.push({d+tm,nd});
                }else if(d+tm==dist[nd]){
                    ways[nd]=(ways[nd]+ways[ele])%MOD;
                }
            }
        }
        return ways[n-1];
        

    }
};