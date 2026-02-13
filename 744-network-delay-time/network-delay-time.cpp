class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});

        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        dist[k]=0;
        int cnt=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            cnt+=dis;
            for(auto it:adj[node]){
                int ele=it.first;
                int wt=it.second;
                if(dis+wt<dist[ele]){
                    dist[ele]=dis+wt;
                    pq.push({dis+wt,ele});
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