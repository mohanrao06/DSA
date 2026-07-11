class Solution {
public:
    void dfs(vector<int>adj[],int ind,vector<int> &vis,int &node,int &ed){
        vis[ind]=1;
        node++;
        ed+=adj[ind].size();
        for(auto it:adj[ind]){
            if(!vis[it]){
                dfs(adj,it,vis,node,ed);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int ed=0,node=0;
                dfs(adj,i,vis,node,ed);
                if(ed==node*(node-1))cnt++;
            }
        }
        return cnt;

    }
};