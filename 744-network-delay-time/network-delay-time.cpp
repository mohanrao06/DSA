class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int wt=times[i][2];
            adj[u].push_back({v,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int node=pq.top().second;
            int time=pq.top().first;
            pq.pop();
            if (time > dist[node]) continue;
            for(auto it:adj[node]){
                int v=it.first;
                int t=it.second;
                if(time+t<dist[v]){
                    dist[v]=time+t;
                    pq.push({time+t,v});
                }
            }
        }
        int maxi=0;
        for(int i=1;i<dist.size();i++){
            if(dist[i]==INT_MAX)return -1;
            maxi=max(maxi,dist[i]);
        }
        return maxi;
        
        
    }
};