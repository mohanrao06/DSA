class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int V=routes.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<routes.size();i++){
            for(auto it:routes[i]){
                adj[it].push_back(i);
            }
        }
        if(source==target)return 0;
        set<int> vistedstops;
        queue<int> q;
        vector<int> vistedBus(V,0);
        q.push(source);
        int buses=0;
        vistedstops.insert(source);
        while(!q.empty()){
            int size=q.size();
            buses++;
            while(size--){
                int stop=q.front();
                q.pop();
                for(auto bus: adj[stop]){
                    if(!vistedBus[bus]){
                        vistedBus[bus]=1;
                        for(auto stops:routes[bus]){
                            if(!vistedstops.count(stops)){
                                if(target==stops)return buses;
                                vistedstops.insert(stops);
                                q.push(stops);
                            }
                        }
                    }
                }
            }

        }
        return -1;

    }
};