class Solution {
public:
    void dfs(int u,vector<vector<int>>&gr,vector<bool> &vis,int &node,int &sum){
        vis[u]=true;
        node++;
        sum+=gr[u].size();
        for(int it:gr[u]){
            if(!vis[it]){
                dfs(it,gr,vis,node,sum);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto it: edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<bool> vis(n);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int node=0,sum=0;
                dfs(i,graph,vis,node,sum);
                if(sum==node*(node-1))ans++;
            }
        }
        return ans;


    }
};