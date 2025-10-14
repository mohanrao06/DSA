class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int price=flights[i][2];
            adj[u].push_back({v,price});
        }
        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,src}});
        dist[src]=0;
        while(!pq.empty()){
            int stop=pq.top().first;
            int node=pq.top().second.second;
            int price=pq.top().second.first;
            pq.pop();
            if(stop>k)continue;
            
            for(auto it: adj[node]){
                int nd=it.first;
                int pr=it.second;
                if(dist[nd]>price+pr && stop<=k){
                    dist[nd]=price+pr;
                    pq.push({stop+1,{pr+price,nd}});
                }


            }
        }
        if(dist[dst]!=INT_MAX)return dist[dst];
        return -1;
        
        
    }
};