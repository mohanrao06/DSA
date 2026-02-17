class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V=points.size();
        vector<vector<pair<int,int>>> adj(V);
        for(int i=0;i<V;i++){
                int x1=points[i][0];
                int y1=points[i][1];
            for(int j=0;j<V;j++){
                int x2=points[j][0];
                int y2=points[j][1];
                int dist=abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({j,dist});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> vis(V,0);
        int ans=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            if(vis[node]) continue;
            ans+=wt;
            vis[node]=1;
            for(auto it:adj[node]){
                int ele=it.first;
                int d=it.second;
                if(!vis[ele]){
                    pq.push({d,ele});
                }
            }
        }
        return ans;
    }
};